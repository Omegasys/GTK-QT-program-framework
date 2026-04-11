#include "ConfigLoader.h"
#include "ConfigParser.h"

#include <filesystem>
#include <cstdlib>
#include <fstream>

using namespace std;

namespace fs = std::filesystem;

// ------------------------------------------------------------
// Public API
// ------------------------------------------------------------

Config ConfigLoader::load(const std::string& appName) {
    std::string appPath = getAppConfigPath(appName);

    // 1️⃣ App-specific config
    if (fs::exists(appPath)) {
        return ConfigParser::parseFile(appPath);
    }

    // 2️⃣ Global default config
    std::string defaultPath = getDefaultConfigPath();

    if (fs::exists(defaultPath)) {
        return ConfigParser::parseFile(defaultPath);
    }

    // 3️⃣ Create default config file if missing
    Config cfg = createDefaultConfig();
    writeDefaultConfigFile(defaultPath, cfg);

    return cfg;
}

// ------------------------------------------------------------
// Path Resolution
// ------------------------------------------------------------

std::string ConfigLoader::getAppConfigPath(const std::string& appName) {
    return appName + ".config";
}

std::string ConfigLoader::getDefaultConfigPath() {
#ifdef _WIN32
    const char* appData = getenv("APPDATA");

    std::string dir;
    if (appData) {
        dir = std::string(appData) + "\\MyFramework";
    } else {
        dir = "C:\\MyFramework";
    }

    fs::create_directories(dir);
    return dir + "\\default.config";

#else
    // 🔥 XDG support
    const char* xdg = getenv("XDG_CONFIG_HOME");

    std::string dir;

    if (xdg) {
        dir = std::string(xdg) + "/myframework";
    } else {
        const char* home = getenv("HOME");
        if (home) {
            dir = std::string(home) + "/.config/myframework";
        } else {
            dir = "./.config/myframework";
        }
    }

    fs::create_directories(dir);
    return dir + "/default.config";
#endif
}

// ------------------------------------------------------------
// Default Config Creation
// ------------------------------------------------------------

Config ConfigLoader::createDefaultConfig() {
    Config cfg;

    // Window defaults
    cfg.set("window.width", "1280");
    cfg.set("window.height", "720");
    cfg.set("window.title", "MyFramework App");

    // Theme defaults
    cfg.set("theme", "default");

    // Redshift defaults (future system)
    cfg.set("redshift.enabled", "false");
    cfg.set("redshift.day_temp", "6500");
    cfg.set("redshift.night_temp", "3500");
    cfg.set("redshift.start", "20");
    cfg.set("redshift.end", "6");

    return cfg;
}

// ------------------------------------------------------------
// File Writing (Auto-generate default config)
// ------------------------------------------------------------

void ConfigLoader::writeDefaultConfigFile(const std::string& path, const Config& cfg) {
    // Prevent overwrite if file already exists
    if (fs::exists(path))
        return;

    std::ofstream file(path);

    if (!file.is_open())
        return;

    // Basic config serialization
    file << "# MyFramework Default Config\n";
    file << "# Auto-generated\n\n";

    file << "window.width=1280\n";
    file << "window.height=720\n";
    file << "window.title=MyFramework App\n\n";

    file << "theme=default\n\n";

    file << "# Redshift\n";
    file << "redshift.enabled=false\n";
    file << "redshift.day_temp=6500\n";
    file << "redshift.night_temp=3500\n";
    file << "redshift.start=20\n";
    file << "redshift.end=6\n";

    file.close();
}
