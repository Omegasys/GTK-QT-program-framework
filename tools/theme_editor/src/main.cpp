#include "ThemeEditorApp.h"

int main() {
    ThemeEditorApp app;

    if (!app.initialize())
        return -1;

    app.run();
    app.shutdown();

    return 0;
}
