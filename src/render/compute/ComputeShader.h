#pragma once
#include <string>

class ComputeShader {
public:
    bool loadFromFile(const std::string& path);
    void bind();

private:
    unsigned int id = 0;
};
