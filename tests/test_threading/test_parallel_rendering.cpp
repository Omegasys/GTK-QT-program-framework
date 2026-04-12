#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <cassert>

/*
 * Simulates parallel rendering workload
 */

void test_parallel_rendering() {
    std::cout << "[Test] Parallel Rendering\n";

    const int tasks = 8;
    std::atomic<int> completed = 0;

    std::vector<std::thread> threads;

    for (int i = 0; i < tasks; i++) {
        threads.emplace_back([&]() {
            // Simulate render work
            for (volatile int j = 0; j < 100000; j++);
            completed++;
        });
    }

    for (auto& t : threads)
        t.join();

    assert(completed == tasks);

    std::cout << "[PASS] Parallel Rendering\n";
}
