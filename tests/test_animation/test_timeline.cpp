#include <MyFramework/animation/Timeline.h>
#include <MyFramework/utils/Time.h>
#include <iostream>

using namespace MyFramework;

void run_timeline_tests() {
    std::cout << "[TEST] Timeline\n";

    Timeline timeline;
    timeline.setDuration(1.0f);
    timeline.play();

    // Simulate time progression
    Time::setDeltaTime(1.0f);
    timeline.update();

    if (timeline.isFinished())
        std::cout << "  ✔ Timeline finished correctly\n";
    else
        std::cout << "  ✖ Timeline did not finish\n";
}
