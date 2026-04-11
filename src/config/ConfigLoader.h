#pragma once

#include <string>
#include <MyFramework/config/Config.h>

class ConfigLoader {
public:
    // Load config with fallback chain
    static Config load(const std::string& appName);

private:
    static std::string getAppConfigPath(const std::string& appName);
    static std::string getDefaultConfigPath();
    static Config createDefaultConfig();
};
