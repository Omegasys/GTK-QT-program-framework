#include <MyFramework/utils/Logger.h>
#include <iostream>

using namespace MyFramework;

void run_logger_tests() {
    std::cout << "[TEST] Logger\n";

    Logger::info("This is an info message");
    Logger::warn("This is a warning");
    Logger::error("This is an error");

    std::cout << "  ✔ Logger output displayed (manual check)\n";
}
