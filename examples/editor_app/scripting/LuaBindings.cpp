#include "LuaBindings.h"
#include "EditorAPI.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

#include <memory>

namespace gqf {

// Global pointer stored in Lua registry (simple approach for now)
static std::shared_ptr<EditorAPI> g_api;

static int lua_log(lua_State* L) {
    const char* msg = lua_tostring(L, 1);
    if (g_api && msg) g_api->log(msg);
    return 0;
}

static int lua_createObject(lua_State* L) {
    const char* type = lua_tostring(L, 1);
    if (g_api && type) g_api->createObject(type);
    return 0;
}

static int lua_setTheme(lua_State* L) {
    const char* theme = lua_tostring(L, 1);
    if (g_api && theme) g_api->setTheme(theme);
    return 0;
}

void LuaBindings::bindAll(lua_State* L, std::shared_ptr<EditorAPI> api) {
    g_api = api;

    lua_register(L, "log", lua_log);
    lua_register(L, "createObject", lua_createObject);
    lua_register(L, "setTheme", lua_setTheme);
}

} // namespace gqf
