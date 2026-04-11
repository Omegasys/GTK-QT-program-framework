#pragma once

#include <MyFramework/ui/Widget.h>
#include <string>
#include <vector>

struct ThemeKeyframe {
    int time; // minutes in day
    std::string themeId;
};

class ThemeTimelineView : public MyFramework::Widget {
public:
    ThemeTimelineView(MyFramework::Window* parent);

    void update();

    void addKeyframe(int time, const std::string& themeId);

private:
    std::vector<ThemeKeyframe> keyframes;
};
