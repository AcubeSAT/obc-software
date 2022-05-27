#ifndef ECSS_SERVICES_XTIMEKEEPINGTASK_HPP
#define ECSS_SERVICES_XTIMEKEEPINGTASK_HPP

#include "FreeRTOS.h"
#include "task.h"
#include "ServicePool.hpp"
#include "BootCounter.hpp"
#include "definitions.h"
#include "Logger.hpp"
#include "Platform/Parameters/PlatformParameters.hpp"

class TimeKeepingTask {
private:
    const uint16_t delayMs = 1000;

public:
    /**
     * Name of each task.
     */
    const char *taskName = "TimeKeeping";
    /**
     * Handle of each FreeRTOS task.
     */
    TaskHandle_t taskHandle = NULL;
    /**
     * The stack depth of each FreeRTOS task, defined as the number of words the stack can hold. For example, in an
     * architecture with 4 byte stack, assigning 100 to the usStackDepth argument, will allocate 4x100=400 bytes.
     */
    const uint16_t taskStackDepth = 1000;

    void execute();

    /**
     * Sets the year base, used to acquire the current time from a tm structure.
     */
    uint16_t yearBase = 1900;

    /**
     * This function sets the epoch time.
     * @param dateTime is a tm struct witch keeps the time from MCU.
     */
    void setEpoch(tm &dateTime);

    /**
     * This function sets the AcubeSAT's time parameters using a tm struct.
     * @param dateTime is a tm struct witch keeps the time from MCU.
     */
    void setTimePlatformParameters(tm &dateTime);

    /**
     * This function prints the on-board time.
     */
    void printOnBoardTime();

};

#endif
