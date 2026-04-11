#include <MyFramework/config/ConfigSerializer.h>
#include <fstream>

namespace MyFramework {

bool ConfigSerializer::saveToFile(const Config& config, const std::string& path) {
    std::ofstream file(path);
    if (!file.is_open())
        return false;

    for (const auto& [key, value] : config.values()) {
        file << key << "=" << value << "\n";
    }

    return true;
}

} // namespace MyFramework
