#include "DockLayout.h"
#include <algorithm>

void DockLayout::addDock(const std::string& name, Region region, float sizeRatio) {
    docks.push_back({name, region, sizeRatio});
}

void DockLayout::removeDock(const std::string& name) {
    docks.erase(
        std::remove_if(docks.begin(), docks.end(),
            [&](const Dock& d) { return d.name == name; }),
        docks.end()
    );
}

std::vector<DockLayout::Dock>& DockLayout::getDocks() {
    return docks;
}

const std::vector<DockLayout::Dock>& DockLayout::getDocks() const {
    return docks;
}

void DockLayout::clear() {
    docks.clear();
}
