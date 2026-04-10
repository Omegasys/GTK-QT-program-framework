#include "MyFramework/config/ConfigWatcher.h"
#include <filesystem>
#include <chrono>
#include <thread>

namespace MyFramework {

ConfigWatcher::ConfigWatcher(const std::string& path)
    : filePath(path) {}

long ConfigWatcher::getLastWriteTime() {
    auto ftime = std::filesystem::last_write_time(filePath);
    return decltype(ftime)::clock::to_time_t(ftime);
}

void ConfigWatcher::start(std::function<void()> onChange) {
    running = true;

    watcherThread = std::thread([this, onChange]() {
        long lastTime = getLastWriteTime();

        while (running) {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));

            long currentTime = getLastWriteTime();
            if (currentTime != lastTime) {
                lastTime = currentTime;
                onChange();
            }
        }
    });
}

void ConfigWatcher::stop() {
    running = false;
    if (watcherThread.joinable()) {
        watcherThread.join();
    }
}

}
