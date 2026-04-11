#include <iostream>
#include <vector>
#include <memory>

/*
 * GraphCanvas
 * ------------------------------------------------------------
 * Responsible for:
 *  - Rendering the full FrameGraph visually
 *  - Managing nodes (passes)
 *  - Handling zoom/pan (future)
 */

class NodeView;

class GraphCanvas {
public:
    GraphCanvas() {
        std::cout << "[GraphCanvas] Created\n";
    }

    void addNode(std::shared_ptr<NodeView> node) {
        nodes.push_back(node);
    }

    void clear() {
        nodes.clear();
    }

    void update() {
        // Future: handle pan/zoom/input
    }

    void draw() {
        std::cout << "[GraphCanvas] Drawing FrameGraph (" 
                  << nodes.size() << " nodes)\n";

        for (auto& node : nodes) {
            node->draw();
        }

        drawConnections();
    }

private:
    void drawConnections() {
        std::cout << "[GraphCanvas] Drawing connections between nodes\n";
        // Future: draw edges between nodes (resources)
    }

private:
    std::vector<std::shared_ptr<NodeView>> nodes;
};
