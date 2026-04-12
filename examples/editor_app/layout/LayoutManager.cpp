#include "LayoutManager.h"
#include "Workspace.h"
#include "LayoutSerializer.h"

LayoutManager::LayoutManager() {
    workspace = std::make_shared<Workspace>();
}

void LayoutManager::setWorkspace(std::shared_ptr<Workspace> ws) {
    workspace = ws;
}

std::shared_ptr<Workspace> LayoutManager::getWorkspace() const {
    return workspace;
}

void LayoutManager::createDefaultLayout() {
    if (!workspace) return;

    workspace->clear();

    workspace->addDock("Project", "left");
    workspace->addDock("Inspector", "right");
    workspace->addDock("Console", "bottom");
    workspace->addDock("Editor", "center");
}

std::string LayoutManager::saveLayout() const {
    return LayoutSerializer::serialize(workspace);
}

bool LayoutManager::loadLayout(const std::string& data) {
    return LayoutSerializer::deserialize(workspace, data);
}

void LayoutManager::resetLayout() {
    createDefaultLayout();
}
