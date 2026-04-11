#pragma once

#include <MyFramework/ui/Widget.h>
#include <vector>
#include <utility>

#include <MyFramework/utils/Color.h>

class GradientEditor : public MyFramework::Widget {
public:
    GradientEditor(MyFramework::Window* parent);

    void update();

    void addStop(float position, const MyFramework::Color& color);

private:
    std::vector<std::pair<float, MyFramework::Color>> stops;
};
