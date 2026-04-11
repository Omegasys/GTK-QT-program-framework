#include "LayoutDebugger.h"

#include <MyFramework/utils/Logger.h>

using namespace MyFramework;

LayoutDebugger::LayoutDebugger(Window* parent)
    : Widget(parent) {}

void LayoutDebugger::refreshLayoutData() {
    // Placeholder: in real system, query layout engine

    boxes.clear();

    boxes.push_back({10, 10, 200, 100, "RootWindow"});
    boxes.push_back({20, 120, 180, 60, "Button"});
    boxes.push_back({210, 120, 300, 200, "Panel"});
}

void LayoutDebugger::update() {
    refreshLayoutData();

    // Simulated debug rendering output
    if (showGrid) {
        Logger::info("[LayoutDebugger] Grid enabled");
    }

    for (const auto& box : boxes) {
        if (showBounds) {
            Logger::info("Box: " + box.name +
                         " (" + std::to_string(box.x) + "," +
                         std::to_string(box.y) + ")");
        }
    }
}
