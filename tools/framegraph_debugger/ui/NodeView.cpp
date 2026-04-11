#include <iostream>
#include <string>
#include <vector>

/*
 * NodeView
 * ------------------------------------------------------------
 * Represents a single FrameGraph pass node in the UI.
 */

class NodeView {
public:
    NodeView(const std::string& name)
        : name(name) {}

    void setPosition(float x, float y) {
        posX = x;
        posY = y;
    }

    void addInput(const std::string& input) {
        inputs.push_back(input);
    }

    void addOutput(const std::string& output) {
        outputs.push_back(output);
    }

    void draw() {
        std::cout << "  [Node] " << name
                  << " @(" << posX << ", " << posY << ")\n";

        std::cout << "    Inputs: ";
        for (auto& i : inputs) std::cout << i << " ";
        std::cout << "\n";

        std::cout << "    Outputs: ";
        for (auto& o : outputs) std::cout << o << " ";
        std::cout << "\n";
    }

private:
    std::string name;

    float posX = 0.0f;
    float posY = 0.0f;

    std::vector<std::string> inputs;
    std::vector<std::string> outputs;
};
