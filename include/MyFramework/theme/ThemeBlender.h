#pragma once
#include "Theme.h"

namespace MyFramework {

class ThemeBlender {
public:
    static Theme blend(const Theme& a, const Theme& b, float t);
};

}
