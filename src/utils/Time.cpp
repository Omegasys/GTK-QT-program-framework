#include <MyFramework/utils/Time.h>

namespace MyFramework {

static double g_deltaTime = 0.0;
static double g_totalTime = 0.0;

void Time::setDeltaTime(double dt) {
    g_deltaTime = dt;
    g_totalTime += dt;
}

double Time::deltaTime() {
    return g_deltaTime;
}

double Time::totalTime() {
    return g_totalTime;
}

} // namespace MyFramework
