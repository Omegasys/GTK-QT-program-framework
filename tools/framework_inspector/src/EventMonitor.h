#pragma once

#include <MyFramework/core/Event.h>
#include <MyFramework/ui/Widget.h>
#include <vector>

class EventMonitor : public MyFramework::Widget {
public:
    EventMonitor(MyFramework::Window* parent);

    void capture(const MyFramework::Event& e);
    void update();

private:
    std::vector<std::string> eventLog;
};
