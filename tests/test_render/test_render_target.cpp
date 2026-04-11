#include <MyFramework/render/RenderTarget.h>
#include <iostream>

using namespace MyFramework;

void run_render_target_tests() {
    std::cout << "[TEST] RenderTarget\n";

    RenderTarget target(640, 480);

    if (target.width() == 640 && target.height() == 480)
        std::cout << "  ✔ Initial size correct\n";
    else
        std::cout << "  ✖ Initial size incorrect\n";

    target.resize(800, 600);

    if (target.width() == 800 && target.height() == 600)
        std::cout << "  ✔ Resize works\n";
    else
        std::cout << "  ✖ Resize failed\n";
}
