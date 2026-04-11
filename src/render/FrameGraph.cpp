#include <GQFusion/render/FrameGraph.h>
#include <iostream>

namespace GQFusion {

void FrameGraph::addPass(const std::shared_ptr<FramePass>& pass) {
    passes.push_back(pass);
}

void FrameGraph::execute() {
    for (auto& pass : passes) {
        executePass(pass);
    }
}

void FrameGraph::clear() {
    passes.clear();
}

void FrameGraph::printGraph() const {
    std::cout << "[FrameGraph] Passes:\n";
    for (const auto& p : passes) {
        std::cout << " - " << p->getName() << "\n";
    }
}

void FrameGraph::executePass(const std::shared_ptr<FramePass>& pass) {
    if (pass) {
        pass->execute();
    }
}

} // namespace GQFusion
