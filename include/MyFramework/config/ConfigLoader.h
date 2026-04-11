#pragma once

#include <string>

namespace GQFusion {

class Config;

/**
 * @brief Handles config loading with fallback chain support.
 *
 * Load order:
 *  1. App-specific config (./app.config)
 *  2. User default config (~/.config/gqfusion/default.config)
 *  3. Generated default config (auto-created)
 */
class ConfigLoader {
public:
    /**
     * @brief Load config for a given application name.
     * @param appName Name of the app (used to resolve config file)
     */
    static Config load(const std::string& appName);

private:
    // ------------------------------------------------------------
    // Path Resolution
    // ------------------------------------------------------------

    static std::string getAppConfigPath(const std::string& appName);
    static std::string getDefaultConfigPath();

    // ------------------------------------------------------------
    // Defaults / Fallbacks
    // ------------------------------------------------------------

    static Config createDefaultConfig();

    // ------------------------------------------------------------
    // File Creation
    // ------------------------------------------------------------

    /**
     * @brief Writes a default config file if none exists.
     */
    static void writeDefaultConfigFile(const std::string& path,
                                       const Config& config);
};

} // namespace GQFusion
