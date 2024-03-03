//
// Created by evangelia on 3/4/24.
//

#pragma once

#include <Time/TimeStamp.hpp>
#include "peripheral/pwm/plib_pwm0.h"

#ifndef OBC_SOFTWARE_HEATER_H
#define OBC_SOFTWARE_HEATER_H


class heater {
    friend heater changeDutyCycle(float dutyCycle);

public:
    Time::DefaultCUC start;
    Time::DefaultCUC stop;

    float maxPower;  // max electrical input
    float dutyCycle = (dutyValue/period)*100 ; //duty cycle value determines the percentage of the ON time of waveform.

private:
    float period;    // equals to the period of the waveform
    float dutyValue; // equals to the ON time of waveform in milliseconds

};


#endif //OBC_SOFTWARE_HEATER_H
