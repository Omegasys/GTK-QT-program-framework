#include <GQFusion/effects/compute/RedshiftEffect.h>
#include <GQFusion/render/compute/ComputeShader.h>
#include <iostream>

namespace GQFusion {

bool RedshiftEffect::initialize(const std::string& shaderPath) {
    std::cout << "[RedshiftEffect] Loading shader: " << shaderPath << "\n";

    shader = std::make_shared<ComputeShader>();
    return true;
}

void RedshiftEffect::apply() {
    if (!shader) return;

    std::cout << "[RedshiftEffect] Applying temperature: "
              << temperature << "\n";
}

void* RedshiftEffect::getComputeShader() const {
    return shader.get();
}

void RedshiftEffect::setTemperature(float value) {
    temperature = value;
}

float RedshiftEffect::getTemperature() const {
    return temperature;
}

void RedshiftEffect::setTint(float r, float g, float b) {
    tintR = r;
    tintG = g;
    tintB = b;
}

} // namespace GQFusion
