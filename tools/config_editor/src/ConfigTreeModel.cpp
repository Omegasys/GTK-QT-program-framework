#include "ConfigTreeModel.h"
#include <sstream>

void ConfigTreeModel::parse(const std::string& raw) {
    tree.clear();

    std::stringstream ss(raw);
    std::string line;

    while (std::getline(ss, line)) {
        size_t eq = line.find('=');
        if (eq == std::string::npos) continue;

        ConfigNode node;
        node.key = line.substr(0, eq);
        node.value = line.substr(eq + 1);

        tree.push_back(node);
    }
}

void ConfigTreeModel::update() {
    // placeholder for live editing / syncing
}

const std::vector<ConfigNode>& ConfigTreeModel::nodes() const {
    return tree;
}
