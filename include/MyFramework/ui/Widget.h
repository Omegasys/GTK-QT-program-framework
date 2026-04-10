#pragma once

#include <string>
#include <vector>
#include <memory>

#include <MyFramework/core/Object.h>
#include <MyFramework/core/Event.h>
#include <MyFramework/render/Renderer.h>

namespace MyFramework {

class Layout;
class EffectStack;

/**
 * @brief Base UI element for all visible components.
 *
 * Widgets are:
 * - Renderable
 * - Event-aware
 * - Layout-compatible
 * - Effect-enabled
 */
class Widget : public Object {
public:
    explicit Widget(Object* parent = nullptr);
    virtual ~Widget();

    // =========================
    // Geometry
    // =========================
    void setPosition(float x, float y);
    void setSize(float width, float height);

    float x() const;
    float y() const;
    float width() const;
    float height() const;

    // =========================
    // Visibility
    // =========================
    void setVisible(bool visible);
    bool isVisible() const;

    void setEnabled(bool enabled);
    bool isEnabled() const;

    // =========================
    // Rendering
    // =========================

    /**
     * @brief Called every frame by Renderer.
     */
    virtual void render(Renderer& renderer);

    /**
     * @brief Internal render pipeline hook.
     */
    virtual void paint(Renderer& renderer);

    // =========================
    // Event handling
    // =========================

    /**
     * @brief Main event entry point.
     */
    virtual bool handleEvent(Event& event);

    virtual bool onMouseMove(Event& event);
    virtual bool onMousePress(Event& event);
    virtual bool onMouseRelease(Event& event);
    virtual bool onKeyPress(Event& event);
    virtual bool onKeyRelease(Event& event);

    // =========================
    // Layout
    // =========================

    void setLayout(Layout* layout);
    Layout* layout() const;

    /**
     * @brief Requests layout update.
     */
    void updateLayout();

    // =========================
    // Effects
    // =========================

    void setEffectStack(EffectStack* stack);
    EffectStack* effectStack() const;

    // =========================
    // Hierarchy overrides
    // =========================

    void addChild(Widget* child);
    void removeChild(Widget* child);

protected:
    // Geometry
    float m_x;
    float m_y;
    float m_width;
    float m_height;

    // State
    bool m_visible;
    bool m_enabled;

    // Layout system
    Layout* m_layout;

    // Effects system
    EffectStack* m_effectStack;

    // Rendering cache/state
    bool m_needsRedraw;
};

} // namespace MyFramework
