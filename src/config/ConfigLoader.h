#pragma once
#include <string>

class Config;

class ConfigLoader {
public:
    static Config load(const std::string& appName);

private:
    static std::string getDefaultPath();
};
