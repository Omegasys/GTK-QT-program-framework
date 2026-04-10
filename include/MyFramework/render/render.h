#pragma once

#include <string>
#include <vector>
#include <memory>

#include <MyFramework/config/ConfigTypes.h>
#include <MyFramework/theme/Theme.h>

namespace MyFramework {

// Forward declarations
class Window;
class Widget;

/**
 * @brief Primitive drawing commands.
 *
 * These are sent to the backend renderer.
 */
enum class DrawCommandType {
    Rect,
    Text,
    Image,
    RoundedRect,
    Line
};

/**
 * @brief A single render command.
 */
struct DrawCommand {
    DrawCommandType type;

    // Position and size
    float x = 0;
    float y = 0;
    float width = 0;
    float height = 0;

    // Optional color
    Color color;

    // Optional text (for Text commands)
    std::string text;

    // Optional rounding
    float radius = 0.0f;

    // Layer for ordering
    int zIndex = 0;
};

/**
 * @brief Frame buffer abstraction (for future GPU backend support).
 */
class RenderTarget {
public:
    virtual ~RenderTarget() = default;

    virtual int width() const = 0;
    virtual int height() const = 0;

    virtual void clear(const Color& color) = 0;
};

/**
 * @brief Abstract renderer backend interface.
 *
 * Implement this for:
 * - OpenGL
 * - Vulkan
 * - DirectX
 * - Software renderer
 */
class RendererBackend {
public:
    virtual ~RendererBackend() = default;

    /**
     * @brief Submit a batch of draw commands.
     */
    virtual void submit(const std::vector<DrawCommand>& commands) = 0;

    /**
     * @brief Presents the rendered frame to the screen.
     */
    virtual void present() = 0;

    /**
     * @brief Begins a new frame.
     */
    virtual void beginFrame(RenderTarget* target) = 0;

    /**
     * @brief Ends the current frame.
     */
    virtual void endFrame() = 0;
};

/**
 * @brief Main rendering engine used by the framework.
 */
class Renderer {
public:
    Renderer();
    ~Renderer();

    /**
     * @brief Sets backend implementation.
     */
    void setBackend(std::unique_ptr<RendererBackend> backend);

    /**
     * @brief Begins rendering a window frame.
     */
    void begin(Window* window);

    /**
     * @brief Ends rendering and flushes to backend.
     */
    void end();

    /**
     * @brief Draws a rectangle.
     */
    void drawRect(float x, float y, float w, float h, const Color& color);

    /**
     * @brief Draws a rounded rectangle.
     */
    void drawRoundedRect(float x, float y, float w, float h, float radius, const Color& color);

    /**
     * @brief Draws text.
     */
    void drawText(float x, float y, const std::string& text, const Color& color);

    /**
     * @brief Draws a widget tree.
     */
    void drawWidgetTree(Widget* root);

    /**
     * @brief Gets current render target.
     */
    RenderTarget* currentTarget() const;

    /**
     * @brief Clears screen with theme background.
     */
    void clearWithTheme(const Theme& theme);

private:
    /**
     * @brief Flushes command buffer to backend.
     */
    void flush();

    /**
     * @brief Recursively renders widgets.
     */
    void renderWidget(Widget* widget);

private:
    std::unique_ptr<RendererBackend> m_backend;
    std::vector<DrawCommand> m_commandBuffer;

    RenderTarget* m_target;
    Window* m_currentWindow;
};

} // namespace MyFramework
