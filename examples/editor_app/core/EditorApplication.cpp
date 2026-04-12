#include "EditorApplication.h"
#include "EditorContext.h"
#include "EditorState.h"

#include <iostream>

EditorApplication::EditorApplication() {
    std::cout << "[EditorApplication] Created\n";
}

EditorApplication::~EditorApplication() {
    std::cout << "[EditorApplication] Destroyed\n";
}

bool EditorApplication::initialize(const std::string& configPath) {
    std::cout << "[EditorApplication] Initializing...\n";

    m_context = std::make_unique<EditorContext>();
    m_state = std::make_unique<EditorState>();

    if (!m_context->loadConfig(configPath)) {
        std::cerr << "[EditorApplication] Failed to load config\n";
        return false;
    }

    m_state->setMode("Editing");

    std::cout << "[EditorApplication] Initialization complete\n";
    return true;
}

void EditorApplication::run() {
    std::cout << "[EditorApplication] Running\n";

    while (m_running) {
        update();
        render();
    }
}

void EditorApplication::shutdown() {
    std::cout << "[EditorApplication] Shutdown\n";
    m_running = false;
}

void EditorApplication::update() {
    m_state->update();
}

void EditorApplication::render() {
    // Future: hook into GPU renderer
    std::cout << "[EditorApplication] Rendering frame\n";
}
