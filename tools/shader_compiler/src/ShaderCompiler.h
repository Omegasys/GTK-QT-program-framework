#pragma once

#include <string>

class ShaderIR;

class ShaderCompiler {
public:
    ShaderCompiler();

    bool compileFile(const std::string& path);
    bool compileSource(const std::string& source);

private:
    ShaderIR optimize(const ShaderIR& ir);
};
