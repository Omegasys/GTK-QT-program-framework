#include <GQFusion/framegraph/FramePass.h>
#include <GQFusion/framegraph/FrameResource.h>
#include <iostream>

namespace GQFusion {

FramePass::FramePass(const std::string& name)
    : name(name) {}

void FramePass::addInput(FrameResource* resource) {
    inputs.push_back(resource);
}

void FramePass::addOutput(FrameResource* resource) {
    outputs.push_back(resource);
}

void FramePass::execute() {
    std::cout << "[FramePass] Executing: " << name << "\n";

    // Placeholder: real implementation binds GPU resources
    for (auto* r : inputs) {
        (void)r;
    }

    for (auto* r : outputs) {
        (void)r;
    }
}

const std::string& FramePass::getName() const {
    return name;
}

} // namespace GQFusion
