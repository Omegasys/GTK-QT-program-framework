#include <iostream>

class EventMonitor {
public:
    void poll() {
        // Capture UI events from engine
    }

    void draw() {
        std::cout << "[Inspector] EventMonitor logging events...\n";
    }
};
