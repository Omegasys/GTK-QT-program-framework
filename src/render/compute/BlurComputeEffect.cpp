#include "BlurComputeEffect.h"
#include <MyFramework/render/Renderer.h>

void BlurComputeEffect::apply() {
    shader.bind();

    // dispatch compute work groups
    Renderer::instance().dispatchCompute(16, 16, 1);
}
