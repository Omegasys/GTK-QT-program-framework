#pragma once
#include <string>
#include <functional>
#include <thread>
#include <atomic>

namespace MyFramework {

class ConfigWatcher {
public:
    ConfigWatcher(const std::string& path);

    void start(std::function<void()> onChange);
    void stop();

private:
    std::string filePath;
    std::atomic<bool> running{false};
    std::thread watcherThread;

    long getLastWriteTime();
};

}
