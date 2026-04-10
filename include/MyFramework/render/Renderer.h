#pragma once

#include <vector>
#include <memory>

#include <MyFramework/render/DrawCommand.h>
#include <MyFramework/render/RendererBackend.h>
#include <MyFramework/render/RenderTarget.h>
#include <MyFramework/utils/Color.h>

namespace MyFramework {

class Window;
class Widget;

/**
 * @brief Main rendering engine.
 *
 * Responsibilities:
 * - Collect draw commands
 * - Manage frame lifecycle
 * - Interface with backend
 */
class Renderer {
public:
    Renderer();
    ~Renderer();

    /**
     * @brief Sets rendering backend.
     */
    void setBackend(std::unique_ptr<RendererBackend> backend);

    /**
     * @brief Begins a new frame.
     */
    void begin(Window* window, RenderTarget* target);

    /**
     * @brief Ends frame and flushes to backend.
     */
    void end();

    /**
     * @brief Draw rectangle.
     */
    void drawRect(float x, float y, float w, float h, const Color& color);

    /**
     * @brief Draw rounded rectangle.
     */
    void drawRoundedRect(float x, float y, float w, float h, float radius, const Color& color);

    /**
     * @brief Draw text.
     */
    void drawText(float x, float y, const std::string& text, const Color& color);

    /**
     * @brief Recursively render widget tree.
     */
    void drawWidgetTree(Widget* root);

    /**
     * @brief Gets current render target.
     */
    RenderTarget* currentTarget() const;

    /**
     * @brief Clears screen.
     */
    void clear(const Color& color);

private:
    /**
     * @brief Sends commands to backend.
     */
    void flush();

    /**
     * @brief Recursive widget rendering.
     */
    void renderWidget(Widget* widget);

private:
    std::unique_ptr<RendererBackend> m_backend;

    std::vector<DrawCommand> m_commands;

    RenderTarget* m_target;
    Window* m_window;
};

} // namespace MyFramework
