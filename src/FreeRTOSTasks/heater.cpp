//#include <stdexcept>
#include "inc/FreeRTOSTasks/heater.hpp"
#include "peripheral/pwm/plib_pwm0.h"
#include "peripheral/pwm/plib_pwm1.h"

Heater::Heater() {
    period = PWM0_ChannelPeriodGet(PWM_CHANNEL_2);
}

Heater::Heater(uint16_t period) {
    PWM0_ChannelPeriodSet(PWM_CHANNEL_2, period);
    this->period = period;
}

void Heater::startHeater() {
    PWM0_ChannelsStart(PWM_CHANNEL_2_MASK);
}

void Heater::stopHeater() {
    PWM0_ChannelsStop(PWM_CHANNEL_2_MASK);
}

void Heater::setDutyPercentage(uint8_t dutyCyclePercentage) {
    PWM0_ChannelDutySet(PWM_CHANNEL_2, convertDutyCyclePercentageToTicks(dutyCyclePercentage));
}

uint16_t Heater::convertDutyCyclePercentageToTicks(uint8_t dutyCyclePercentage) {
    return period * (dutyCyclePercentage / 100);
}