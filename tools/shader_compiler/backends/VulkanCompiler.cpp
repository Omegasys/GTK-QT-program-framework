#include <iostream>
#include "../ShaderIR.h"

class VulkanCompiler {
public:
    bool compile(const ShaderIR& ir) {
        std::cout << "[Vulkan] Compiling Shader IR...\n";

        for (const auto& inst : ir.instructions()) {
            std::cout << "  VK_OP: " << inst << "\n";
        }

        std::cout << "[Vulkan] Compilation complete.\n";
        return true;
    }
};
