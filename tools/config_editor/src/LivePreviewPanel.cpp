#include "LivePreviewPanel.h"
#include <MyFramework/config/ConfigParser.h>
#include <MyFramework/theme/ThemeManager.h>
#include <MyFramework/utils/Logger.h>

using namespace MyFramework;

LivePreviewPanel::LivePreviewPanel(Window* parent)
    : Widget(parent) {}

void LivePreviewPanel::update(const std::string& configData) {
    Config config = ConfigParser::parseString(configData);

    themeManager.loadFromConfig(config);

    Theme current = themeManager.currentTheme();

    Logger::info("Preview updated: opacity = " + std::to_string(current.opacity));
}
