#pragma once
#include "ConfigTypes.h"

namespace MyFramework {

class ConfigParser {
public:
    static Config parse(const std::string& path);
};

Theme parseThemeString(const std::string& data);

}
