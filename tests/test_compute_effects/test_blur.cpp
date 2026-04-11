#include <iostream>
#include <vector>
#include <cassert>

/*
 * Simulated blur test (CPU-side validation)
 */

void test_blur() {
    std::cout << "[Test] Blur Effect\n";

    std::vector<float> input = {1, 2, 3, 4, 5};
    std::vector<float> output(5, 0.0f);

    // Simple 3-sample blur
    for (size_t i = 1; i < input.size() - 1; i++) {
        output[i] = (input[i-1] + input[i] + input[i+1]) / 3.0f;
    }

    assert(output[2] == 3.0f); // (2+3+4)/3

    std::cout << "[PASS] Blur\n";
}
