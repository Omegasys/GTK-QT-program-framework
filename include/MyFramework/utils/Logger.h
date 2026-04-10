#pragma once

#include <string>

namespace MyFramework {

/**
 * @brief Logging system for debugging and runtime diagnostics.
 */
class Logger {
public:
    enum class Level {
        Info,
        Warning,
        Error,
        Debug
    };

    /**
     * @brief Logs a message.
     */
    static void log(Level level, const std::string& message);

    static void info(const std::string& message);
    static void warn(const std::string& message);
    static void error(const std::string& message);
    static void debug(const std::string& message);

    /**
     * @brief Enables or disables debug logging.
     */
    static void setDebugEnabled(bool enabled);

private:
    static bool s_debugEnabled;
};

} // namespace MyFramework
