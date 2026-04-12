#include "Toolbar.h"
#include <iostream>

Toolbar::Toolbar()
    : Panel("Toolbar") {}

void Toolbar::update() {
    // Future: button interactions
}

void Toolbar::render() {
    std::cout << "[Toolbar] (Save | Load | Play | Stop)\n";
}
