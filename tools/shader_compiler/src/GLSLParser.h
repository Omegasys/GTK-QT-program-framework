#pragma once

#include <string>

class ShaderIR;

class GLSLParser {
public:
    ShaderIR parse(const std::string& source);
};
