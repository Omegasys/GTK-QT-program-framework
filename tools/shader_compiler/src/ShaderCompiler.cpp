#include "ShaderCompiler.h"
#include "GLSLParser.h"
#include "ShaderIR.h"
#include "OptimizationPass.h"

#include <iostream>
#include <fstream>

ShaderCompiler::ShaderCompiler() {}

bool ShaderCompiler::compileFile(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cout << "Failed to open shader file\n";
        return false;
    }

    std::string source((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());

    return compileSource(source);
}

bool ShaderCompiler::compileSource(const std::string& source) {
    GLSLParser parser;
    ShaderIR ir = parser.parse(source);

    ShaderIR optimized = optimize(ir);

    // Pretend compilation output
    std::cout << "Compiling Shader IR...\n";
    std::cout << optimized.debugString() << "\n";

    return true;
}

ShaderIR ShaderCompiler::optimize(const ShaderIR& ir) {
    ShaderIR result = ir;

    OptimizationPass pass;
    result = pass.run(result);

    return result;
}
