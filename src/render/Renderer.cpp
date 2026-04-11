#include <GQFusion/render/Renderer.h>
#include <GQFusion/render/rendererbackend.h>
#include <GQFusion/render/RenderTarget.h>
#include <GQFusion/effects/EffectStack.h>

#include <memory>

namespace GQFusion {

// ------------------------------------------------------------
// Singleton
// ------------------------------------------------------------

static Renderer* s_instance = nullptr;

Renderer& Renderer::instance() {
    if (!s_instance) {
        s_instance = new Renderer();
    }
    return *s_instance;
}

// ------------------------------------------------------------
// Lifecycle
// ------------------------------------------------------------

Renderer::Renderer() = default;

Renderer::~Renderer() {
    shutdown();
}

bool Renderer::initialize(std::unique_ptr<RendererBackend> backendImpl,
                          int width,
                          int height) {
    backend = std::move(backendImpl);

    if (!backend || !backend->initialize()) {
        return false;
    }

    viewportWidth = width;
    viewportHeight = height;

    // Create main render target (offscreen buffer)
    mainTarget = std::make_unique<RenderTarget>();
    mainTarget->create(width, height);

    return true;
}

void Renderer::shutdown() {
    if (backend) {
        backend->shutdown();
        backend.reset();
    }

    mainTarget.reset();
}

// ------------------------------------------------------------
// Frame Control
// ------------------------------------------------------------

void Renderer::beginFrame() {
    if (!backend) return;

    backend->beginFrame();

    // Render UI into offscreen target
    if (mainTarget) {
        backend->bindRenderTarget(mainTarget.get());
    }
}

void Renderer::endFrame() {
    if (!backend) return;

    // 🔥 Apply compute-based post-processing
    runComputeEffects();

    backend->endFrame();
    backend->present();
}

// ------------------------------------------------------------
// Drawing
// ------------------------------------------------------------

void Renderer::drawRect(float x, float y, float w, float h) {
    if (!backend) return;
    backend->drawRect(x, y, w, h);
}

// ------------------------------------------------------------
// Compute Effects Pipeline
// ------------------------------------------------------------

void Renderer::runComputeEffects() {
    if (!effectStack || !backend) return;

    const auto& effects = effectStack->getComputeEffects();

    for (const auto& effect : effects) {
        if (!effect) continue;

        void* shader = effect->getComputeShader();
        if (!shader) continue;

        backend->bindComputeShader(shader);

        // Dispatch size based on viewport (rounded up)
        int groupSizeX = (viewportWidth  + 15) / 16;
        int groupSizeY = (viewportHeight + 15) / 16;

        backend->dispatchCompute(groupSizeX, groupSizeY, 1);
    }
}

// ------------------------------------------------------------
// Effect Stack
// ------------------------------------------------------------

void Renderer::setEffectStack(EffectStack* stack) {
    effectStack = stack;
}

// ------------------------------------------------------------
// Resize Handling
// ------------------------------------------------------------

void Renderer::resize(int width, int height) {
    viewportWidth = width;
    viewportHeight = height;

    if (mainTarget) {
        mainTarget->resize(width, height);
    }
}

// ------------------------------------------------------------
// Accessors
// ------------------------------------------------------------

int Renderer::getWidth() const {
    return viewportWidth;
}

int Renderer::getHeight() const {
    return viewportHeight;
}

RendererBackend* Renderer::getBackend() {
    return backend.get();
}

} // namespace GQFusion
