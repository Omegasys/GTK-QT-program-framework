#pragma once

#include <MyFramework/ui/Widget.h>
#include <vector>
#include <string>

class WidgetTreeView : public MyFramework::Widget {
public:
    WidgetTreeView(MyFramework::Window* parent);

    void update();
    void refreshTree();

private:
    std::vector<std::string> widgetNames;
};
