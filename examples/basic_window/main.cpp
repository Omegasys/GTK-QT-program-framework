#include <MyFramework/core/Application.h>
#include <MyFramework/ui/Window.h>
#include <MyFramework/ui/Button.h>
#include <MyFramework/ui/Label.h>
#include <MyFramework/utils/Logger.h>

using namespace MyFramework;

int main() {
    Application app;

    if (!app.initialize()) {
        Logger::error("Failed to initialize application");
        return -1;
    }

    Window window(800, 600, "Basic Window");
    window.show();

    // Create UI
    Button* button = new Button(&window);
    button->setPosition(100, 100);
    button->setSize(200, 50);
    button->setText("Click Me");

    Label* label = new Label(&window);
    label->setPosition(100, 200);
    label->setText("Hello from MyFramework!");

    button->onClick = [&]() {
        Logger::info("Button clicked!");
        label->setText("Button was clicked!");
    };

    // Main loop
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            window.handleEvent(event);
        }

        window.renderFrame();
    }

    app.shutdown();
    return 0;
}
