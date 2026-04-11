#include "ThemeManager.h"

#include <MyFramework/utils/Logger.h>

using namespace std;

ThemeManager& ThemeManager::instance() {
    static ThemeManager inst;
    return inst;
}

ThemeManager::ThemeManager() {
    // Register built-in themes
    themes["default"] = loadDefaultTheme();
    themes["dark"] = {
        Color(30, 30, 30),
        Color(220, 220, 220),
        1.0f
    };
}

void ThemeManager::loadTheme(const std::string& name) {
    auto it = themes.find(name);

    if (it != themes.end()) {
        activeTheme = it->second;
        Logger::info("Loaded theme: " + name);
    } else {
        Logger::warn("Theme not found: " + name + ", using fallback");
        activeTheme = loadFallbackTheme();
    }
}

void ThemeManager::setTheme(const std::string& name) {
    loadTheme(name);
}

const Theme& ThemeManager::currentTheme() const {
    return activeTheme;
}

Theme ThemeManager::loadDefaultTheme() {
    Theme t;
    t.background = Color(240, 240, 240);
    t.foreground = Color(20, 20, 20);
    t.opacity = 1.0f;
    return t;
}

Theme ThemeManager::loadFallbackTheme() {
    // Emergency fallback (guaranteed safe)
    Theme t;
    t.background = Color(50, 50, 50);
    t.foreground = Color(255, 255, 255);
    t.opacity = 1.0f;
    return t;
}
