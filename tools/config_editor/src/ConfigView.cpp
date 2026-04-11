#include "ConfigView.h"
#include "ConfigTreeModel.h"

#include <MyFramework/utils/FileSystem.h>

using namespace MyFramework;

ConfigView::ConfigView(Window* parent)
    : Widget(parent) {
    model = new ConfigTreeModel();
}

void ConfigView::loadFile(const std::string& path) {
    currentFile = path;
    configData = FileSystem::readFile(path);
    model->parse(configData);
}

void ConfigView::update() {
    model->update();
}

std::string ConfigView::getCurrentConfig() const {
    return configData;
}
