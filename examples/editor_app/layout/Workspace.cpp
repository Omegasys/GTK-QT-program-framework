#include "Workspace.h"

static DockLayout::Region parseRegion(const std::string& r) {
    if (r == "left") return DockLayout::Region::Left;
    if (r == "right") return DockLayout::Region::Right;
    if (r == "top") return DockLayout::Region::Top;
    if (r == "bottom") return DockLayout::Region::Bottom;
    return DockLayout::Region::Center;
}

Workspace::Workspace() {}

void Workspace::addDock(const std::string& name, const std::string& region) {
    layout.addDock(name, parseRegion(region));
}

void Workspace::removeDock(const std::string& name) {
    layout.removeDock(name);
}

DockLayout& Workspace::getLayout() {
    return layout;
}

void Workspace::clear() {
    layout.clear();
}
