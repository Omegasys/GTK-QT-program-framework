#include <iostream>

// Forward include tests (simple aggregation)
#include "test_blur.cpp"
#include "test_glow.cpp"
#include "test_shadow.cpp"
#include "test_redshift.cpp"

int main() {
    std::cout << "[Test Suite] Compute Effects\n\n";

    test_blur();
    test_glow();
    test_shadow();
    test_redshift();

    std::cout << "\n[ALL TESTS PASSED]\n";
    return 0;
}
