#include "SystemUIManager.h"
#include "Taskbar.h"
#include <MyFramework/ui/Window.h>

using namespace MyFramework;

SystemUIManager& SystemUIManager::instance() {
    static SystemUIManager inst;
    return inst;
}

void SystemUIManager::initialize() {
    Window* systemWindow = new Window(1920, 50, "Taskbar");

    taskbar = new Taskbar(systemWindow);
}

void SystemUIManager::update() {
    if (taskbar)
        taskbar->update();
}
