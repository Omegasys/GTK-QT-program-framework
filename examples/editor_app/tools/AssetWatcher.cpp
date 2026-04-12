#include "AssetWatcher.h"
#include <iostream>

namespace fs = std::filesystem;

namespace gqf {

AssetWatcher::AssetWatcher() = default;
AssetWatcher::~AssetWatcher() = default;

void AssetWatcher::watchFile(const std::string& path, Callback callback) {
    if (!fs::exists(path)) return;

    m_watchList[path] = {
        fs::last_write_time(path),
        callback,
        false
    };
}

void AssetWatcher::watchDirectory(const std::string& path, Callback callback) {
    if (!fs::exists(path)) return;

    m_watchList[path] = {
        fs::last_write_time(path),
        callback,
        true
    };
}

void AssetWatcher::poll() {
    for (auto& [path, entry] : m_watchList) {
        checkFile(path, entry);
    }
}

void AssetWatcher::checkFile(const std::string& path, WatchEntry& entry) {
    if (!fs::exists(path)) return;

    auto currentWrite = fs::last_write_time(path);

    if (currentWrite != entry.lastWrite) {
        entry.lastWrite = currentWrite;

        std::cout << "[AssetWatcher] Changed: " << path << "\n";

        if (entry.callback)
            entry.callback(path);
    }
}

} // namespace gqf
