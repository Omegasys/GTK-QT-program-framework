#include "RedshiftManager.h"

RedshiftManager& RedshiftManager::instance() {
    static RedshiftManager inst;
    return inst;
}

void RedshiftManager::update(float hour) {
    // Simple curve: warm at night, neutral during day
    if (hour >= 20 || hour <= 6) {
        temperature = 3500.0f; // warm
    } else {
        temperature = 6500.0f; // neutral
    }
}

float RedshiftManager::getTemperature() const {
    return temperature;
}
