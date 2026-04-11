#pragma once

#include <string>

namespace GQFusion {

/**
 * @brief Represents a compute shader.
 */
class ComputeShader {
public:
    ComputeShader() = default;
    ~ComputeShader();

    // ------------------------------------------------------------
    // Loading
    // ------------------------------------------------------------

    bool loadFromFile(const std::string& path);
    bool loadFromSource(const std::string& source);

    // ------------------------------------------------------------
    // Usage
    // ------------------------------------------------------------

    void bind() const;
    void unbind() const;

    // ------------------------------------------------------------
    // Dispatch
    // ------------------------------------------------------------

    void dispatch(int x, int y, int z) const;

    unsigned int getID() const { return id; }

private:
    unsigned int id = 0;
};

} // namespace GQFusion
