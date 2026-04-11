#include <MyFramework/core/Timer.h>

namespace MyFramework {

// =======================
// Timer
// =======================

Timer::Timer() {
    reset();
}

void Timer::reset() {
    m_start = std::chrono::steady_clock::now();
}

double Timer::elapsed() const {
    auto now = std::chrono::steady_clock::now();
    return std::chrono::duration<double>(now - m_start).count();
}

long long Timer::elapsedMs() const {
    auto now = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now - m_start).count();
}

// =======================
// IntervalTimer
// =======================

IntervalTimer::IntervalTimer()
    : m_running(false) {}

void IntervalTimer::start(int intervalMs, std::function<void()> callback) {
    m_running = true;

    // NOTE: This is a simple placeholder.
    // Real implementation should use threads or event loop.
    while (m_running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(intervalMs));
        if (callback) callback();
    }
}

void IntervalTimer::stop() {
    m_running = false;
}

bool IntervalTimer::isRunning() const {
    return m_running;
}

} // namespace MyFramework
