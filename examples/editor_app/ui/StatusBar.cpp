#include "StatusBar.h"
#include <iostream>

StatusBar::StatusBar()
    : Panel("StatusBar"), m_status("Ready") {}

void StatusBar::update() {
    // Future: update FPS, state, etc.
}

void StatusBar::render() {
    std::cout << "[Status] " << m_status << "\n";
}

void StatusBar::setStatus(const std::string& status) {
    m_status = status;
}
