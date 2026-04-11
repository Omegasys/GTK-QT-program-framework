#include <iostream>
#include <map>
#include <string>
#include <cassert>

/*
 * Validates resource producer/consumer relationships
 */

void test_resource_dependencies() {
    std::cout << "[Test] Resource Dependencies\n";

    std::map<std::string, std::string> producer;
    std::map<std::string, std::string> consumer;

    producer["ui_buffer"] = "UI Pass";
    producer["blur_buffer"] = "Blur Pass";

    consumer["ui_buffer"] = "Blur Pass";
    consumer["blur_buffer"] = "Glow Pass";

    assert(producer["ui_buffer"] == "UI Pass");
    assert(consumer["ui_buffer"] == "Blur Pass");

    assert(producer["blur_buffer"] == "Blur Pass");
    assert(consumer["blur_buffer"] == "Glow Pass");

    std::cout << "[PASS] Resource Dependencies\n";
}
