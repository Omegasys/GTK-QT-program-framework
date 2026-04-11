#pragma once

#include <memory>

namespace GQFusion {

class ComputeShader;

/**
 * @brief Soft shadow effect using compute shaders.
 */
class ShadowComputeEffect {
public:
    ShadowComputeEffect();
    ~ShadowComputeEffect() = default;

    // ------------------------------------------------------------
    // Setup
    // ------------------------------------------------------------

    bool initialize(const std::string& shaderPath);

    // ------------------------------------------------------------
    // Usage
    // ------------------------------------------------------------

    void apply();

    void* getComputeShader() const;

    // ------------------------------------------------------------
    // Parameters
    // ------------------------------------------------------------

    void setOffset(float x, float y);
    void getOffset(float& x, float& y) const;

    void setBlur(float value);
    float getBlur() const;

    void setOpacity(float value);
    float getOpacity() const;

private:
    std::shared_ptr<ComputeShader> shader;

    float offsetX = 5.0f;
    float offsetY = 5.0f;

    float blur = 4.0f;
    float opacity = 0.5f;
};

} // namespace GQFusion
