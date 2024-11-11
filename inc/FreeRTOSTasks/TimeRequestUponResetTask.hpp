#pragma once

#include "Task.hpp"
#include "ApplicationLayer.hpp"

class TimeRequestUponResetTask: public Task {
public:
       const static inline uint16_t TaskStackDepth = 2300;

    StackType_t taskStack[TaskStackDepth];
    TaskHandle_t TimeRequestUponResetTaskHandle = NULL;
    void execute();


    TimeRequestUponResetTask() : Task("TimeRequestUponResetTask") {}

    /**
     * Create freeRTOS Task
     */
    void createTask() {
        xTaskCreateStatic(vClassTask < TimeRequestUponResetTask > , this->TaskName, TimeRequestUponResetTask::TaskStackDepth, this,
                         tskIDLE_PRIORITY+3, this->taskStack, &(this->taskBuffer));
    }
};

inline std::optional<TimeRequestUponResetTask> timeRequestUponResetTask;