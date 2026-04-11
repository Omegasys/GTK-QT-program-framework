#include <iostream>

class WidgetTreeView {
public:
    void refresh() {
        // In real engine: pull from RenderTree
    }

    void draw() {
        std::cout << "[Inspector] WidgetTreeView rendering tree...\n";
    }
};
