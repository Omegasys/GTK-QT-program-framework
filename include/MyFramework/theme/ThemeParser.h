#pragma once

#include <string>

namespace GQFusion {

class Theme;

/**
 * @brief Parses theme definitions from files or strings.
 *
 * Responsible for converting theme config formats into Theme objects.
 */
class ThemeParser {
public:
    /**
     * @brief Parse a theme from a file.
     * @param path File path to theme definition
     */
    static Theme parseFile(const std::string& path);

    /**
     * @brief Parse a theme from a raw string.
     */
    static Theme parseString(const std::string& data);

private:
    /**
     * @brief Parse a single key-value line.
     */
    static void parseLine(Theme& theme,
                          const std::string& key,
                          const std::string& value);

    /**
     * @brief Parse color from string (e.g. "#RRGGBB")
     */
    static void parseColor(/* out */ Theme& theme,
                           const std::string& key,
                           const std::string& value);

    /**
     * @brief Trim whitespace helper
     */
    static std::string trim(const std::string& str);
};

} // namespace GQFusion
