#include "ConfigLoader.h"
#include "ConfigParser.h"

#include <filesystem>

Config ConfigLoader::load(const std::string& appName) {
    std::string appConfig = appName + ".config";

    if (std::filesystem::exists(appConfig)) {
        return ConfigParser::parseFile(appConfig);
    }

    std::string defaultPath = getDefaultPath();

    if (std::filesystem::exists(defaultPath)) {
        return ConfigParser::parseFile(defaultPath);
    }

    // fallback hardcoded defaults
    return Config();
}

std::string ConfigLoader::getDefaultPath() {
#ifdef _WIN32
    return "C:/Users/Public/MyFramework/default.config";
#else
    return std::string(getenv("HOME")) + "/.config/myframework/default.config";
#endif
}
