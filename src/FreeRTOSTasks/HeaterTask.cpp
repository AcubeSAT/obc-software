//
// Created by evangelia on 3/12/24.
//


#include "FreeRTOSTasks/HeaterTask.hpp"
#include "peripheral/pwm/plib_pwm0.h"

void HeaterTask::execute() {

    PWM0_Initialize();
    PWM0_ChannelsStart(PWM_CHANNEL_2_MASK);
    vTaskDelay(pdMS_TO_TICKS(100));

}