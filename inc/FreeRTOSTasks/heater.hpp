//
// Created by evangelia on 3/4/24.
//

#pragma once


#include "peripheral/pwm/plib_pwm0.h"

#ifndef OBC_SOFTWARE_HEATER_H
#define OBC_SOFTWARE_HEATER_H


class heater {

public:

    /*This function initializes given instance of PWM periphral with the values configured in MCC GUI.
     * This initializes all the selected channels of given peripheal in MCC GUI.
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
    float dutyCycle =
            (dutyValue / period) * 100; //duty cycle value determines the percentage of the ON time of waveform.

private:
    const float period = PWM0_ChannelPeriodGet(PWM_CHANNEL_2);   // equals to the period of the waveform in milliseconds
    float dutyValue; // equals to the ON time of waveform in milliseconds
    const float maxPower;  // max electrical input

};


#endif //OBC_SOFTWARE_HEATER_H
