#include <iostream>
#include <memory>

#include <GQFusion/framegraph/FrameGraph.h>
#include <GQFusion/framegraph/FrameExecutor.h>
#include <GQFusion/framegraph/FramePass.h>
#include <GQFusion/framegraph/FrameResource.h>

using namespace GQFusion;

int main() {
    std::cout << "[FrameGraph Demo] Starting...\n";

    FrameGraph graph;
    FrameExecutor executor;

    // ------------------------------------------------------------
    // Create passes
    // ------------------------------------------------------------
    auto uiPass = std::make_shared<FramePass>("UI Pass");
    auto blurPass = std::make_shared<FramePass>("Blur Pass");
    auto glowPass = std::make_shared<FramePass>("Glow Pass");
    auto compositePass = std::make_shared<FramePass>("Composite Pass");

    // ------------------------------------------------------------
    // Dummy resources
    // ------------------------------------------------------------
    FrameResource uiBuffer;
    FrameResource blurBuffer;
    FrameResource glowBuffer;
    FrameResource finalBuffer;

    uiPass->addOutput(&uiBuffer);

    blurPass->addInput(&uiBuffer);
    blurPass->addOutput(&blurBuffer);

    glowPass->addInput(&blurBuffer);
    glowPass->addOutput(&glowBuffer);

    compositePass->addInput(&glowBuffer);
    compositePass->addOutput(&finalBuffer);

    // ------------------------------------------------------------
    // Build graph
    // ------------------------------------------------------------
    graph.addPass(uiPass);
    graph.addPass(blurPass);
    graph.addPass(glowPass);
    graph.addPass(compositePass);

    // ------------------------------------------------------------
    // Execute frame graph
    // ------------------------------------------------------------
    executor.execute(graph);

    std::cout << "[FrameGraph Demo] Done.\n";
    return 0;
}
