//
// Created by evangelia on 3/21/24.
//

#include "FreeRTOSTasks/HeaterTask.hpp"
#include "peripheral/pwm/plib_pwm0.h"

void HeaterTask::execute() {

    PWM0_Initialize();

    PWM0_ChannelPeriodSet(PWM_CHANNEL_2, 7500);
    PWM0_ChannelDutySet(PWM_CHANNEL_2, 3750);
    PWM0_ChannelsStart(PWM_CHANNEL_2_MASK);
    vTaskDelay(pdMS_TO_TICKS(100));

}