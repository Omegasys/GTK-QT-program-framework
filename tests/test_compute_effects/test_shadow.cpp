#include <iostream>
#include <cassert>

/*
 * Shadow = intensity attenuation
 */

void test_shadow() {
    std::cout << "[Test] Shadow Effect\n";

    float light = 1.0f;
    float occlusion = 0.3f;

    float shadowed = light * (1.0f - occlusion);

    assert(shadowed == 0.7f);

    std::cout << "[PASS] Shadow\n";
}
