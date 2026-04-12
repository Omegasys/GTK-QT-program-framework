#include "EditorAPI.h"
#include <iostream>

namespace gqf {

void EditorAPI::log(const std::string& message) {
    std::cout << "[Lua] " << message << "\n";
}

void EditorAPI::createObject(const std::string& type) {
    std::cout << "[EditorAPI] Create object: " << type << "\n";
}

void EditorAPI::deleteObject(int id) {
    std::cout << "[EditorAPI] Delete object id: " << id << "\n";
}

void EditorAPI::setObjectPosition(int id, float x, float y, float z) {
    std::cout << "[EditorAPI] Move object " << id
              << " to " << x << "," << y << "," << z << "\n";
}

void EditorAPI::setTheme(const std::string& themeName) {
    std::cout << "[EditorAPI] Switch theme: " << themeName << "\n";
}

} // namespace gqf
