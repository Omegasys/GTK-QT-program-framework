#include "RenderDebugOverlay.h"

#include <MyFramework/render/Renderer.h>
#include <MyFramework/utils/Logger.h>

using namespace MyFramework;

RenderDebugOverlay::RenderDebugOverlay(Window* parent)
    : Widget(parent) {}

void RenderDebugOverlay::update() {
    // Debug rendering overlay

    // Example stats (placeholder)
    int fps = 60;
    int drawCalls = 42;

    Logger::info("FPS: " + std::to_string(fps) +
                 " DrawCalls: " + std::to_string(drawCalls));
}
