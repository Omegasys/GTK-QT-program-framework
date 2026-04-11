#pragma once

#include <MyFramework/ui/Widget.h>
#include <vector>

struct LayoutBox {
    float x, y, w, h;
    std::string name;
};

class LayoutDebugger : public MyFramework::Widget {
public:
    LayoutDebugger(MyFramework::Window* parent);

    void update();

    void refreshLayoutData();

private:
    std::vector<LayoutBox> boxes;
    bool showGrid = true;
    bool showBounds = true;
};
