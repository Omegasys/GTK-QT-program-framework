#pragma once

#include <memory>

namespace GQFusion {

class ComputeShader;

/**
 * @brief GPU-based blur effect using compute shaders.
 */
class BlurComputeEffect {
public:
    BlurComputeEffect();
    ~BlurComputeEffect() = default;

    // ------------------------------------------------------------
    // Setup
    // ------------------------------------------------------------

    /**
     * @brief Initialize the effect (load shader).
     */
    bool initialize(const std::string& shaderPath);

    // ------------------------------------------------------------
    // Usage
    // ------------------------------------------------------------

    void apply();

    /**
     * @brief Get raw shader handle for backend dispatch.
     */
    void* getComputeShader() const;

    // ------------------------------------------------------------
    // Parameters
    // ------------------------------------------------------------

    void setRadius(float r);
    float getRadius() const;

private:
    std::shared_ptr<ComputeShader> shader;

    float radius = 5.0f;
};

} // namespace GQFusion
