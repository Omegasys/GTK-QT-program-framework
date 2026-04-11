#include "EventMonitor.h"

#include <MyFramework/utils/Logger.h>

using namespace MyFramework;

EventMonitor::EventMonitor(Window* parent)
    : Widget(parent) {}

void EventMonitor::capture(const Event& e) {
    eventLog.push_back("Event captured");
}

void EventMonitor::update() {
    // Render event log (placeholder)

    if (eventLog.size() > 100)
        eventLog.erase(eventLog.begin());
}
