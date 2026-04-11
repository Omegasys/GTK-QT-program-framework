#include <MyFramework/core/Application.h>
#include <MyFramework/utils/Logger.h>
#include <iostream>

using namespace MyFramework;

void run_full_app_boot_test() {
    std::cout << "[TEST] Full App Boot\n";

    Application app;

    if (app.initialize()) {
        std::cout << "  ✔ Application initialized\n";
    } else {
        std::cout << "  ✖ Application failed to initialize\n";
        return;
    }

    app.shutdown();

    std::cout << "  ✔ Application shutdown cleanly\n";
}
