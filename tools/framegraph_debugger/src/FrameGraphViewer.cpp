#include <iostream>
#include <vector>
#include <string>

/*
 * FrameGraphViewer
 * ------------------------------------------------------------
 * Visualizes passes and dependencies as a graph.
 */

struct FGPass {
    std::string name;
    std::vector<std::string> inputs;
    std::vector<std::string> outputs;
};

class FrameGraphViewer {
public:
    void buildGraph() {
        passes.clear();

        passes.push_back({"UI Pass", {}, {"ui_buffer"}});
        passes.push_back({"Blur Pass", {"ui_buffer"}, {"blur_buffer"}});
        passes.push_back({"Glow Pass", {"blur_buffer"}, {"glow_buffer"}});
        passes.push_back({"Composite Pass", {"glow_buffer"}, {"final_output"}});
    }

    void draw() {
        std::cout << "[FrameGraphViewer] Graph:\n";

        for (const auto& p : passes) {
            std::cout << "  Pass: " << p.name << "\n";

            std::cout << "    Inputs: ";
            for (auto& in : p.inputs) std::cout << in << " ";
            std::cout << "\n";

            std::cout << "    Outputs: ";
            for (auto& out : p.outputs) std::cout << out << " ";
            std::cout << "\n";
        }
    }

private:
    std::vector<FGPass> passes;
};
