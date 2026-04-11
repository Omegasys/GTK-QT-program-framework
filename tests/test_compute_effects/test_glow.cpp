#include <iostream>
#include <vector>
#include <cassert>

/*
 * Glow = threshold + amplification
 */

void test_glow() {
    std::cout << "[Test] Glow Effect\n";

    std::vector<float> input = {0.1f, 0.5f, 0.9f};
    std::vector<float> output(3);

    float threshold = 0.6f;

    for (size_t i = 0; i < input.size(); i++) {
        output[i] = (input[i] > threshold) ? input[i] * 2.0f : 0.0f;
    }

    assert(output[2] > 1.0f);
    assert(output[0] == 0.0f);

    std::cout << "[PASS] Glow\n";
}
