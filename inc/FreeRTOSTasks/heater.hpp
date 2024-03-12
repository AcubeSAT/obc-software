//
// Created by evangelia on 3/4/24.
//

#pragma once


#include "peripheral/pwm/plib_pwm0.h"

#ifndef OBC_SOFTWARE_HEATER_H
#define OBC_SOFTWARE_HEATER_H


class heater {

public:

    /*This function initializes given instance of PWM peripheral with the values configured in MCC GUI.
     * This initializes all the selected channels of given peripheral in MCC GUI.
     * This function must be called before any other PWM function is called.
     * This function should only be called once during system initialization.*/
    static void initializeHeater() {
        PWM0_Initialize();
    }

    //This function disables the 2nd channel of the PWM0
    static void startHeater() {
        PWM0_ChannelsStart(PWM_CHANNEL_2_MASK);
    }

    //This function enables the 2nd channel of the PWM0
    static void stopHeater() {
        PWM0_ChannelsStop(PWM_CHANNEL_2_MASK);
    }

    //sets the Duty of PWM
    void setDutyPercentage(float dutyValuePercentage) {
        PWM0_ChannelDutySet(PWM_CHANNEL_2, convertDutyCycleToMilliseconds(dutyValuePercentage));
    }

    /* dutyValue() takes the duty cycle percentage of the waveform as an argument
     * and returns the on-time of the waveform in ticks.
     */
    float convertDutyCycleToMilliseconds(float dutyCyclePercentage) {
        return period * (dutyCyclePercentage / 100.0f);
    }


private:
    const float period = PWM0_ChannelPeriodGet(PWM_CHANNEL_2);   // equals to the period of the waveform in ticks

    /* max electrical input . At the time being, I am not sure if this is needed.
     * If it is, we should probably initialize the maxPower to the power supply voltage
     * that we are going to use for the Heater
     */
    const float maxPower;  // max electrical input

};


#endif //OBC_SOFTWARE_HEATER_H
