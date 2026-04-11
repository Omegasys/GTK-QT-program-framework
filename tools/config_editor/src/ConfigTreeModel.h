#pragma once

#include <string>
#include <vector>

struct ConfigNode {
    std::string key;
    std::string value;
};

class ConfigTreeModel {
public:
    void parse(const std::string& raw);
    void update();

    const std::vector<ConfigNode>& nodes() const;

private:
    std::vector<ConfigNode> tree;
};
