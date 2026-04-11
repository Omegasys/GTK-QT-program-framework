#include <MyFramework/utils/FileSystem.h>
#include <filesystem>
#include <fstream>

namespace MyFramework {

bool FileSystem::exists(const std::string& path) {
    return std::filesystem::exists(path);
}

std::string FileSystem::readFile(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open())
        return "";

    return std::string(
        (std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>()
    );
}

bool FileSystem::writeFile(const std::string& path, const std::string& content) {
    std::ofstream file(path);
    if (!file.is_open())
        return false;

    file << content;
    return true;
}

std::time_t FileSystem::lastWriteTime(const std::string& path) {
    auto ftime = std::filesystem::last_write_time(path);
    return decltype(ftime)::clock::to_time_t(ftime);
}

} // namespace MyFramework
