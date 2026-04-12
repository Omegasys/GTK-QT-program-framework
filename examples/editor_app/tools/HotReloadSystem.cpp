#include "HotReloadSystem.h"
#include "AssetWatcher.h"
#include "LiveReload.h"
#include "ScriptEngine.h"

#include <iostream>

namespace gqf {

HotReloadSystem::HotReloadSystem() = default;
HotReloadSystem::~HotReloadSystem() = default;

void HotReloadSystem::initialize() {
    m_watcher = std::make_unique<AssetWatcher>();
    m_liveReload = std::make_unique<LiveReload>();

    if (m_scriptEngine) {
        m_liveReload->setScriptEngine(m_scriptEngine);
    }

    std::cout << "[HotReloadSystem] Initialized\n";
}

void HotReloadSystem::shutdown() {
    m_watcher.reset();
    m_liveReload.reset();
}

void HotReloadSystem::setScriptEngine(std::shared_ptr<ScriptEngine> engine) {
    m_scriptEngine = engine;

    if (m_liveReload) {
        m_liveReload->setScriptEngine(engine);
    }
}

void HotReloadSystem::watchPath(const std::string& path) {
    if (!m_watcher) return;

    m_watcher->watchDirectory(path, [this](const std::string& changedPath) {
        if (m_liveReload) {
            m_liveReload->reload(changedPath);
        }
    });
}

void HotReloadSystem::update() {
    if (m_watcher) {
        m_watcher->poll();
    }
}

} // namespace gqf
