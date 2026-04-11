#include "Taskbar.h"
#include <MyFramework/theme/ThemeManager.h>

using namespace MyFramework;

Taskbar::Taskbar(Window* parent)
    : Widget(parent) {}

void Taskbar::applyTheme() {
    auto theme = ThemeManager::instance().currentTheme();

    // apply theme->taskbar values
}

void Taskbar::update() {
    applyTheme();

    // render taskbar UI (buttons, icons, etc.)
}
