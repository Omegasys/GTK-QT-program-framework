#pragma once

class RedshiftManager {
public:
    static RedshiftManager& instance();

    void update(float timeOfDay); // 0–24
    float getTemperature() const;

private:
    float temperature = 6500.0f; // default (daylight)
};
