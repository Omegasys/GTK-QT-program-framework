#include "ConsolePanel.h"
#include <iostream>

ConsolePanel::ConsolePanel()
    : Panel("Console") {}

void ConsolePanel::update() {
    // Future: live log stream
}

void ConsolePanel::render() {
    std::cout << "[Console]\n";

    for (const auto& log : m_logs) {
        std::cout << log << "\n";
    }
}

void ConsolePanel::log(const std::string& message) {
    m_logs.push_back(message);
}
