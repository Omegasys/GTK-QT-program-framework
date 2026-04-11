#include <MyFramework/render/Texture.h>

namespace MyFramework {

Texture::Texture()
    : m_width(0), m_height(0), m_valid(false) {}

bool Texture::loadFromFile(const std::string& path) {
    // Placeholder (real implementation uses image loader)
    m_path = path;
    m_width = 256;
    m_height = 256;
    m_valid = true;
    return true;
}

int Texture::width() const { return m_width; }
int Texture::height() const { return m_height; }

bool Texture::isValid() const { return m_valid; }

} // namespace MyFramework
