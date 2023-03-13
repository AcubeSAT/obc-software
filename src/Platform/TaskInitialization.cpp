#include "TaskInitialization.hpp"

void initializeTasks() {
    SEGGER_RTT_Init();
    BootCounter::incrementBootCounter();

    uartGatekeeperTask.emplace();
    timeKeepingTask.emplace();
    ambientTemperatureTask.emplace();
    watchdogTask.emplace();
    mcuTemperatureTask.emplace();
    canGatekeeperTask.emplace();
    canTestTask.emplace();

    ambientTemperatureTask->createTask();
    mcuTemperatureTask->createTask();
    timeKeepingTask->createTask();
    uartGatekeeperTask->createTask();
    watchdogTask->createTask();
    canGatekeeperTask->createTask();
    canTestTask->createTask();
}
