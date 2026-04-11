#include "ShaderIR.h"

class OptimizationPass {
public:
    ShaderIR run(const ShaderIR& input) {
        ShaderIR out = input;

        // Fake optimization: remove empty lines / no-ops
        ShaderIR optimized;

        for (auto& inst : input.instructions()) {
            if (!inst.empty()) {
                optimized.addInstruction("OPT: " + inst);
            }
        }

        return optimized;
    }
};
