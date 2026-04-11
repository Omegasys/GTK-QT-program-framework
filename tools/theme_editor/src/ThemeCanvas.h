#pragma once

#include <MyFramework/ui/Widget.h>
#include <MyFramework/utils/Color.h>

class ThemeCanvas : public MyFramework::Widget {
public:
    ThemeCanvas(MyFramework::Window* parent);

    void update();

    void setPrimaryColor(const MyFramework::Color& color);
    void setSecondaryColor(const MyFramework::Color& color);

private:
    MyFramework::Color primary;
    MyFramework::Color secondary;
};
