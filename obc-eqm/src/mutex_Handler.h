#pragma once

#include "FreeRTOS.h"
#include "semphr.h"

enum smphr_groups{
    GROUP_A,
    GROUP_B,
    GROUP_C
};

void initializeSemaphores();

bool takeSemaphoreGroup(smphr_groups group);

void releaseSemaphoreGroup(smphr_groups group);