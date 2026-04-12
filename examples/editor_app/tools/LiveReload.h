#pragma once

#include <string>
#include <memory>

namespace gqf {

class ScriptEngine;

/// Handles reloading of assets when they change
class LiveReload {
public:
    LiveReload();

    void setScriptEngine(std::shared_ptr<ScriptEngine> engine);

    void reload(const std::string& path);

private:
    std::shared_ptr<ScriptEngine> m_scriptEngine;

    void reloadScript(const std::string& path);
    void reloadTheme(const std::string& path);
};

} // namespace gqf
