#pragma once

#include "Panel.h"
#include <vector>
#include <string>

/*
 * ConsolePanel
 * ------------------------------------------------------------
 * Displays logs and debug messages.
 */

class ConsolePanel : public Panel {
public:
    ConsolePanel();

    void update() override;
    void render() override;

    void log(const std::string& message);

private:
    std::vector<std::string> m_logs;
};
