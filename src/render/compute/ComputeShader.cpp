#include "ComputeShader.h"
#include <fstream>
#include <sstream>
#include <GL/gl.h>

bool ComputeShader::loadFromFile(const std::string& path) {
    std::ifstream file(path);
    std::stringstream ss;
    ss << file.rdbuf();

    std::string src = ss.str();
    const char* code = src.c_str();

    id = glCreateShader(GL_COMPUTE_SHADER);
    glShaderSource(id, 1, &code, nullptr);
    glCompileShader(id);

    return true;
}

void ComputeShader::bind() {
    glUseProgram(id);
}
