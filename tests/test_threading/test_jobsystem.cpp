#include <iostream>
#include <queue>
#include <functional>
#include <cassert>

/*
 * Simulates a job system queue
 */

void test_jobsystem() {
    std::cout << "[Test] JobSystem\n";

    std::queue<std::function<void()>> jobs;
    int result = 0;

    jobs.push([&]() { result += 1; });
    jobs.push([&]() { result += 2; });
    jobs.push([&]() { result += 3; });

    while (!jobs.empty()) {
        jobs.front()();
        jobs.pop();
    }

    assert(result == 6);

    std::cout << "[PASS] JobSystem\n";
}
