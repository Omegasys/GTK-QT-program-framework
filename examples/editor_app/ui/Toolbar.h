#pragma once

#include "Panel.h"

/*
 * Toolbar
 * ------------------------------------------------------------
 * Top action bar (buttons, tools).
 */

class Toolbar : public Panel {
public:
    Toolbar();

    void update() override;
    void render() override;
};
