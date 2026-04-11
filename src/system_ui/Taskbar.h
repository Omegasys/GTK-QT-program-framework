#pragma once
#include <MyFramework/ui/Widget.h>

class Taskbar : public MyFramework::Widget {
public:
    Taskbar(MyFramework::Window* parent);

    void update();
    void applyTheme();
};
