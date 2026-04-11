#include <MyFramework/theme/ThemeScheduler.h>
#include <iostream>

using namespace MyFramework;

void run_theme_fallback_tests() {
    std::cout << "[TEST] Theme Fallback\n";

    ThemeScheduler scheduler;

    Theme fallback;
    fallback.opacity = 0.75f;

    scheduler.setFallback(fallback);

    Theme current = scheduler.currentTheme();

    if (current.opacity == 0.75f)
        std::cout << "  ✔ Fallback theme applied\n";
    else
        std::cout << "  ✖ Fallback failed\n";
}
