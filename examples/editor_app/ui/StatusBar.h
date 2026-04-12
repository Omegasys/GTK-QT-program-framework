#pragma once

#include "Panel.h"
#include <string>

/*
 * StatusBar
 * ------------------------------------------------------------
 * Bottom info bar (FPS, state, messages).
 */

class StatusBar : public Panel {
public:
    StatusBar();

    void update() override;
    void render() override;

    void setStatus(const std::string& status);

private:
    std::string m_status;
};
