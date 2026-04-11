#include <MyFramework/render/Shader.h>

namespace MyFramework {

Shader::Shader()
    : m_loaded(false) {}

bool Shader::load(const std::string& vertexSrc, const std::string& fragmentSrc) {
    // Placeholder: store strings
    m_vertexSource = vertexSrc;
    m_fragmentSource = fragmentSrc;
    m_loaded = true;
    return true;
}

void Shader::bind() {
    if (!m_loaded) return;
    // In real backend: glUseProgram / vkBindPipeline
}

void Shader::unbind() {
    // Placeholder
}

bool Shader::isLoaded() const {
    return m_loaded;
}

} // namespace MyFramework
