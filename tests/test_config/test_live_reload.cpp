#include <MyFramework/config/ConfigWatcher.h>
#include <MyFramework/utils/FileSystem.h>
#include <iostream>
#include <thread>
#include <chrono>

using namespace MyFramework;

void run_live_reload_tests() {
    std::cout << "[TEST] Live Reload (ConfigWatcher)\n";

    std::string path = "test_live_reload.tmp";

    FileSystem::writeFile(path, "value=1");

    bool triggered = false;

    ConfigWatcher watcher(path);
    watcher.onConfigChanged = [&](const std::string&) {
        triggered = true;
    };

    watcher.start();

    // Modify file after short delay
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    FileSystem::writeFile(path, "value=2");

    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    watcher.stop();

    if (triggered)
        std::cout << "  ✔ Live reload triggered\n";
    else
        std::cout << "  ✖ Live reload failed\n";
}
