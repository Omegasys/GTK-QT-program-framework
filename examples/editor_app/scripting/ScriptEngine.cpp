#include "ScriptEngine.h"
#include "EditorAPI.h"
#include "LuaBindings.h"

#include <iostream>

// Lua headers (assumes Lua installed)
extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

namespace gqf {

ScriptEngine::ScriptEngine() = default;

ScriptEngine::~ScriptEngine() {
    shutdown();
}

bool ScriptEngine::initialize() {
    m_luaState = luaL_newstate();

    if (!m_luaState) {
        std::cerr << "[ScriptEngine] Failed to create Lua state\n";
        return false;
    }

    luaL_openlibs(m_luaState);

    LuaBindings::bindAll(m_luaState, m_editorAPI);

    std::cout << "[ScriptEngine] Initialized\n";
    return true;
}

void ScriptEngine::shutdown() {
    if (m_luaState) {
        lua_close(m_luaState);
        m_luaState = nullptr;
    }
}

bool ScriptEngine::executeFile(const std::string& path) {
    if (!m_luaState) return false;

    if (luaL_dofile(m_luaState, path.c_str()) != LUA_OK) {
        std::cerr << "[Lua Error] " << lua_tostring(m_luaState, -1) << "\n";
        return false;
    }

    return true;
}

bool ScriptEngine::executeString(const std::string& code) {
    if (!m_luaState) return false;

    if (luaL_dostring(m_luaState, code.c_str()) != LUA_OK) {
        std::cerr << "[Lua Error] " << lua_tostring(m_luaState, -1) << "\n";
        return false;
    }

    return true;
}

void ScriptEngine::update(float deltaTime) {
    // future: tick Lua systems / editor scripts
    (void)deltaTime;
}

lua_State* ScriptEngine::getState() {
    return m_luaState;
}

void ScriptEngine::setEditorAPI(std::shared_ptr<EditorAPI> api) {
    m_editorAPI = api;
}

} // namespace gqf
