#include "ThemeSlotEditor.h"

#include <MyFramework/utils/Logger.h>

using namespace MyFramework;

ThemeSlotEditor::ThemeSlotEditor(Window* parent)
    : Widget(parent) {}

void ThemeSlotEditor::update() {
    for (auto& slot : slots) {
        if (slot.themes.empty()) {
            Logger::warn("Theme slot has no themes assigned");
        }
    }
}

void ThemeSlotEditor::addThemeSlot(const std::string& name) {
    slots.push_back({name, {}});
}

void ThemeSlotEditor::assignTheme(const std::string& slot, const std::string& themeId) {
    for (auto& s : slots) {
        if (s.name == slot) {
            s.themes.push_back(themeId);
        }
    }
}
