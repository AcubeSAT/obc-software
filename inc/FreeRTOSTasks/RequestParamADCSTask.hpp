#ifndef REQUESTPARAMADCS_HPP
#define REQUESTPARAMADCS_HPP

#endif //REQUESTPARAMADCS_HPP

#pragma once

#include "CAN/Driver.hpp"
#include "Task.hpp"

class RequestParamADCSTask : public Task {
private:

public:
    const static inline uint16_t TaskStackDepth = 2300;

    StackType_t taskStack[TaskStackDepth];

    void execute();

    RequestParamADCSTask() : Task("CAN Test") {}

    /**
     * Create freeRTOS Task
     */

     void createTask() {
        xTaskCreateStatic(vClassTask < RequestParamADCSTask > , this->TaskName, RequestParamADCSTask::TaskStackDepth, this,
                        tskIDLE_PRIORITY+2, this->taskStack, &(this->taskBuffer));
    }
};

inline std::optional<RequestParamADCSTask> RequestParamADCSTask;