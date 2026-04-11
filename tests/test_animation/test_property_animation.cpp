#include <MyFramework/animation/PropertyAnimation.h>
#include <MyFramework/utils/Time.h>
#include <iostream>

using namespace MyFramework;

void run_property_animation_tests() {
    std::cout << "[TEST] PropertyAnimation\n";

    float value = 0.0f;

    PropertyAnimation<float> anim;
    anim.setStartValue(0.0f);
    anim.setEndValue(100.0f);
    anim.setDuration(1.0f);

    anim.onUpdate([&](float v) {
        value = v;
    });

    anim.play();

    // Simulate full duration
    Time::setDeltaTime(1.0f);
    anim.update();

    if (value > 90.0f)
        std::cout << "  ✔ Property animation reached target\n";
    else
        std::cout << "  ✖ Property animation failed\n";
}
