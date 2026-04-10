#pragma once

#include <atomic>
#include <functional>
#include <memory>
#include <vector>
#include <string>

namespace MyFramework {

class Window;

/**
 * @brief Core application class.
 *
 * Manages the application lifecycle, main event loop,
 * and global state.
 *
 * Only one instance of Application should exist.
 */
class Application {
public:
    /**
     * @brief Constructs the application.
     *
     * Initializes internal systems.
     */
    Application();

    /**
     * @brief Destructor.
     */
    ~Application();

    // Disable copy
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    // Allow move
    Application(Application&&) = default;
    Application& operator=(Application&&) = default;

    /**
     * @brief Starts the main event loop.
     * @return Exit code
     */
    int run();

    /**
     * @brief Requests application shutdown.
     */
    void quit();

    /**
     * @brief Checks if the application is running.
     */
    bool isRunning() const;

    /**
     * @brief Adds a window to the application.
     */
    void addWindow(Window* window);

    /**
     * @brief Removes a window from the application.
     */
    void removeWindow(Window* window);

    /**
     * @brief Returns all registered windows.
     */
    const std::vector<Window*>& windows() const;

    /**
     * @brief Executes a function on the main thread.
     *
     * Useful for thread-safe UI updates.
     */
    void post(std::function<void()> task);

    /**
     * @brief Sets callback before event loop starts.
     */
    void onStart(std::function<void()> callback);

    /**
     * @brief Sets callback before shutdown.
     */
    void onExit(std::function<void()> callback);

    /**
     * @brief Returns the global application instance.
     */
    static Application& instance();

private:
    void processEvents();
    void executePostedTasks();

private:
    static Application* s_instance;

    std::atomic<bool> m_running;

    std::vector<Window*> m_windows;

    std::vector<std::function<void()>> m_taskQueue;

    std::function<void()> m_onStart;
    std::function<void()> m_onExit;
};

} // namespace MyFramework
