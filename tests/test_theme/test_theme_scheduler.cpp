#include <MyFramework/theme/ThemeScheduler.h>
#include <iostream>

using namespace MyFramework;

void run_theme_scheduler_tests() {
    std::cout << "[TEST] Theme Scheduler\n";

    ThemeScheduler scheduler;

    Theme morning;
    morning.opacity = 0.3f;

    Theme evening;
    evening.opacity = 0.9f;

    // Full day coverage to ensure deterministic result
    scheduler.addTimeRange(0, 720, morning);    // 00:00 - 12:00
    scheduler.addTimeRange(721, 1440, evening); // 12:01 - 24:00

    Theme current = scheduler.currentTheme();

    if (current.opacity == 0.3f || current.opacity == 0.9f)
        std::cout << "  ✔ Scheduler returns valid theme\n";
    else
        std::cout << "  ✖ Scheduler failed\n";
}
