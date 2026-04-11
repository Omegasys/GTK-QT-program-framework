#include "ShaderIR.h"
#include <sstream>

void ShaderIR::addInstruction(const std::string& inst) {
    ops.push_back(inst);
}

const std::vector<std::string>& ShaderIR::instructions() const {
    return ops;
}

std::string ShaderIR::debugString() const {
    std::stringstream ss;

    ss << "ShaderIR:\n";
    for (auto& op : ops) {
        ss << "  " << op << "\n";
    }

    return ss.str();
}
