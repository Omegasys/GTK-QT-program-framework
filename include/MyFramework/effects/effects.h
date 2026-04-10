#pragma once

#include <vector>
#include <memory>

#include <MyFramework/config/ConfigTypes.h>
#include <MyFramework/theme/Theme.h>
#include <MyFramework/render/render.h>

namespace MyFramework {

class Window;
class Widget;

/**
 * @brief Base class for all visual effects.
 */
class Effect {
public:
    virtual ~Effect() = default;

    /**
     * @brief Updates effect state per frame.
     */
    virtual void update(float deltaTime) = 0;

    /**
     * @brief Applies the effect during rendering.
     */
    virtual void apply(Renderer& renderer, Window* window) = 0;

    /**
     * @brief Returns whether the effect is finished.
     */
    virtual bool isFinished() const { return false; }
};

/**
 * @brief Smooth fade in/out effect.
 */
class FadeEffect : public Effect {
public:
    FadeEffect(float startOpacity, float targetOpacity, float duration);

    void update(float deltaTime) override;
    void apply(Renderer& renderer, Window* window) override;

    bool isFinished() const override;

private:
    float m_startOpacity;
    float m_targetOpacity;
    float m_currentOpacity;
    float m_duration;
    float m_elapsed;
};

/**
 * @brief Blur effect applied to windows.
 */
class BlurEffect : public Effect {
public:
    explicit BlurEffect(float targetBlur, float duration = 0.0f);

    void update(float deltaTime) override;
    void apply(Renderer& renderer, Window* window) override;

    bool isFinished() const override;

private:
    float m_blur;
    float m_targetBlur;
    float m_duration;
    float m_elapsed;
};

/**
 * @brief Window shadow effect based on theme.
 */
class ShadowEffect : public Effect {
public:
    ShadowEffect(const Theme& theme);

    void update(float deltaTime) override;
    void apply(Renderer& renderer, Window* window) override;

private:
    Theme m_theme;
};

/**
 * @brief Rounded corner effect for windows/widgets.
 */
class CornerRadiusEffect : public Effect {
public:
    explicit CornerRadiusEffect(float radius);

    void update(float deltaTime) override;
    void apply(Renderer& renderer, Window* window) override;

private:
    float m_radius;
};

/**
 * @brief Manages multiple effects on a single object.
 */
class EffectStack {
public:
    /**
     * @brief Adds a new effect.
     */
    void add(std::unique_ptr<Effect> effect);

    /**
     * @brief Updates all effects.
     */
    void update(float deltaTime);

    /**
     * @brief Applies all effects.
     */
    void apply(Renderer& renderer, Window* window);

    /**
     * @brief Removes finished effects.
     */
    void cleanup();

    /**
     * @brief Clears all effects.
     */
    void clear();

private:
    std::vector<std::unique_ptr<Effect>> m_effects;
};

/**
 * @brief High-level effects manager for the framework.
 */
class EffectsManager {
public:
    EffectsManager();

    /**
     * @brief Registers a window to receive effects.
     */
    void registerWindow(Window* window);

    /**
     * @brief Unregisters a window.
     */
    void unregisterWindow(Window* window);

    /**
     * @brief Updates all effects globally.
     */
    void update(float deltaTime);

    /**
     * @brief Applies effects during rendering.
     */
    void apply(Renderer& renderer);

    /**
     * @brief Applies theme-based effects automatically.
     */
    void applyThemeEffects(Window* window, const Theme& theme);

private:
    std::unordered_map<Window*, EffectStack> m_windowEffects;
};

} // namespace MyFramework
