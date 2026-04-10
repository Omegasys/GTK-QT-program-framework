#include "MyFramework/theme/Color.h"
#include <stdexcept>

namespace MyFramework {

Color::Color(int r, int g, int b) : r(r), g(g), b(b) {}

static int hexToInt(const std::string& hex) {
    return std::stoi(hex, nullptr, 16);
}

Color Color::fromHex(const std::string& hex) {
    if (hex.size() != 7 || hex[0] != '#') {
        throw std::runtime_error("Invalid hex color format");
    }

    int r = hexToInt(hex.substr(1, 2));
    int g = hexToInt(hex.substr(3, 2));
    int b = hexToInt(hex.substr(5, 2));

    return Color(r, g, b);
}

}
