#pragma once

class Taskbar;

class SystemUIManager {
public:
    static SystemUIManager& instance();

    void initialize();
    void update();

private:
    Taskbar* taskbar = nullptr;
};
