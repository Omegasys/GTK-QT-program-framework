#include <iostream>

// Include all tests
#include "test_pass_execution.cpp"
#include "test_resource_dependencies.cpp"
#include "test_execution_order.cpp"
#include "test_multi_pass_rendering.cpp"

int main() {
    std::cout << "[Test Suite] FrameGraph\n\n";

    test_pass_execution();
    test_resource_dependencies();
    test_execution_order();
    test_multi_pass_rendering();

    std::cout << "\n[ALL FRAMEGRAPH TESTS PASSED]\n";
    return 0;
}
