#include "TaskInitialization.hpp"

void Init::initializeTasks() {
    SEGGER_RTT_Init();
    BootCounter::incrementBootCounter();

    uartGatekeeperTask.emplace();
    timeKeepingTask.emplace();
    updateParametersTask.emplace();
    ambientTemperatureTask.emplace();
    watchdogTask.emplace();

    xTaskCreateStatic(vClassTask<UARTGatekeeperTask>, uartGatekeeperTask->taskName, uartGatekeeperTask->taskStackDepth,
                      &uartGatekeeperTask, tskIDLE_PRIORITY + 2, uartGatekeeperTask->taskStack,
                      &uartGatekeeperTask->taskBuffer);
    xTaskCreateStatic(vClassTask<UpdateParametersTask>, updateParametersTask->taskName,
                      updateParametersTask->taskStackDepth,
                      &updateParametersTask, tskIDLE_PRIORITY + 1, updateParametersTask->taskStack,
                      &updateParametersTask->taskBuffer);
    xTaskCreateStatic(vClassTask<TimeKeepingTask>, timeKeepingTask->taskName, timeKeepingTask->taskStackDepth,
                      &timeKeepingTask, tskIDLE_PRIORITY + 1, timeKeepingTask->taskStack, &timeKeepingTask->taskBuffer);
    xTaskCreateStatic(vClassTask<AmbientTemperatureTask>, ambientTemperatureTask->taskName,
                      ambientTemperatureTask->taskStackDepth,
                      &ambientTemperatureTask, tskIDLE_PRIORITY + 2, ambientTemperatureTask->taskStack,
                      &ambientTemperatureTask->taskBuffer);
    xTaskCreateStatic(vClassTask<WatchdogTask>, watchdogTask->taskName, watchdogTask->taskStackDepth,
                      &watchdogTask, tskIDLE_PRIORITY, watchdogTask->taskStack, &watchdogTask->taskBuffer);

}