#pragma once

#include <vector>
#include <thread>
#include <functional>
#include <queue>
#include <mutex>
#include <condition_variable>

namespace GQFusion {

/**
 * @brief Basic thread pool for parallel task execution.
 */
class ThreadPool {
public:
    ThreadPool(size_t threadCount);
    ~ThreadPool();

    // Submit a task
    void enqueue(std::function<void()> task);

    // Stop all threads
    void shutdown();

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop = false;
};

} // namespace GQFusion
