#include "MyFramework/config/ConfigParser.h"
#include <fstream>
#include <sstream>
#include <regex>
#include <iostream>

namespace MyFramework {

static bool isValidHex(const std::string& hex) {
    return std::regex_match(hex, std::regex("^#[0-9A-Fa-f]{6}$"));
}

static std::vector<std::string> split(const std::string& str, char delim) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string item;

    while (std::getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

redshift.enabled=true
redshift.night_temp=3500
redshift.day_temp=6500
redshift.start=20
redshift.end=6

Theme parseThemeString(const std::string& data) {
    Theme theme{};

    auto parts = split(data, '-');
    if (parts.size() != 10) {
        throw std::runtime_error("Invalid theme format");
    }

    // Validate hex colors
    for (int i = 0; i < 3; ++i) {
        if (!isValidHex(parts[i])) throw std::runtime_error("Invalid color");
    }
    for (int i = 7; i < 10; ++i) {
        if (!isValidHex(parts[i])) throw std::runtime_error("Invalid shadow color");
    }

    theme.windowLeft   = Color::fromHex(parts[0]);
    theme.windowCenter = Color::fromHex(parts[1]);
    theme.windowRight  = Color::fromHex(parts[2]);

    theme.opacity       = std::stoi(parts[3]);
    theme.blur          = std::stoi(parts[4]);
    theme.cornerRadius  = std::stoi(parts[5]);
    theme.shadowDistance= std::stoi(parts[6]);

    theme.shadowLeft   = Color::fromHex(parts[7]);
    theme.shadowCenter = Color::fromHex(parts[8]);
    theme.shadowRight  = Color::fromHex(parts[9]);

    return theme;
}

Config ConfigParser::parse(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open config file");
    }

    Config config;
    std::string line;
    std::string currentApp;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        // Section header
        if (line[0] == '[') {
            size_t start = line.find(':');
            size_t end = line.find(']');
            currentApp = line.substr(start + 1, end - start - 1);
            config.apps[currentApp] = AppConfig{};
            continue;
        }

        auto pos = line.find('=');
        if (pos == std::string::npos) continue;

        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        if (key == "fallback_theme") {
            config.apps[currentApp].fallback =
                parseThemeString(value);
        }
        else if (key.find("theme_") == 0) {
            auto parts = split(value, ':');
            if (parts.size() != 2) continue;

            auto timeRange = split(parts[0], '-');
            if (timeRange.size() != 2) continue;

            ThemeEntry entry;
            entry.start = timeRange[0];
            entry.end   = timeRange[1];
            entry.theme = parseThemeString(parts[1]);

            config.apps[currentApp].themes.push_back(entry);
        }
    }

    return config;
}

} // namespace MyFramework
