#include <iostream>
#include "../ShaderIR.h"

class OpenGLCompiler {
public:
    bool compile(const ShaderIR& ir) {
        std::cout << "[OpenGL] Compiling Shader IR...\n";

        for (const auto& inst : ir.instructions()) {
            std::cout << "  GL_OP: " << inst << "\n";
        }

        std::cout << "[OpenGL] Compilation complete.\n";
        return true;
    }
};
