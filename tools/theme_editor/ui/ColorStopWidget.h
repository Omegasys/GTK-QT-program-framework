#pragma once

#include <MyFramework/ui/Widget.h>
#include <MyFramework/utils/Color.h>

class ColorStopWidget : public MyFramework::Widget {
public:
    ColorStopWidget(MyFramework::Window* parent);

    void setPosition(float t); // 0.0 - 1.0 along gradient
    float getPosition() const;

    void setColor(const MyFramework::Color& color);
    MyFramework::Color getColor() const;

    void update();

private:
    float position = 0.0f; // normalized gradient position
    MyFramework::Color color;
    bool dragging = false;
};
