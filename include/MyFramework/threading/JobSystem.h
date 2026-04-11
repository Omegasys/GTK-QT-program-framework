#pragma once

#include <functional>
#include <vector>

namespace GQFusion {

/**
 * @brief High-level job system built on top of ThreadPool.
 */
class JobSystem {
public:
    using Job = std::function<void()>;

    JobSystem();
    ~JobSystem();

    void initialize(int threads);

    void addJob(const Job& job);

    void wait();

private:
    std::vector<Job> jobs;
};

} // namespace GQFusion
