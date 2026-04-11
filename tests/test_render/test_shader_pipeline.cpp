#include <MyFramework/render/Shader.h>
#include <iostream>

using namespace MyFramework;

void run_shader_tests() {
    std::cout << "[TEST] Shader\n";

    Shader shader;

    bool loaded = shader.load(
        "void main() {}",   // vertex
        "void main() {}"    // fragment
    );

    if (loaded && shader.isLoaded())
        std::cout << "  ✔ Shader loaded successfully\n";
    else
        std::cout << "  ✖ Shader load failed\n";

    shader.bind();
    shader.unbind();

    std::cout << "  ✔ Shader bind/unbind executed\n";
}
