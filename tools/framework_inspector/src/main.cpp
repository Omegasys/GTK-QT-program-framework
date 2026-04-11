#include "InspectorApp.h"

int main() {
    InspectorApp app;

    if (!app.initialize())
        return -1;

    app.run();
    app.shutdown();

    return 0;
}
