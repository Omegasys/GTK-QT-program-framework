#include "LiveReload.h"
#include "ScriptEngine.h"

#include <iostream>

namespace gqf {

LiveReload::LiveReload() = default;

void LiveReload::setScriptEngine(std::shared_ptr<ScriptEngine> engine) {
    m_scriptEngine = engine;
}

void LiveReload::reload(const std::string& path) {
    std::cout << "[LiveReload] Reloading: " << path << "\n";

    if (path.ends_with(".lua")) {
        reloadScript(path);
    }
    else if (path.ends_with(".json")) {
        reloadTheme(path);
    }
}

void LiveReload::reloadScript(const std::string& path) {
    if (m_scriptEngine) {
        std::cout << "[LiveReload] Reload Lua script\n";
        m_scriptEngine->executeFile(path);
    }
}

void LiveReload::reloadTheme(const std::string& path) {
    std::cout << "[LiveReload] Reload Theme JSON\n";

    // Future: call ThemeManager here
}

} // namespace gqf
