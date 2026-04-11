#include <MyFramework/animation/Easing.h>
#include <iostream>

using namespace MyFramework;

void run_easing_tests() {
    std::cout << "[TEST] Easing\n";

    float linear = Easing::linear(0.5f);
    float easeIn = Easing::easeIn(0.5f);
    float easeOut = Easing::easeOut(0.5f);

    if (linear == 0.5f)
        std::cout << "  ✔ Linear easing correct\n";
    else
        std::cout << "  ✖ Linear easing incorrect\n";

    if (easeIn < 0.5f)
        std::cout << "  ✔ EaseIn curve correct\n";
    else
        std::cout << "  ✖ EaseIn incorrect\n";

    if (easeOut > 0.5f)
        std::cout << "  ✔ EaseOut curve correct\n";
    else
        std::cout << "  ✖ EaseOut incorrect\n";
}
