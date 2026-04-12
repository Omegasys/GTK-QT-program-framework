#pragma once

struct lua_State;

namespace gqf {

class EditorAPI;

/// Registers all Lua ↔ C++ bindings
class LuaBindings {
public:
    static void bindAll(lua_State* L, std::shared_ptr<EditorAPI> api);
};

} // namespace gqf
