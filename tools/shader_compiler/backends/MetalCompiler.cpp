#include <iostream>
#include "../ShaderIR.h"

class MetalCompiler {
public:
    bool compile(const ShaderIR& ir) {
        std::cout << "[Metal] Compiling Shader IR...\n";

        for (const auto& inst : ir.instructions()) {
            std::cout << "  MT_OP: " << inst << "\n";
        }

        std::cout << "[Metal] Compilation complete.\n";
        return true;
    }
};
