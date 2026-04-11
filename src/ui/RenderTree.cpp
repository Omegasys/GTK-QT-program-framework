#include <GQFusion/ui/RenderTree.h>
#include <GQFusion/ui/Widget.h>

#include <queue>

namespace GQFusion {

void RenderTree::build(Widget* root) {
    nodes.clear();
    if (!root) return;

    traverse(root, 0);
    cull();
}

void RenderTree::update() {
    cull();
}

void RenderTree::clear() {
    nodes.clear();
}

const std::vector<RenderTree::Node>& RenderTree::getNodes() const {
    return nodes;
}

std::vector<const RenderTree::Node*> RenderTree::getVisibleNodes() const {
    std::vector<const Node*> result;

    for (const auto& n : nodes) {
        if (n.visible && !n.culled) {
            result.push_back(&n);
        }
    }

    return result;
}

// ------------------------------------------------------------
// Internal traversal
// ------------------------------------------------------------

void RenderTree::traverse(Widget* widget, int depth) {
    if (!widget) return;

    Node node;
    node.widget = widget;
    node.depth = depth;

    node.x = widget->getX();
    node.y = widget->getY();
    node.width = widget->getWidth();
    node.height = widget->getHeight();
    node.visible = widget->isVisible();

    nodes.push_back(node);

    for (auto* child : widget->getChildren()) {
        traverse(child, depth + 1);
    }
}

// ------------------------------------------------------------
// Simple culling (placeholder AABB logic)
// ------------------------------------------------------------

void RenderTree::cull() {
    for (auto& node : nodes) {
        if (!node.visible) {
            node.culled = true;
            continue;
        }

        // Basic screen-space culling placeholder
        if (node.width <= 0 || node.height <= 0) {
            node.culled = true;
        } else {
            node.culled = false;
        }
    }
}

} // namespace GQFusion
