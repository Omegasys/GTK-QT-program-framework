#pragma once

#include <string>
#include <vector>

class ShaderIR {
public:
    void addInstruction(const std::string& inst);

    const std::vector<std::string>& instructions() const;

    std::string debugString() const;

private:
    std::vector<std::string> ops;
};
