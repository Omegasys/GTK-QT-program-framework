#include "ShaderCompiler.h"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: shader_compiler <file.glsl>\n";
        return 1;
    }

    std::string path = argv[1];

    ShaderCompiler compiler;

    if (!compiler.compileFile(path)) {
        std::cout << "Shader compilation failed.\n";
        return 1;
    }

    std::cout << "Shader compiled successfully.\n";
    return 0;
}
