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

    /**
     * @brief Converts color to hex string.
     */
    std::string toHex() const;
};

/**
 * @brief Represents a time value (24-hour format).
 */
struct Time {
    int hour;
    int minute;

    Time() : hour(0), minute(0) {}
    Time(int h, int m) : hour(h), minute(m) {}

    /**
     * @brief Parses time from string "HH:MM".
     */
    static Time fromString(const std::string& str);

    /**
     * @brief Converts time to string.
     */
    std::string toString() const;

    /**
     * @brief Converts time to minutes (for comparisons).
     */
    int toMinutes() const;

    /**
     * @brief Comparison operators.
     */
    bool operator<(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator<=(const Time& other) const;
    bool operator>=(const Time& other) const;
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
    Time startTime;
    Time endTime;

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

} // namespace MyFramework
