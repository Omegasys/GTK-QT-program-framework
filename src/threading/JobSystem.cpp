#include <GQFusion/threading/JobSystem.h>
#include <iostream>

namespace GQFusion {

JobSystem::JobSystem() = default;

JobSystem::~JobSystem() = default;

void JobSystem::initialize(int threads) {
    std::cout << "[JobSystem] Initialized with " << threads << " threads\n";
}

void JobSystem::addJob(const Job& job) {
    jobs.push_back(job);
}

void JobSystem::wait() {
    for (auto& job : jobs) {
        job();
    }

    jobs.clear();
}

} // namespace GQFusion
