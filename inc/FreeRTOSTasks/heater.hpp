#pragma once

#include <cstdint>

class heater {

public:
    //constructor
    heater() {};

    /*This function initializes given instance of PWM peripheral with the values configured in MCC GUI.
     * This initializes all the selected channels of given peripheral in MCC GUI.
     * This function must be called before any other PWM function is called.
     * This function should only be called once during system initialization.*/
    static void initializeHeater();

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