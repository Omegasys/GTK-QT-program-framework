#pragma once

#include <string>
#include <memory>

namespace MyFramework {

class WindowImpl;

/**
 * @brief Platform abstraction layer.
 *
 * Responsible for:
 * - OS detection
 * - Window creation
 * - Input backend initialization
 * - Clipboard / system integration (future)
 */
class Platform {
public:
    enum class Type {
        Windows,
        Linux,
        MacOS,
        Unknown
    };

    /**
     * @brief Detects current OS.
     */
    static Type detect();

    /**
     * @brief Initializes platform layer.
     */
    static bool initialize();

    /**
     * @brief Shuts down platform layer.
     */
    static void shutdown();

    /**
     * @brief Creates a native window implementation.
     */
    static WindowImpl* createWindow(int width, int height, const std::string& title);

    /**
     * @brief Returns platform name as string.
     */
    static std::string name();

private:
    static Type s_type;
    static bool s_initialized;
};

} // namespace MyFramework
