#include <MyFramework/theme/ThemeScheduler.h>
#include <ctime>

namespace MyFramework {

static int currentMinutes() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    return now->tm_hour * 60 + now->tm_min;
}

void ThemeScheduler::addTimeRange(int startMin, int endMin, const Theme& theme) {
    m_ranges.push_back({startMin, endMin, theme});
}

Theme ThemeScheduler::currentTheme() const {
    int now = currentMinutes();

    for (const auto& r : m_ranges) {
        if (now >= r.start && now <= r.end)
            return r.theme;
    }

    return m_fallback;
}

bool ThemeScheduler::hasOverlap() const {
    for (size_t i = 0; i < m_ranges.size(); ++i) {
        for (size_t j = i + 1; j < m_ranges.size(); ++j) {
            if (!(m_ranges[i].end < m_ranges[j].start ||
                  m_ranges[j].end < m_ranges[i].start)) {
                return true;
            }
        }
    }
    return false;
}

void ThemeScheduler::setFallback(const Theme& theme) {
    m_fallback = theme;
}

} // namespace MyFramework
