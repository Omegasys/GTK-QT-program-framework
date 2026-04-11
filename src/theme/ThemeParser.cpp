#include <MyFramework/theme/ThemeParser.h>
#include <sstream>

namespace MyFramework {

static Color parseHex(const std::string& hex) {
    unsigned int r, g, b;
    sscanf(hex.c_str(), "#%02x%02x%02x", &r, &g, &b);
    return Color(r / 255.0f, g / 255.0f, b / 255.0f, 1.0f);
}

Theme ThemeParser::parseThemeString(const std::string& str) {
    Theme theme;

    std::stringstream ss(str);
    std::string segment;
    std::vector<std::string> parts;

    while (std::getline(ss, segment, '-')) {
        parts.push_back(segment);
    }

    if (parts.size() < 10)
        return theme;

    theme.leftColor   = parseHex(parts[0]);
    theme.centerColor = parseHex(parts[1]);
    theme.rightColor  = parseHex(parts[2]);

    theme.opacity        = std::stof(parts[3]) / 255.0f;
    theme.blur           = std::stof(parts[4]);
    theme.cornerRadius   = std::stof(parts[5]);
    theme.shadowDistance = std::stof(parts[6]);

    theme.shadowLeft   = parseHex(parts[7]);
    theme.shadowCenter = parseHex(parts[8]);
    theme.shadowRight  = parseHex(parts[9]);

    return theme;
}

} // namespace MyFramework
