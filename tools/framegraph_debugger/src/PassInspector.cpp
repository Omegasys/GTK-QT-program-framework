#include <iostream>
#include <string>

/*
 * PassInspector
 * ------------------------------------------------------------
 * Displays detailed info about a selected pass.
 */

class PassInspector {
public:
    void inspect(const std::string& passName) {
        std::cout << "[PassInspector] Inspecting: " << passName << "\n";

        // Placeholder inspection data
        std::cout << "  Type: Compute\n";
        std::cout << "  Shader: glow.comp\n";
        std::cout << "  Workgroup: 16x16\n";
        std::cout << "  Execution Time: ~0.2ms\n";
    }
};
