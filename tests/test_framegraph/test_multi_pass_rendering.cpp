#include <iostream>
#include <vector>
#include <string>
#include <cassert>

/*
 * Simulates multi-pass rendering pipeline
 */

struct Pass {
    std::string name;
    std::string input;
    std::string output;
};

void test_multi_pass_rendering() {
    std::cout << "[Test] Multi-Pass Rendering\n";

    std::vector<Pass> pipeline = {
        {"UI Pass", "", "ui_buffer"},
        {"Blur Pass", "ui_buffer", "blur_buffer"},
        {"Glow Pass", "blur_buffer", "glow_buffer"},
        {"Composite Pass", "glow_buffer", "final_output"}
    };

    // Validate pipeline continuity
    for (size_t i = 1; i < pipeline.size(); i++) {
        assert(pipeline[i].input == pipeline[i - 1].output);
    }

    // Final output check
    assert(pipeline.back().output == "final_output");

    std::cout << "[PASS] Multi-Pass Rendering\n";
}
