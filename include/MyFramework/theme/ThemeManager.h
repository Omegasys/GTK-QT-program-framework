#pragma once

#include <string>
#include <unordered_map>
#include <MyFramework/utils/Color.h>

struct Theme {
    Color background;
    Color foreground;
    float opacity = 1.0f;
};

class ThemeManager {
public:
    static ThemeManager& instance();

    void loadTheme(const std::string& name);
    const Theme& currentTheme() const;

    void setTheme(const std::string& name);

private:
    ThemeManager();

    Theme loadDefaultTheme();
    Theme loadFallbackTheme();

private:
    std::unordered_map<std::string, Theme> themes;
    Theme activeTheme;
};
