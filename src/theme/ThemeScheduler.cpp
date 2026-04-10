#include "MyFramework/theme/ThemeScheduler.h"
#include "MyFramework/theme/ThemeBlender.h"
#include <stdexcept>

namespace MyFramework {

int ThemeScheduler::timeToMinutes(const std::string& time) {
    int hours = std::stoi(time.substr(0, 2));
    int mins  = std::stoi(time.substr(3, 2));
    return hours * 60 + mins;
}

Theme ThemeScheduler::resolveTheme(
    const std::vector<ThemeEntry>& themes,
    const Theme& fallback,
    const std::string& currentTime
) {
    int now = timeToMinutes(currentTime);

    std::vector<const ThemeEntry*> active;

    for (const auto& t : themes) {
        int start = timeToMinutes(t.start);
        int end   = timeToMinutes(t.end);

        if (start <= now && now < end) {
            active.push_back(&t);
        }
    }

    // No active themes → fallback
    if (active.empty()) {
        return fallback;
    }

    // Only one active theme
    if (active.size() == 1) {
        return active[0]->theme;
    }

    // Two or more → blend first two (can extend later)
    const ThemeEntry* a = active[0];
    const ThemeEntry* b = active[1];

    int startA = timeToMinutes(a->start);
    int endA   = timeToMinutes(a->end);

    int overlapStart = std::max(startA, timeToMinutes(b->start));
    int overlapEnd   = std::min(endA,   timeToMinutes(b->end));

    if (overlapEnd <= overlapStart) {
        return a->theme; // fallback to first if no real overlap
    }

    float t = float(now - overlapStart) / float(overlapEnd - overlapStart);

    return ThemeBlender::blend(a->theme, b->theme, t);
}

}
