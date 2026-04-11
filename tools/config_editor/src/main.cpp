#include "ConfigEditorApp.h"

int main() {
    ConfigEditorApp app;

    if (!app.initialize()) {
        return -1;
    }

    app.run();
    app.shutdown();

    return 0;
}
