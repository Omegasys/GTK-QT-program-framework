#pragma once

#include <memory>

namespace GQFusion {

class ComputeShader;

/**
 * @brief Glow/Bloom effect using compute shaders.
 */
class GlowComputeEffect {
public:
    GlowComputeEffect();
    ~GlowComputeEffect() = default;

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

    void setIntensity(float value);
    float getIntensity() const;

    void setThreshold(float value);
    float getThreshold() const;

private:
    std::shared_ptr<ComputeShader> shader;

    float intensity = 1.0f;
    float threshold = 0.8f;
};

} // namespace GQFusion
