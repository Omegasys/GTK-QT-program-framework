#include "EditorRenderer.h"
#include "ViewportRenderer.h"
#include "FrameGraphBuilder.h"

#include <iostream>

EditorRenderer::EditorRenderer() {
    std::cout << "[EditorRenderer] Created\n";
}

EditorRenderer::~EditorRenderer() {
    std::cout << "[EditorRenderer] Destroyed\n";
}

void EditorRenderer::initialize() {
    m_viewportRenderer = std::make_unique<ViewportRenderer>();
    m_frameGraphBuilder = std::make_unique<FrameGraphBuilder>();

    m_viewportRenderer->initialize();
}

void EditorRenderer::renderFrame() {
    // Build frame graph
    m_frameGraphBuilder->build();

    // Execute viewport rendering
    m_viewportRenderer->render();

    std::cout << "[EditorRenderer] Frame rendered\n";
}
