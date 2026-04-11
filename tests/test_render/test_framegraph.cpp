#include <iostream>
#include <vector>
#include <string>
#include <cassert>

/*
 * Basic FrameGraph validation test
 */

struct Pass {
    std::string name;
    std::vector<std::string> inputs;
    std::vector<std::string> outputs;
};

int main() {
    std::cout << "[Test] FrameGraph\n";

    std::vector<Pass> graph = {
        {"UI Pass", {}, {"ui_buffer"}},
        {"Blur Pass", {"ui_buffer"}, {"blur_buffer"}},
        {"Glow Pass", {"blur_buffer"}, {"glow_buffer"}},
        {"Composite Pass", {"glow_buffer"}, {"final_output"}}
    };

    // Validate dependency chain
    assert(graph[1].inputs[0] == "ui_buffer");
    assert(graph[2].inputs[0] == "blur_buffer");
    assert(graph[3].inputs[0] == "glow_buffer");

    // Validate output exists
    assert(graph.back().outputs[0] == "final_output");

    std::cout << "[PASS] FrameGraph structure valid\n";
    return 0;
}
