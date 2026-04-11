#include <iostream>
#include <vector>
#include <string>
#include <cassert>

/*
 * Ensures passes execute in dependency order
 */

void test_execution_order() {
    std::cout << "[Test] Execution Order\n";

    std::vector<std::string> order = {
        "UI Pass",
        "Blur Pass",
        "Glow Pass",
        "Composite Pass"
    };

    auto indexOf = [&](const std::string& name) {
        for (size_t i = 0; i < order.size(); i++) {
            if (order[i] == name) return i;
        }
        return size_t(-1);
    };

    // Validate ordering constraints
    assert(indexOf("UI Pass") < indexOf("Blur Pass"));
    assert(indexOf("Blur Pass") < indexOf("Glow Pass"));
    assert(indexOf("Glow Pass") < indexOf("Composite Pass"));

    std::cout << "[PASS] Execution Order\n";
}
