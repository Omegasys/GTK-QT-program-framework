#include <GQFusion/framegraph/FrameExecutor.h>
#include <GQFusion/framegraph/FrameGraph.h>

namespace GQFusion {

void FrameExecutor::execute(FrameGraph& graph) {
    executePasses(graph);
}

void FrameExecutor::executePasses(FrameGraph& graph) {
    graph.execute();
}

} // namespace GQFusion
