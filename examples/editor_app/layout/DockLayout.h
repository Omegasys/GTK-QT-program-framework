#pragma once

#include <string>
#include <vector>
#include <memory>

class DockLayout {
public:
    enum class Region {
        Left,
        Right,
        Top,
        Bottom,
        Center
    };

    struct Dock {
        std::string name;
        Region region;
        float sizeRatio; // 0.0 - 1.0
    };

    void addDock(const std::string& name, Region region, float sizeRatio = 0.25f);

    void removeDock(const std::string& name);

    std::vector<Dock>& getDocks();
    const std::vector<Dock>& getDocks() const;

    void clear();

private:
    std::vector<Dock> docks;
};
