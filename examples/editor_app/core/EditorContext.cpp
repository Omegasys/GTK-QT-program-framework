#include "EditorContext.h"

#include <fstream>
#include <iostream>
#include <sstream>

EditorContext::EditorContext() {
    std::cout << "[EditorContext] Created\n";
}

bool EditorContext::loadConfig(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "[EditorContext] Failed to open config: " << path << "\n";
        return false;
    }

    std::cout << "[EditorContext] Loading config...\n";

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key, value;

        if (std::getline(iss, key, '=') && std::getline(iss, value)) {
            m_config[key] = value;
        }
    }

    return true;
}

const std::string& EditorContext::getValue(const std::string& key) const {
    static std::string empty;
    auto it = m_config.find(key);
    return (it != m_config.end()) ? it->second : empty;
}
