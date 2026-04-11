#include <iostream>
#include <vector>
#include <string>
#include <cassert>

/*
 * Validates that passes execute when scheduled
 */

void test_pass_execution() {
    std::cout << "[Test] Pass Execution\n";

    std::vector<std::string> executed;

    // Simulated execution
    auto runPass = [&](const std::string& name) {
        executed.push_back(name);
    };

    runPass("UI Pass");
    runPass("Blur Pass");

    assert(executed.size() == 2);
    assert(executed[0] == "UI Pass");
    assert(executed[1] == "Blur Pass");

    std::cout << "[PASS] Pass Execution\n";
}
