#include <iostream>
#include <string>

/*
 * InspectorWindow
 * ------------------------------------------------------------
 * High-level container window for the inspector UI.
 * Hosts:
 *  - WidgetTreeView
 *  - PropertyEditor
 *  - EventMonitor
 *  - RenderOverlay
 */

class InspectorWindow {
public:
    InspectorWindow() {
        std::cout << "[InspectorWindow] Created\n";
    }

    void update() {
        // Future: layout updates, docking logic
    }

    void draw() {
        std::cout << "[InspectorWindow] Drawing main inspector UI\n";

        drawMenuBar();
        drawPanels();
    }

private:
    void drawMenuBar() {
        std::cout << "  ├─ MenuBar: [View] [Debug] [Tools]\n";
    }

    void drawPanels() {
        std::cout << "  ├─ Panels:\n";
        std::cout << "  │   ├─ Widget Tree\n";
        std::cout << "  │   ├─ Properties\n";
        std::cout << "  │   ├─ Event Log\n";
        std::cout << "  │   └─ Render Overlay\n";
    }
};
