#include <GQFusion/render/compute/ComputeDispatcher.h>
#include <GQFusion/render/compute/ComputeShader.h>
#include <iostream>

namespace GQFusion {

void ComputeDispatcher::addDispatch(const DispatchCommand& cmd) {
    queue.push_back(cmd);
}

void ComputeDispatcher::clear() {
    queue.clear();
}

void ComputeDispatcher::dispatch(ComputeShader* shader, int x, int y, int z) {
    queue.push_back({ shader, x, y, z });
}

void ComputeDispatcher::execute() {
    for (const auto& cmd : queue) {
        if (!cmd.shader) continue;

        std::cout << "[ComputeDispatcher] Dispatching compute shader\n";
        std::cout << " Groups: " << cmd.groupsX
                  << "," << cmd.groupsY
                  << "," << cmd.groupsZ << "\n";
    }

    queue.clear();
}

} // namespace GQFusion
