#pragma once

#include <string>

/*
 * EditorState
 * ------------------------------------------------------------
 * Tracks runtime/editor state (mode, selection, etc.)
 */

class EditorState {
public:
    EditorState();

    void update();

    void setMode(const std::string& mode);
    const std::string& getMode() const;

private:
    std::string m_mode;
};
