#pragma once

#include <cstdint>

class Heater {

public:
    /**Different instances of the constructor
     * we can construct a heater either initializing a period value
     * or taking the default period value
     */
    Heater(uint16_t period);

    Heater();


    /**This function disables the 2nd channel of the PWM0
     *
     */
    static void startHeater();

    /**This function enables the 2nd channel of the PWM0
     *
     */
    static void stopHeater();

    /**sets the Duty of PWM
     *
     * @param dutyCyclePercentage
     */
    void setDutyPercentage(uint8_t dutyCyclePercentage);

    /** dutyValue() takes the duty cycle percentage of the waveform as an argument
     * and returns the on-time of the waveform in ticks.
     */
    uint16_t convertDutyCyclePercentageToTicks();

private:

    /** the period of the waveform in ticks
     *
     */
    uint16_t period;

    /** the duty Cycle Percentage (== heater On Time / period)
     *
     */
    uint8_t dutyCyclePercentage;
};