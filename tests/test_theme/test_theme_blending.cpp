#include <MyFramework/theme/Theme.h>
#include <iostream>

using namespace MyFramework;

void run_theme_blending_tests() {
    std::cout << "[TEST] Theme Blending\n";

    Theme a;
    a.opacity = 0.0f;

    Theme b;
    b.opacity = 1.0f;

    Theme mid = Theme::blend(a, b, 0.5f);

    if (mid.opacity > 0.4f && mid.opacity < 0.6f)
        std::cout << "  ✔ Blend midpoint correct\n";
    else
        std::cout << "  ✖ Blend incorrect\n";
}
