# Basic Window Example

This example demonstrates:

- Creating an application
- Opening a window
- Adding a button and label
- Handling click events

## Features

- Basic UI rendering
- Event handling
- Widget hierarchy

## Run

```bash
mkdir build
cd build
cmake ..
make
./basic_window

---

# 🌈 `examples/theme_demo/main.cpp`

This one shows your **core innovation**:
👉 time-based themes + live reload

```cpp
#include <MyFramework/core/Application.h>
#include <MyFramework/ui/Window.h>
#include <MyFramework/ui/Label.h>
#include <MyFramework/config/ConfigParser.h>
#include <MyFramework/config/ConfigWatcher.h>
#include <MyFramework/theme/ThemeManager.h>
#include <MyFramework/utils/Logger.h>

using namespace MyFramework;

int main() {
    Application app;

    if (!app.initialize()) {
        Logger::error("Failed to initialize");
        return -1;
    }

    Window window(800, 600, "Theme Demo");
    window.show();

    Label* label = new Label(&window);
    label->setPosition(50, 50);
    label->setText("Live Theme Demo");

    ThemeManager themeManager;

    std::string configPath = "themes.config";

    // Initial load
    Config config = ConfigParser::parseFile(configPath);
    themeManager.loadFromConfig(config);

    // Live reload
    ConfigWatcher watcher(configPath);
    watcher.onConfigChanged = [&](const std::string& path) {
        Logger::info("Config changed, reloading...");
        Config newConfig = ConfigParser::parseFile(path);
        themeManager.loadFromConfig(newConfig);
    };
    watcher.start();

    // Main loop
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            window.handleEvent(event);
        }

        themeManager.update();

        // (Future) Apply theme to window here

        window.renderFrame();
    }

    watcher.stop();
    app.shutdown();
    return 0;
}
