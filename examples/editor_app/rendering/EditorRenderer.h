#pragma once

#include <memory>

class ViewportRenderer;
class FrameGraphBuilder;

/*
 * EditorRenderer
 * ------------------------------------------------------------
 * High-level renderer orchestrating all editor rendering.
 */

class EditorRenderer {
public:
    EditorRenderer();
    ~EditorRenderer();

    void initialize();
    void renderFrame();

private:
    std::unique_ptr<ViewportRenderer> m_viewportRenderer;
    std::unique_ptr<FrameGraphBuilder> m_frameGraphBuilder;
};
