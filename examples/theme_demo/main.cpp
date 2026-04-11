#include <MyFramework/core/Application.h>
#include <MyFramework/ui/Window.h>
#include <MyFramework/ui/Label.h>
#include <MyFramework/config/ConfigParser.h>
#include <MyFramework/config/ConfigWatcher.h>
#include <MyFramework/theme/ThemeManager.h>
#include <MyFramework/utils/Logger.h>
#include <MyFramework/utils/Time.h>

using namespace MyFramework;

int main() {
    Application app;

    if (!app.initialize()) {
        Logger::error("Failed to initialize application");
        return -1;
    }

    // Create window
    Window window(800, 600, "Theme Demo - Live Reload + Time-Based Themes");
    window.show();

    // UI Label
    Label* label = new Label(&window);
    label->setPosition(50, 50);
    label->setText("Live Theme Demo\nEdit themes.config while running!");

    // Theme system
    ThemeManager themeManager;
    std::string configPath = "themes.config";

    // Initial load
    {
        Logger::info("Loading initial config...");
        Config config = ConfigParser::parseFile(configPath);
        themeManager.loadFromConfig(config);
    }

    // Live reload watcher
    ConfigWatcher watcher(configPath);
    watcher.onConfigChanged = [&](const std::string& path) {
        Logger::info("Config file changed → Reloading themes");

        Config newConfig = ConfigParser::parseFile(path);
        themeManager.loadFromConfig(newConfig);
    };
    watcher.start();

    // Main loop
    while (window.isOpen()) {
        // Handle events
        Event event;
        while (window.pollEvent(event)) {
            window.handleEvent(event);
        }

        // Update theme system
        themeManager.update();

        // Get current theme
        const Theme& theme = themeManager.currentTheme();

        // 🔥 Apply theme visually (basic version)
        // (Later this should move into Renderer / Window)
        label->setColor(theme.centerColor);

        // Debug info in label
        label->setText(
            "Live Theme Demo\n"
            "Edit themes.config while running!\n\n"
            "Opacity: " + std::to_string(theme.opacity) + "\n" +
            "Blur: " + std::to_string(theme.blur) + "\n" +
            "Corner Radius: " + std::to_string(theme.cornerRadius)
        );

        // Render frame
        window.renderFrame();
    }

    watcher.stop();
    app.shutdown();

    return 0;
}
