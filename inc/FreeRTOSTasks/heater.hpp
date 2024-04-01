#pragma once

#include <cstdint>

class Heater {

public:
    //constructor
    Heater() {};

    //This function disables the 2nd channel of the PWM0
    static void startHeater();

    //This function enables the 2nd channel of the PWM0
    static void stopHeater() ;

    //sets the Duty of PWM
    void setDutyPercentage(float dutyValuePercentage);

    /* dutyValue() takes the duty cycle percentage of the waveform as an argument
     * and returns the on-time of the waveform in ticks.
     */
    float convertDutyCycleToMilliseconds(float dutyCyclePercentage);


private:

    static float period ; // equals to the period of the waveform in ticks

};