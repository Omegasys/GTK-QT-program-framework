#include "EditorState.h"

#include <iostream>

EditorState::EditorState()
    : m_mode("Idle") {
    std::cout << "[EditorState] Initialized\n";
}

void EditorState::update() {
    // Future: selection, tools, interaction
    std::cout << "[EditorState] Mode: " << m_mode << "\n";
}

void EditorState::setMode(const std::string& mode) {
    m_mode = mode;
}

const std::string& EditorState::getMode() const {
    return m_mode;
}
