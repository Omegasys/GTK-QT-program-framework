#include <iostream>
#include <vector>
#include <string>

/*
 * ResourceTracker
 * ------------------------------------------------------------
 * Tracks creation, usage, and lifetime of frame resources.
 */

struct ResourceInfo {
    std::string name;
    std::string producer;
    std::vector<std::string> consumers;
};

class ResourceTracker {
public:
    void captureResources() {
        resources.clear();

        resources.push_back({"ui_buffer", "UI Pass", {"Blur Pass"}});
        resources.push_back({"blur_buffer", "Blur Pass", {"Glow Pass"}});
        resources.push_back({"glow_buffer", "Glow Pass", {"Composite Pass"}});
    }

    void draw() {
        std::cout << "[ResourceTracker] Resources:\n";

        for (const auto& r : resources) {
            std::cout << "  Resource: " << r.name << "\n";
            std::cout << "    Produced by: " << r.producer << "\n";

            std::cout << "    Consumed by: ";
            for (auto& c : r.consumers)
                std::cout << c << " ";
            std::cout << "\n";
        }
    }

private:
    std::vector<ResourceInfo> resources;
};
