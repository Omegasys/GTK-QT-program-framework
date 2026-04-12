#pragma once

#include <string>
#include <memory>

class Workspace;

class LayoutSerializer {
public:
    static std::string serialize(const std::shared_ptr<Workspace>& workspace);
    static bool deserialize(std::shared_ptr<Workspace>& workspace, const std::string& data);
};
