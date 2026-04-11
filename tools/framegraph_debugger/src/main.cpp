#include <iostream>

// Forward declarations (simple linkage style for now)
class FrameGraphViewer;
class PassInspector;
class ResourceTracker;
class ExecutionTimeline;

#include "FrameGraphViewer.cpp"
#include "PassInspector.cpp"
#include "ResourceTracker.cpp"
#include "ExecutionTimeline.cpp"

int main() {
    std::cout << "[FrameGraphDebugger] Starting...\n";

    FrameGraphViewer viewer;
    PassInspector inspector;
    ResourceTracker tracker;
    ExecutionTimeline timeline;

    // ------------------------------------------------------------
    // Simulated update loop
    // ------------------------------------------------------------
    for (int frame = 0; frame < 3; frame++) {
        std::cout << "\n[Frame " << frame << "]\n";

        viewer.buildGraph();
        tracker.captureResources();
        timeline.record(frame);

        viewer.draw();
        inspector.inspect("Glow Pass");
        tracker.draw();
        timeline.draw();
    }

    std::cout << "[FrameGraphDebugger] Shutdown\n";
    return 0;
}
