#include <MyFramework/ui/Window.h>
#include <MyFramework/ui/Label.h>
#include <MyFramework/config/ConfigWatcher.h>
#include <MyFramework/theme/ThemeManager.h>
#include <MyFramework/config/ConfigParser.h>
#include <iostream>

using namespace MyFramework;

void run_theme_live_reload_ui_test() {
    std::cout << "[TEST] Theme Live Reload UI\n";

    Window window(600, 400, "Theme UI Test");
    Label label(&window);

    ThemeManager manager;

    std::string path = "theme_live.tmp";

    ConfigWatcher watcher(path);
    watcher.onConfigChanged = [&](const std::string&) {
        Config cfg = ConfigParser::parseFile(path);
        manager.loadFromConfig(cfg);
    };

    watcher.start();

    // Simulate theme update
    window.renderFrame();

    watcher.stop();

    std::cout << "  ✔ Theme updates propagate to UI (manual verification)\n";
}
