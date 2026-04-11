#include <MyFramework/core/Application.h>
#include <MyFramework/ui/Window.h>
#include <MyFramework/ui/Label.h>
#include <MyFramework/config/ConfigParser.h>
#include <MyFramework/config/ConfigWatcher.h>
#include <MyFramework/utils/Logger.h>

using namespace MyFramework;

int main() {
    Application app;

    if (!app.initialize()) {
        Logger::error("Failed to initialize application");
        return -1;
    }

    Window window(800, 600, "Config Live Reload Demo");
    window.show();

    Label* label = new Label(&window);
    label->setPosition(50, 50);

    std::string configPath = "app.config";
    Config config;

    // Function to apply config to UI
    auto applyConfig = [&](const Config& cfg) {
        std::string text  = cfg.value("text", "Default Text");
        std::string color = cfg.value("color", "black");

        label->setText(
            "Live Config Reload Demo\n\n"
            "Text: " + text + "\n" +
            "Color: " + color + "\n\n"
            "Edit app.config while running!"
        );

        // Simple color mapping
        if (color == "red") {
            label->setColor(Color(1, 0, 0));
        } else if (color == "green") {
            label->setColor(Color(0, 1, 0));
        } else if (color == "blue") {
            label->setColor(Color(0, 0, 1));
        } else {
            label->setColor(Color::Black());
        }
    };

    // Initial load
    Logger::info("Loading config...");
    config = ConfigParser::parseFile(configPath);
    applyConfig(config);

    // Watch for changes
    ConfigWatcher watcher(configPath);
    watcher.onConfigChanged = [&](const std::string& path) {
        Logger::info("Config changed → Reloading");

        config = ConfigParser::parseFile(path);
        applyConfig(config);
    };

    watcher.start();

    // Main loop
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            window.handleEvent(event);
        }

        window.renderFrame();
    }

    watcher.stop();
    app.shutdown();

    return 0;
}
