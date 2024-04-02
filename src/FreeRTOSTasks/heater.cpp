#include "Logger.hpp"
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
    if (dutyCyclePercentage <= 100 && dutyCyclePercentage >= 0)
        PWM0_ChannelDutySet(PWM_CHANNEL_2, convertDutyCyclePercentageToTicks());
    else
        LOG_ERROR << "Duty cycle percentage must be between 0 and 100 ";
}

uint16_t Heater::convertDutyCyclePercentageToTicks() {
    return period * (dutyCyclePercentage / 100);
}