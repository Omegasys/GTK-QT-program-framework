#include <iostream>
#include <vector>
#include <thread>
#include <atomic>
#include <cassert>

/*
 * Simulates a basic thread pool executing jobs
 */

void test_threadpool() {
    std::cout << "[Test] ThreadPool\n";

    const int jobCount = 10;
    std::atomic<int> counter = 0;

    std::vector<std::thread> workers;

    for (int i = 0; i < jobCount; i++) {
        workers.emplace_back([&]() {
            counter++;
        });
    }

    for (auto& t : workers)
        t.join();

    assert(counter == jobCount);

    std::cout << "[PASS] ThreadPool\n";
}
