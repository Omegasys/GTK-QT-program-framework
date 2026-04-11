#include <GQFusion/utils/Profiler.h>
#include <iostream>
#include <chrono>

namespace GQFusion {

static std::chrono::high_resolution_clock::time_point startTime;

void Profiler::beginFrame() {
    startTime = std::chrono::high_resolution_clock::now();
}

void Profiler::endFrame() {
    auto end = std::chrono::high_resolution_clock::now();

    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - startTime);

    std::cout << "[Profiler] Frame time: "
              << duration.count() / 1000.0f
              << " ms\n";
}

} // namespace GQFusion
