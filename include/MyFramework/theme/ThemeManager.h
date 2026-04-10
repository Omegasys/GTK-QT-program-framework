#pragma once

#include <string>
#include <memory>
#include <unordered_map>

#include <MyFramework/config/ConfigTypes.h>
#include <MyFramework/config/Config.h>
#include <MyFramework/theme/Theme.h>

namespace MyFramework {

class Window;

/**
 * @brief Central manager for themes and configuration.
 *
 * Handles:
 * - Loading config files
 * - Resolving themes based on time
 * - Live reloading
 * - Applying themes to windows
 */
class ThemeManager {
public:
    /**
     * @brief Constructs the ThemeManager.
     */
    ThemeManager();

    /**
     * @brief Destructor.
     */
    ~ThemeManager();

    // Disable copy
    ThemeManager(const ThemeManager&) = delete;
    ThemeManager& operator=(const ThemeManager&) = delete;

    /**
     * @brief Loads configuration file.
     */
    bool loadConfig(const std::string& path);

    /**
     * @brief Reloads configuration.
     */
    bool reload();

    /**
     * @brief Enables live reload of config file.
     */
    void enableLiveReload(bool enabled);

    /**
     * @brief Returns whether live reload is enabled.
     */
    bool isLiveReloadEnabled() const;

    /**
     * @brief Registers a window with an application name.
     *
     * @param window Window pointer
     * @param appName Name used in config [Application:Name]
     */
    void registerWindow(Window* window, const std::string& appName);

    /**
     * @brief Unregisters a window.
     */
    void unregisterWindow(Window* window);

    /**
     * @brief Updates themes for all registered windows.
     */
    void update();

    /**
     * @brief Forces theme update for a specific window.
     */
    void updateWindow(Window* window);

    /**
     * @brief Gets current theme for an application.
     */
    Theme currentTheme(const std::string& appName) const;

    /**
     * @brief Sets custom time (for testing or overrides).
     */
    void setTimeOverride(const Time& time);

    /**
     * @brief Clears time override (returns to system time).
     */
    void clearTimeOverride();

    /**
     * @brief Returns singleton instance.
     */
    static ThemeManager& instance();

private:
    /**
     * @brief Resolves theme for an app.
     */
    Theme resolveThemeForApp(const std::string& appName) const;

    /**
     * @brief Applies theme to a window.
     */
    void applyTheme(Window* window, const Theme& theme);

    /**
     * @brief Starts file watcher.
     */
    void startWatcher();

    /**
     * @brief Stops file watcher.
     */
    void stopWatcher();

    /**
     * @brief Called when config file changes.
     */
    void onConfigChanged();

private:
    static ThemeManager* s_instance;

    std::string m_configPath;
    Config m_config;

    bool m_liveReloadEnabled;

    std::unique_ptr<ConfigWatcher> m_watcher;

    // Window → app name mapping
    std::unordered_map<Window*, std::string> m_windows;

    // Optional time override
    bool m_useTimeOverride;
    Time m_timeOverride;
};

} // namespace MyFramework
