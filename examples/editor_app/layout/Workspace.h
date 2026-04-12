#pragma once

#include <string>
#include <vector>
#include "DockLayout.h"

class Workspace {
public:
    Workspace();

    void addDock(const std::string& name, const std::string& region);
    void removeDock(const std::string& name);

    DockLayout& getLayout();

    void clear();

private:
    DockLayout layout;
};
