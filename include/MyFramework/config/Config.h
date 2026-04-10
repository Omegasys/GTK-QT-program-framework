#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace MyFramework {

/**
 * @brief Represents an RGB color.
 */
struct Color {
    int r;
    int g;
    int b;

    Color() : r(0), g(0), b(0) {}
    Color(int r_, int g_, int b_) : r(r_), g(g_), b(b_) {}

    /**
     * @brief Creates a color from hex string (#RRGGBB).
     */
    static Color fromHex(const std::string& hex);
};

/**
 * @brief Represents a full UI theme.
 */
struct Theme {
    // Window gradient
    Color windowLeft;
    Color windowCenter;
    Color windowRight;

    // Visual properties
    int opacity;          // 0–255
    int blur;             // pixels
    int cornerRadius;     // pixels
    int shadowDistance;   // pixels

    // Shadow gradient
    Color shadowLeft;
    Color shadowCenter;
    Color shadowRight;
};

/**
 * @brief Represents a time-based theme entry.
 */
struct ThemeEntry {
    std::string startTime;  // "HH:MM"
    std::string endTime;    // "HH:MM"

    Theme theme;
};

/**
 * @brief Configuration for a single application.
 */
struct AppConfig {
    Theme fallbackTheme;
    std::vector<ThemeEntry> themes;
};

/**
 * @brief Root configuration object.
 */
struct Config {
    std::unordered_map<std::string, AppConfig> applications;
};

/**
 * @brief Parses configuration files.
 */
class ConfigParser {
public:
    /**
     * @brief Parses a config file into a Config object.
     *
     * @param path Path to config file
     * @return Parsed configuration
     */
    static Config parse(const std::string& path);

private:
    static Theme parseThemeString(const std::string& str);
    static ThemeEntry parseThemeEntry(const std::string& line);
};

/**
 * @brief Watches config files for changes (live reload).
 */
class ConfigWatcher {
public:
    /**
     * @brief Creates a watcher for a file path.
     */
    explicit ConfigWatcher(const std::string& path);

    /**
     * @brief Starts watching the file.
     *
     * @param onChange Callback when file changes
     */
    void start(std::function<void()> onChange);

    /**
     * @brief Stops watching.
     */
    void stop();

    /**
     * @brief Returns whether watcher is running.
     */
    bool isRunning() const;

private:
    std::string m_path;
    bool m_running;

    // Implementation detail (polling or platform-specific)
    void watchLoop(std::function<void()> onChange);
};

} // namespace MyFramework
