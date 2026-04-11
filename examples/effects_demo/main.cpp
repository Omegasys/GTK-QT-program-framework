#include <MyFramework/core/Application.h>
#include <MyFramework/ui/Window.h>
#include <MyFramework/ui/Button.h>
#include <MyFramework/ui/Label.h>

#include <MyFramework/effects/EffectStack.h>
#include <MyFramework/effects/FadeEffect.h>
#include <MyFramework/effects/BlurEffect.h>
#include <MyFramework/effects/ShadowEffect.h>

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

    Window window(800, 600, "Effects Demo - Live Reload");
    window.show();

    // UI
    Button* button = new Button(&window);
    button->setPosition(250, 200);
    button->setSize(300, 80);
    button->setText("Effects Demo");

    Label* label = new Label(&window);
    label->setPosition(250, 320);
    label->setText("Edit demo.config while running!");

    // Effects
    EffectStack* effects = new EffectStack();

    FadeEffect* fade = new FadeEffect();
    BlurEffect* blur = new BlurEffect();
    ShadowEffect* shadow = new ShadowEffect();

    effects->addEffect(shadow);
    effects->addEffect(blur);
    effects->addEffect(fade);

    button->setEffectStack(effects);

    std::string configPath = "demo.config";
    Config config;

    // Apply config → effects
    auto applyConfig = [&](const Config& cfg) {
        float opacity = std::stof(cfg.value("opacity", "255")) / 255.0f;
        float blurRadius = std::stof(cfg.value("blur", "0"));
        float shadowDist = std::stof(cfg.value("shadow_distance", "5"));

        std::string shadowColorStr = cfg.value("shadow_color", "#000000");

        // Simple hex parsing
        int r = 0, g = 0, b = 0;
        sscanf(shadowColorStr.c_str(), "#%02x%02x%02x", &r, &g, &b);

        Color shadowColor(r / 255.0f, g / 255.0f, b / 255.0f);

        fade->setOpacity(opacity);
        blur->setRadius(blurRadius);
        shadow->setOffset(0, shadowDist);
        shadow->setColor(shadowColor);

        label->setText(
            "Effects Demo (Live)\n\n"
            "Opacity: " + std::to_string(opacity) + "\n" +
            "Blur: " + std::to_string(blurRadius) + "\n" +
            "Shadow Dist: " + std::to_string(shadowDist) + "\n\n"
            "Edit demo.config!"
        );
    };

    // Initial load
    Logger::info("Loading effects config...");
    config = ConfigParser::parseFile(configPath);
    applyConfig(config);

    // Live reload
    ConfigWatcher watcher(configPath);
    watcher.onConfigChanged = [&](const std::string& path) {
        Logger::info("Config changed → Updating effects");

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
