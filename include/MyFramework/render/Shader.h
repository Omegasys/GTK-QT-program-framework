#pragma once

#include <string>

namespace GQFusion {

/**
 * @brief Represents a GPU shader program (vertex + fragment).
 */
class Shader {
public:
    Shader() = default;
    ~Shader();

    // ------------------------------------------------------------
    // Loading
    // ------------------------------------------------------------

    bool loadFromFiles(const std::string& vertexPath,
                       const std::string& fragmentPath);

    bool loadFromSource(const std::string& vertexSrc,
                        const std::string& fragmentSrc);

    // ------------------------------------------------------------
    // Usage
    // ------------------------------------------------------------

    void bind() const;
    void unbind() const;

    // ------------------------------------------------------------
    // Uniforms
    // ------------------------------------------------------------

    void setFloat(const std::string& name, float value);
    void setInt(const std::string& name, int value);

    unsigned int getID() const { return id; }

private:
    unsigned int id = 0;
};

} // namespace GQFusion
