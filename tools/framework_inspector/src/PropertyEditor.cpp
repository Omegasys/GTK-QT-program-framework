#include "PropertyEditor.h"

#include <MyFramework/utils/Logger.h>

using namespace MyFramework;

PropertyEditor::PropertyEditor(Window* parent)
    : Widget(parent) {}

void PropertyEditor::inspectObject(const std::string& objectId) {
    properties.clear();

    // Fake reflection system
    properties["id"] = objectId;
    properties["visible"] = "true";
    properties["opacity"] = "1.0";
}

void PropertyEditor::update() {
    // Render property UI (placeholder)
}
