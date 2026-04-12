#pragma once

#include <string>

namespace gqf {

/// Safe API exposed to Lua scripts
class EditorAPI {
public:
    void log(const std::string& message);

    void createObject(const std::string& type);
    void deleteObject(int id);

    void setObjectPosition(int id, float x, float y, float z);

    void setTheme(const std::string& themeName);
};

} // namespace gqf
