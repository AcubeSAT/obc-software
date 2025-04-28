//
// Created by kyriakum on 10/4/2025.
//

#include "HousekeepingTask.hpp"
#include "TimeBasedSchedulingTask.hpp"
#include "StatisticsReportingTask.hpp"
#include "CANGatekeeperTask.hpp"
#include "CANTestTask.hpp"
#include "TCHandlingTask.hpp"
#include "NANDTask.hpp"
#include "MRAMTask.hpp"
#include "TaskInitialization.hpp"

#ifndef TASKHANDLER_HPP
#define TASKHANDLER_HPP

namespace TaskHandler {
    inline void initialize() {
        initializeAmbientTemperatureTask();
        housekeepingTask.emplace();
        canTestTask.emplace();
        nandTask.emplace();
        mramTask.emplace();

        housekeepingTask->createTask();
        canTestTask->createTask();
        nandTask->createTask();
        mramTask->createTask();
        resetChecks();
        vTaskStartScheduler();
    }
}

#endif //TASKHANDLER_HPP
