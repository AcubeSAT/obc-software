#pragma once

#include "FreeRTOS.h"
#include "SEGGER_RTT.h"
#include "TimeKeepingTask.hpp"
#include "MCUTemperatureTask.hpp"
#include "AmbientTemperatureTask.hpp"
#include "UARTGatekeeperTask.hpp"
#include "WatchdogTask.hpp"
#include "CANGatekeeperTask.hpp"
#include "CANTestTask.hpp"

void initializeTasks();
