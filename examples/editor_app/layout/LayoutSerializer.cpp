#include "LayoutSerializer.h"
#include "Workspace.h"
#include <sstream>

std::string LayoutSerializer::serialize(const std::shared_ptr<Workspace>& workspace) {
    if (!workspace) return "{}";

    const auto& docks = workspace->getLayout().getDocks();

    std::ostringstream out;
    out << "{ \"docks\": [";

    for (size_t i = 0; i < docks.size(); i++) {
        const auto& d = docks[i];

        std::string region =
            (d.region == DockLayout::Region::Left) ? "left" :
            (d.region == DockLayout::Region::Right) ? "right" :
            (d.region == DockLayout::Region::Top) ? "top" :
            (d.region == DockLayout::Region::Bottom) ? "bottom" : "center";

        out << "{"
            << "\"name\":\"" << d.name << "\","
            << "\"region\":\"" << region << "\","
            << "\"size\":" << d.sizeRatio
            << "}";

        if (i + 1 < docks.size()) out << ",";
    }

    out << "] }";
    return out.str();
}

bool LayoutSerializer::deserialize(std::shared_ptr<Workspace>& workspace, const std::string& data) {
    // Minimal placeholder parser (extend later with JSON lib)
    if (!workspace) return false;

    workspace->clear();

    // VERY simplified: just checks key tokens
    if (data.find("Project") != std::string::npos) {
        workspace->addDock("Project", "left");
    }
    if (data.find("Inspector") != std::string::npos) {
        workspace->addDock("Inspector", "right");
    }
    if (data.find("Console") != std::string::npos) {
        workspace->addDock("Console", "bottom");
    }
    if (data.find("Editor") != std::string::npos) {
        workspace->addDock("Editor", "center");
    }

    return true;
}
