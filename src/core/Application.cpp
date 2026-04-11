#include <MyFramework/core/Application.h>
#include <MyFramework/platform/Platform.h>
#include <MyFramework/utils/Time.h>
#include <MyFramework/system_ui/SystemUIManager.h>

void Application::run() {
    SystemUIManager::instance().initialize();

    while (running) {
        // existing loop...

        SystemUIManager::instance().update();
    }
}

namespace MyFramework {

Application::Application()
    : m_running(false) {
}

Application::~Application() {
    shutdown();
}

bool Application::initialize() {
    if (!Platform::initialize())
        return false;

    m_running = true;
    return true;
}

void Application::shutdown() {
    Platform::shutdown();
    m_running = false;
}

void Application::run() {
    using clock = std::chrono::steady_clock;

    auto last = clock::now();

    while (m_running) {
        auto now = clock::now();
        double dt = std::chrono::duration<double>(now - last).count();
        last = now;

        Time::setDeltaTime(dt);

        // Process events
        processEvents();

        // Update
        update(dt);

        // Render
        render();
    }
}

void Application::quit() {
    m_running = false;
}

// =======================
// Hooks (to be expanded)
// =======================

void Application::processEvents() {
    // TODO: integrate WindowImpl polling
}

void Application::update(double dt) {
    // TODO: update animations, themes, etc.
}

void Application::render() {
    // TODO: call renderer
}

} // namespace MyFramework
