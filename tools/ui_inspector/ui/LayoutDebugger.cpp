#include <iostream>
#include <vector>

/*
 * LayoutDebugger
 * ------------------------------------------------------------
 * Visualizes layout bounds, alignment, spacing, and hierarchy.
 * Intended for GPU overlay rendering later.
 */

struct DebugRect {
    float x, y, w, h;
};

class LayoutDebugger {
public:
    void addRect(float x, float y, float w, float h) {
        rects.push_back({x, y, w, h});
    }

    void clear() {
        rects.clear();
    }

    void draw() {
        std::cout << "[LayoutDebugger] Drawing " << rects.size()
                  << " layout bounds\n";

        for (const auto& r : rects) {
            std::cout << "  Rect: (" << r.x << ", " << r.y
                      << ", " << r.w << ", " << r.h << ")\n";
        }
    }

private:
    std::vector<DebugRect> rects;
};
