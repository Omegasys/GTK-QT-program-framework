#pragma once

#include <memory>

namespace GQFusion {

class ComputeShader;

/**
 * @brief GPU-based color grading / redshift effect.
 *
 * Used for:
 * - Warm/cool transitions
 * - Time-of-day simulation
 * - Theme blending
 */
class RedshiftEffect {
public:
    RedshiftEffect() = default;
    ~RedshiftEffect() = default;

    // ------------------------------------------------------------
    // Initialization
    // ------------------------------------------------------------

    bool initialize(const std::string& shaderPath);

    // ------------------------------------------------------------
    // Execution
    // ------------------------------------------------------------

    void apply();
    void* getComputeShader() const;

    // ------------------------------------------------------------
    // Parameters
    // ------------------------------------------------------------

    void setTemperature(float value); // -1 (cool) → +1 (warm)
    float getTemperature() const;

    void setTint(float r, float g, float b);

private:
    std::shared_ptr<ComputeShader> shader;

    float temperature = 0.0f;
    float tintR = 1.0f;
    float tintG = 1.0f;
    float tintB = 1.0f;
};

} // namespace GQFusion
