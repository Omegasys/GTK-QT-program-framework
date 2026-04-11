#pragma once

#include <string>
#include <vector>

namespace GQFusion {
namespace String {

/**
 * @brief Trim whitespace from both ends.
 */
std::string trim(const std::string& str);

/**
 * @brief Convert string to lowercase.
 */
std::string toLower(const std::string& str);

/**
 * @brief Convert string to uppercase.
 */
std::string toUpper(const std::string& str);

/**
 * @brief Split string by delimiter.
 */
std::vector<std::string> split(const std::string& str, char delimiter);

/**
 * @brief Check if string starts with prefix.
 */
bool startsWith(const std::string& str, const std::string& prefix);

/**
 * @brief Check if string ends with suffix.
 */
bool endsWith(const std::string& str, const std::string& suffix);

/**
 * @brief Replace all occurrences of a substring.
 */
std::string replaceAll(const std::string& str,
                       const std::string& from,
                       const std::string& to);

/**
 * @brief Convert string to int safely.
 */
int toInt(const std::string& str, int defaultValue = 0);

/**
 * @brief Convert string to float safely.
 */
float toFloat(const std::string& str, float defaultValue = 0.0f);

/**
 * @brief Convert bool string ("true"/"false"/"1"/"0").
 */
bool toBool(const std::string& str, bool defaultValue = false);

} // namespace String
} // namespace GQFusion
