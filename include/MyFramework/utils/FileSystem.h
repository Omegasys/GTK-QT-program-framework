#pragma once

#include <string>
#include <vector>

namespace GQFusion {
namespace FileSystem {

/**
 * @brief Check if a file exists.
 */
bool exists(const std::string& path);

/**
 * @brief Create directory (recursive).
 */
bool createDirectory(const std::string& path);

/**
 * @brief Read entire file into string.
 */
std::string readFile(const std::string& path);

/**
 * @brief Write string to file.
 */
bool writeFile(const std::string& path, const std::string& content);

/**
 * @brief Get file extension.
 */
std::string getExtension(const std::string& path);

/**
 * @brief Get file name from path.
 */
std::string getFileName(const std::string& path);

/**
 * @brief Get parent directory.
 */
std::string getDirectory(const std::string& path);

/**
 * @brief List files in directory.
 */
std::vector<std::string> listFiles(const std::string& directory);

/**
 * @brief Get current working directory.
 */
std::string currentPath();

/**
 * @brief Join two paths.
 */
std::string join(const std::string& a, const std::string& b);

} // namespace FileSystem
} // namespace GQFusion
