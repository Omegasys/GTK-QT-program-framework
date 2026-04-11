#pragma once

#include <string>

namespace GQFusion {

/**
 * @brief Represents a GPU texture.
 */
class Texture {
public:
    Texture() = default;
    ~Texture();

    // ------------------------------------------------------------
    // Creation
    // ------------------------------------------------------------

    bool loadFromFile(const std::string& path);
    bool create(int width, int height);

    // ------------------------------------------------------------
    // Binding
    // ------------------------------------------------------------

    void bind(unsigned int slot = 0) const;
    void unbind() const;

    // ------------------------------------------------------------
    // Info
    // ------------------------------------------------------------

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    unsigned int getID() const { return id; }

private:
    unsigned int id = 0;
    int width = 0;
    int height = 0;
};

} // namespace GQFusion
