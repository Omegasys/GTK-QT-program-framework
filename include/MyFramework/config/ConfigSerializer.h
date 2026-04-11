#pragma once

#include <string>

namespace GQFusion {

class Config;

/**
 * @brief Handles serialization and deserialization of Config objects.
 *
 * Responsible for converting Config data to and from file/string formats.
 */
class ConfigSerializer {
public:
    // ------------------------------------------------------------
    // File Operations
    // ------------------------------------------------------------

    /**
     * @brief Save a config to a file.
     * @param config Config object to save
     * @param path File path
     * @return true if successful
     */
    static bool saveToFile(const Config& config, const std::string& path);

    /**
     * @brief Load a config from a file.
     * @param path File path
     * @return Parsed Config object
     */
    static Config loadFromFile(const std::string& path);

    // ------------------------------------------------------------
    // String Operations
    // ------------------------------------------------------------

    /**
     * @brief Serialize config to string format.
     */
    static std::string serialize(const Config& config);

    /**
     * @brief Deserialize config from string.
     */
    static Config deserialize(const std::string& data);

private:
    // Internal helpers (optional expansion point)
    static void writeKeyValue(std::string& out,
                             const std::string& key,
                             const std::string& value);
};

} // namespace GQFusion
