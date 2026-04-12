#pragma once

#include <string>
#include <functional>
#include <unordered_map>
#include <filesystem>

namespace gqf {

/// Watches files and directories for changes
class AssetWatcher {
public:
    using Callback = std::function<void(const std::string&)>;

    AssetWatcher();
    ~AssetWatcher();

    void watchFile(const std::string& path, Callback callback);
    void watchDirectory(const std::string& path, Callback callback);

    void poll(); // Call every frame or tick

private:
    struct WatchEntry {
        std::filesystem::file_time_type lastWrite;
        Callback callback;
        bool isDirectory;
    };

    std::unordered_map<std::string, WatchEntry> m_watchList;

    void checkFile(const std::string& path, WatchEntry& entry);
};

} // namespace gqf
