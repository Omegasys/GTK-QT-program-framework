#pragma once

#include <vector>
#include <memory>

namespace GQFusion {

class Widget;

/**
 * @brief Represents a virtualized UI render tree.
 *
 * The RenderTree is a flattened, optimized version of the widget hierarchy
 * used for rendering and culling.
 */
class RenderTree {
public:
    struct Node {
        Widget* widget = nullptr;

        float x = 0.0f;
        float y = 0.0f;
        float width = 0.0f;
        float height = 0.0f;

        bool visible = true;
        bool culled = false;

        int depth = 0;
    };

public:
    RenderTree() = default;
    ~RenderTree() = default;

    // ------------------------------------------------------------
    // Build / Update
    // ------------------------------------------------------------

    /**
     * @brief Rebuild render tree from widget hierarchy.
     */
    void build(Widget* root);

    /**
     * @brief Update layout + visibility states.
     */
    void update();

    /**
     * @brief Clear tree.
     */
    void clear();

    // ------------------------------------------------------------
    // Query
    // ------------------------------------------------------------

    const std::vector<Node>& getNodes() const;

    /**
     * @brief Get only visible nodes (after culling).
     */
    std::vector<const Node*> getVisibleNodes() const;

private:
    void traverse(Widget* widget, int depth);

    void cull();

private:
    std::vector<Node> nodes;
};

} // namespace GQFusion
