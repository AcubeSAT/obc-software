#pragma once

#include "CAN/Driver.hpp"
#include "Task.hpp"

class OBTtoADCSTask : public Task {
private:

public:
    const static inline uint16_t TaskStackDepth = 2300;

    StackType_t taskStack[TaskStackDepth];

    void execute();


    OBTtoADCSTask() : Task("CAN Test") {}

    /**
     * Create freeRTOS Task
     */
    void createTask() {
        xTaskCreateStatic(vClassTask < OBTtoADCSTask > , this->TaskName, OBTtoADCSTask::TaskStackDepth, this,
                         tskIDLE_PRIORITY+2, this->taskStack, &(this->taskBuffer));
    }
};

inline std::optional<OBTtoADCSTask> OBTtoADCSTask;
