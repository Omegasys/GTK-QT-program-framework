#include "TimeFrameEditor.h"

#include <MyFramework/ui/Widget.h>
#include <MyFramework/utils/Logger.h>

using namespace MyFramework;

TimeFrameEditor::TimeFrameEditor(Window* parent)
    : Widget(parent) {}

void TimeFrameEditor::update() {
    // Simulated UI logic for editing timeframes

    for (auto& frame : frames) {
        if (frame.start >= frame.end) {
            Logger::warn("Invalid timeframe detected");
        }
    }
}

void TimeFrameEditor::addFrame(int start, int end, const std::string& themeId) {
    frames.push_back({start, end, themeId});
}
