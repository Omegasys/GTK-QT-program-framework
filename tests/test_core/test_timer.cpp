#include <MyFramework/core/Timer.h>
#include <MyFramework/utils/Time.h>
#include <iostream>

using namespace MyFramework;

void run_timer_tests() {
    std::cout << "[TEST] Timer\n";

    Timer timer;
    timer.start(1.0f);

    // Simulate time passing
    Time::setDeltaTime(1.0);

    timer.update();

    if (timer.isFinished())
        std::cout << "  ✔ Timer finished correctly\n";
    else
        std::cout << "  ✖ Timer did not finish\n";
}
