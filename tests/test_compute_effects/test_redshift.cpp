#include <iostream>
#include <cassert>

/*
 * Redshift = time-based color temperature shift
 */

float computeTemperature(float hour) {
    // Simple curve: warm at night, cool at day
    if (hour < 6.0f) return 3000.0f;
    if (hour > 18.0f) return 3200.0f;

    return 6500.0f; // daylight
}

void test_redshift() {
    std::cout << "[Test] Redshift\n";

    float morning = computeTemperature(8.0f);
    float night = computeTemperature(22.0f);

    assert(morning == 6500.0f);
    assert(night < 4000.0f);

    std::cout << "[PASS] Redshift\n";
}
