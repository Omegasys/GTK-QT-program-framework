#pragma once
#include <string>

namespace MyFramework {

struct Color {
    int r{0}, g{0}, b{0};

    Color() = default;
    Color(int r, int g, int b);

    static Color fromHex(const std::string& hex);
};

}
