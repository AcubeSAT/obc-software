#pragma once

#include "CAN/Driver.hpp"
#include "Task.hpp"

class CANTestTask : public Task {
private:

public:
    const static inline uint16_t TaskStackDepth = 2300;

    StackType_t taskStack[TaskStackDepth];

    void execute();

    CANTestTask() : Task("CAN Test") {}

    /**
     * Create freeRTOS Task
     */
    void createTask() {
        xTaskCreateStatic(vClassTask < CANTestTask > , this->TaskName, CANTestTask::TaskStackDepth, this,
                          configMAX_PRIORITIES - 1, this->taskStack, &(this->taskBuffer));
    }
};

inline std::optional<CANTestTask> canTestTask;
