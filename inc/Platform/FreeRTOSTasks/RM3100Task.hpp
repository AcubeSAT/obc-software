#ifndef OBC_SOFTWARE_RM3100TASK_HPP
#define OBC_SOFTWARE_RM3100TASK_HPP

#include "Task.hpp"
#include "RM3100.hpp"

class RM3100TASK : public Task {
private:
    const uint16_t delayMs = 1000;
public:
    void execute();

    /**
     * This function prints the magnetometer measurements.
     */
    void printData(RM3100 rm3100);

    RM3100TASK(const char *taskName, TaskHandle_t taskHandle, const uint16_t taskStackDepth,
                    const uint16_t delayMs) : Task(taskName, taskHandle, taskStackDepth), delayMs(delayMs) {}
};

#endif
