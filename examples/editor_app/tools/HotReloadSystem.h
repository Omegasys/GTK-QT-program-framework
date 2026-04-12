#pragma once

#include <memory>
#include <string>

namespace gqf {

class AssetWatcher;
class LiveReload;
class ScriptEngine;

/// High-level system coordinating live + hot reload
class HotReloadSystem {
public:
    HotReloadSystem();
    ~HotReloadSystem();

    void initialize();
    void shutdown();

    void update();

    void watchPath(const std::string& path);

    void setScriptEngine(std::shared_ptr<ScriptEngine> engine);

private:
    std::unique_ptr<AssetWatcher> m_watcher;
    std::unique_ptr<LiveReload> m_liveReload;

    std::shared_ptr<ScriptEngine> m_scriptEngine;
};

} // namespace gqf
