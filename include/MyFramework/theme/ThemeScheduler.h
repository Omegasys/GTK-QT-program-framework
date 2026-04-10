#pragma once
#include "Theme.h"
#include <vector>
#include <string>

namespace MyFramework {

struct ThemeEntry {
    std::string start; // "HH:MM"
    std::string end;   // "HH:MM"
    Theme theme;
};

class ThemeScheduler {
public:
    static Theme resolveTheme(
        const std::vector<ThemeEntry>& themes,
        const Theme& fallback,
        const std::string& currentTime
    );

private:
    static int timeToMinutes(const std::string& time);
};

}
