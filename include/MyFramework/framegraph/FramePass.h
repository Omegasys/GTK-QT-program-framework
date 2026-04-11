#pragma once

#include <string>
#include <vector>

namespace GQFusion {

class FrameResource;

/**
 * @brief Single render or compute pass in the frame graph.
 */
class FramePass {
public:
    FramePass(const std::string& name);

    void addInput(FrameResource* resource);
    void addOutput(FrameResource* resource);

    void execute();

    const std::string& getName() const;

private:
    std::string name;

    std::vector<FrameResource*> inputs;
    std::vector<FrameResource*> outputs;
};

} // namespace GQFusion
