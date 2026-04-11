#include "ThemeTimelineView.h"
#include <MyFramework/utils/Logger.h>

using namespace MyFramework;

ThemeTimelineView::ThemeTimelineView(Window* parent)
    : Widget(parent) {}

void ThemeTimelineView::update() {
    for (auto& kf : keyframes) {
        if (kf.time < 0 || kf.time > 1440) {
            Logger::warn("Invalid theme keyframe time");
        }
    }
}

void ThemeTimelineView::addKeyframe(int time, const std::string& themeId) {
    keyframes.push_back({time, themeId});
}
