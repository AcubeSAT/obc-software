#ifndef OBC_SOFTWARE_TESTSERVICETASK_H
#define OBC_SOFTWARE_TESTSERVICETASK_H
#include "Task.hpp"

/**
 * FreeRTOS task for periodically checking if the MCU is alive.
 */
class TestServiceTask : public Task {
private:
    const uint16_t delayMs = 10000;
public:
    void execute();

    TestServiceTask(const char *taskName, TaskHandle_t taskHandle, const uint16_t taskStackDepth) : Task(taskName, taskHandle, taskStackDepth) {}
};


#endif //OBC_SOFTWARE_TESTSERVICETASK_H
