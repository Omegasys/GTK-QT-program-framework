#include <iostream>
#include <vector>
#include <string>
#include <cassert>

/*
 * Simulates command scheduling and ordering
 */

void test_command_scheduler() {
    std::cout << "[Test] CommandScheduler\n";

    std::vector<std::string> commands;

    auto schedule = [&](const std::string& cmd) {
        commands.push_back(cmd);
    };

    schedule("Upload Buffers");
    schedule("Dispatch Compute");
    schedule("Draw UI");

    assert(commands.size() == 3);
    assert(commands[0] == "Upload Buffers");
    assert(commands[2] == "Draw UI");

    std::cout << "[PASS] CommandScheduler\n";
}
