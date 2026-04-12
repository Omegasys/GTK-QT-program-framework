#pragma once

#include "Panel.h"

/*
 * Viewport
 * ------------------------------------------------------------
 * Main render panel (scene / UI preview).
 */

class Viewport : public Panel {
public:
    Viewport();

    void update() override;
    void render() override;
};
