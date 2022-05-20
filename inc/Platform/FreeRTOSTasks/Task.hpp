#ifndef OBC_SOFTWARE_TASK_HPP
#define OBC_SOFTWARE_TASK_HPP

#include "FreeRTOS.h"
#include "task.h"
#include "ServicePool.hpp"
#include "BootCounter.hpp"
#include "definitions.h"
#include "Logger.hpp"

/**
 * Base class, whose method 'execute' is meant to be inherited by each and every individual FreeRTOS task.
 */
class Task {
public:
    /**
     * Name of each task.
     */
    const char *taskName;
    /**
     * Handle of each FreeRTOS task.
     */
    TaskHandle_t taskHandle;
    /**
     * The stack depth of each FreeRTOS task, defined as the number of words the stack can hold. For example, in an
     * architecture with 4 byte stack, assigning 100 to the usStackDepth argument, will allocate 4x100=400 bytes.
     */
    const uint16_t taskStackDepth = 2000;

    /**
     * Implemented by each child-task, in order to perform its individual, different job.
     */
    virtual void execute() = 0;

    /**
     * Helps call the execute function through 'xTaskCreate' during the creation of the FreeRTOS tasks.
     * @param pvParameters used for passing parameters inside FreeRTOS tasks.
     */
    static void vClassTask(void *pvParameters) {
        (static_cast<Task *>(pvParameters))->execute();
    }

    Task(const char *taskName, TaskHandle_t taskHandle, const uint16_t taskStackDepth) : taskName(taskName),
                                                                                         taskHandle(taskHandle),
                                                                                         taskStackDepth(
                                                                                                 taskStackDepth) {}
};

#endif
