#include <GQFusion/render/backends/OpenGLBackend.h>
#include <GQFusion/render/RenderTarget.h>

#include <GL/gl.h>
#include <iostream>

namespace GQFusion {

// ------------------------------------------------------------
// Lifecycle
// ------------------------------------------------------------

bool OpenGLBackend::initialize() {
    std::cout << "[OpenGL] Initialize backend\n";

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return true;
}

void OpenGLBackend::shutdown() {
    std::cout << "[OpenGL] Shutdown backend\n";
}

// ------------------------------------------------------------
// Frame
// ------------------------------------------------------------

void OpenGLBackend::beginFrame() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLBackend::endFrame() {
    // nothing required
}

void OpenGLBackend::present() {
    glFlush();
}

// ------------------------------------------------------------
// Rendering
// ------------------------------------------------------------

void OpenGLBackend::drawRect(float x, float y, float w, float h) {
    // Simple immediate-mode (placeholder)
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y + h);
        glVertex2f(x, y + h);
    glEnd();
}

// ------------------------------------------------------------
// Render Target
// ------------------------------------------------------------

void OpenGLBackend::bindRenderTarget(RenderTarget* target) {
    if (!target) return;

    // TODO: bind FBO
    // glBindFramebuffer(GL_FRAMEBUFFER, target->getFBO());
}

// ------------------------------------------------------------
// Compute
// ------------------------------------------------------------

void OpenGLBackend::bindComputeShader(void* shader) {
    if (!shader) return;

    GLuint program = static_cast<GLuint>(reinterpret_cast<uintptr_t>(shader));
    glUseProgram(program);
}

void OpenGLBackend::dispatchCompute(int x, int y, int z) {
    glDispatchCompute(x, y, z);

    // Ensure writes complete before next stage
    glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
}

} // namespace GQFusion
