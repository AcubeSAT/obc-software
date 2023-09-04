#pragma once

#include "FreeRTOS.h"
#include "Logger.hpp"

extern "C" void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
    LOG_DEBUG << "Stack overflow on task " << pcTaskName;
}

