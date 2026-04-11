#include <MyFramework/theme/ThemeManager.h>
#include <MyFramework/theme/ThemeParser.h>
#include <MyFramework/utils/Time.h>

namespace MyFramework {

ThemeManager::ThemeManager()
    : m_currentTheme(),
      m_lastTheme() {}

void ThemeManager::loadFromConfig(const Config& config) {
    m_scheduler = ThemeScheduler();

    for (const auto& [key, value] : config.values()) {
        // Example: "08:00-12:00:#xxxxxx-..."
        auto colon = value.find(':');
        auto dash  = value.find('-');

        if (colon == std::string::npos || dash == std::string::npos)
            continue;

        std::string timeRange = value.substr(0, colon);
        std::string themeStr  = value.substr(colon + 1);

        int startH, startM, endH, endM;
        sscanf(timeRange.c_str(), "%d:%d-%d:%d", &startH, &startM, &endH, &endM);

        int startMin = startH * 60 + startM;
        int endMin   = endH * 60 + endM;

        Theme theme = ThemeParser::parseThemeString(themeStr);
        m_scheduler.addTimeRange(startMin, endMin, theme);
    }
}

void ThemeManager::update() {
    Theme newTheme = m_scheduler.currentTheme();

    if (m_transition.isActive()) {
        m_transition.update((float)Time::deltaTime());
        m_currentTheme = m_transition.current();
        return;
    }

    if (newTheme.leftColor.r != m_currentTheme.leftColor.r) {
        m_transition.start(m_currentTheme, newTheme, 1.0f);
        m_lastTheme = m_currentTheme;
    }

    m_currentTheme = newTheme;
}

const Theme& ThemeManager::currentTheme() const {
    return m_currentTheme;
}

} // namespace MyFramework
