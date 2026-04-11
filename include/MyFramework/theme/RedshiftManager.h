#pragma once

namespace GQFusion {

/**
 * @brief Manages time-based color temperature shifting (Redshift/Night Mode).
 *
 * Adjusts rendering tone based on time of day.
 */
class RedshiftManager {
public:
    static RedshiftManager& instance();

    // ------------------------------------------------------------
    // Control
    // ------------------------------------------------------------

    void setEnabled(bool enabled);
    bool isEnabled() const;

    /**
     * @brief Update based on time (0–24 hours).
     */
    void update(float hour);

    // ------------------------------------------------------------
    // Temperature
    // ------------------------------------------------------------

    void setDayTemperature(float temp);     // e.g. 6500K
    void setNightTemperature(float temp);   // e.g. 3500K

    float getTemperature() const;

    // ------------------------------------------------------------
    // Schedule
    // ------------------------------------------------------------

    void setStartHour(float hour);  // night start
    void setEndHour(float hour);    // night end

private:
    RedshiftManager() = default;

private:
    bool enabled = false;

    float currentTemp = 6500.0f;

    float dayTemp = 6500.0f;
    float nightTemp = 3500.0f;

    float startHour = 20.0f;
    float endHour = 6.0f;
};

} // namespace GQFusion
