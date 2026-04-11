#include "GLSLParser.h"
#include "ShaderIR.h"

#include <sstream>

ShaderIR GLSLParser::parse(const std::string& source) {
    ShaderIR ir;

    std::stringstream ss(source);
    std::string line;

    while (std::getline(ss, line)) {
        if (line.find("vec") != std::string::npos) {
            ir.addInstruction("VECTOR_OP: " + line);
        } else if (line.find("void") != std::string::npos) {
            ir.addInstruction("FUNCTION: " + line);
        } else {
            ir.addInstruction("GENERIC: " + line);
        }
    }

    return ir;
}
