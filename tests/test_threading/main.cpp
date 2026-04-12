#include <iostream>

// Include all tests
#include "test_threadpool.cpp"
#include "test_jobsystem.cpp"
#include "test_command_scheduler.cpp"
#include "test_parallel_rendering.cpp"

int main() {
    std::cout << "[Test Suite] Threading\n\n";

    test_threadpool();
    test_jobsystem();
    test_command_scheduler();
    test_parallel_rendering();

    std::cout << "\n[ALL THREADING TESTS PASSED]\n";
    return 0;
}
