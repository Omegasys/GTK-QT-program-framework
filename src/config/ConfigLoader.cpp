#include "ConfigLoader.h"
#include "ConfigParser.h"

#include <filesystem>
#include <cstdlib>

using namespace std;

Config ConfigLoader::load(const std::string& appName) {
    string appPath = getAppConfigPath(appName);

    // 1. App-specific config
    if (filesystem::exists(appPath)) {
        return ConfigParser::parseFile(appPath);
    }

    // 2. Global default config
    string defaultPath = getDefaultConfigPath();
    if (filesystem::exists(defaultPath)) {
        return ConfigParser::parseFile(defaultPath);
    }

    // 3. Hardcoded fallback
    return createDefaultConfig();
}

std::string ConfigLoader::getAppConfigPath(const std::string& appName) {
    return appName + ".config";
}

std::string ConfigLoader::getDefaultConfigPath() {
#ifdef _WIN32
    const char* appData = getenv("APPDATA");
    if (appData) {
        return string(appData) + "\\MyFramework\\default.config";
    }
    return "C:\\MyFramework\\default.config";
#else
    const char* home = getenv("HOME");
    if (home) {
        return string(home) + "/.config/myframework/default.config";
    }
    return "./default.config";
#endif
}

Config ConfigLoader::createDefaultConfig() {
    Config cfg;

    // Basic defaults
    cfg.set("window.width", "1280");
    cfg.set("window.height", "720");
    cfg.set("window.title", "MyFramework App");

    cfg.set("theme", "default");

    // Redshift defaults (future-ready)
    cfg.set("redshift.enabled", "false");
    cfg.set("redshift.day_temp", "6500");
    cfg.set("redshift.night_temp", "3500");

    return cfg;
}
