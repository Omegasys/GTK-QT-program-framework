#pragma once

#include "Panel.h"
#include <string>

/*
 * InspectorPanel
 * ------------------------------------------------------------
 * Displays properties of selected object.
 */

class InspectorPanel : public Panel {
public:
    InspectorPanel();

    void update() override;
    void render() override;

    void setSelected(const std::string& objectName);

private:
    std::string m_selectedObject;
};
