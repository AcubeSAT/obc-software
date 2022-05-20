#ifndef ECSS_SERVICES_XTIMEKEEPINGTASK_HPP
#define ECSS_SERVICES_XTIMEKEEPINGTASK_HPP

#include "Task.hpp"

class XTimeKeepingTask : public Task {
private:
    const uint16_t delayMs = 1000;
public:
    void execute() override;

    /**
     * Sets the year base, used to acquire the current time from a tm structure.
     */
    uint16_t yearBase = 1900;

    /**
     * This function sets the epoch time.
     * @param dateTime is a tm struct witch keeps the time from MCU.
     */
    void setEpoch(struct tm &dateTime);

    /**
     * This function sets the AcubeSAT's time parameters using a tm struct.
     * @param dateTime is a tm struct witch keeps the time from MCU.
     */
    void setTimePlatformParameters(struct tm &dateTime);

    /**
     * This function prints the on-board time.
     */
    void printOnBoardTime();

    XTimeKeepingTask(const char *taskName, TaskHandle_t taskHandle, const uint16_t taskStackDepth,
                     const uint16_t delayMs) : Task(taskName, taskHandle, taskStackDepth), delayMs(delayMs) {}
};

#endif
