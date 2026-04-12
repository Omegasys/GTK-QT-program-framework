#pragma once

#include <string>
#include <memory>

struct lua_State;

namespace gqf {

class EditorAPI;

/// Core Lua scripting engine
class ScriptEngine {
public:
    ScriptEngine();
    ~ScriptEngine();

    bool initialize();
    void shutdown();

    bool executeFile(const std::string& path);
    bool executeString(const std::string& code);

    void update(float deltaTime);

    lua_State* getState();

    void setEditorAPI(std::shared_ptr<EditorAPI> api);

private:
    lua_State* m_luaState = nullptr;
    std::shared_ptr<EditorAPI> m_editorAPI;
};

} // namespace gqf
