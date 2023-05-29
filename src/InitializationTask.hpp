//
// Created by giorgos on 5/29/23.
//
#include "main.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "list.h"
#include "task.h"
#include "definitions.h"
#include "OBC_Definitions.hpp"
#include "TaskInitialization.hpp"
#include "HousekeepingTask.hpp"
#include "TimeBasedSchedulingTask.hpp"
#include "StatisticsReportingTask.hpp"
#include "TCHandlingTask.hpp"

#include "Task.hpp"

#ifndef OBC_SOFTWARE_INITIALIZATIONTASK_HPP
#define OBC_SOFTWARE_INITIALIZATIONTASK_HPP

class InitializationTask: public Task
{
public:
    const static inline uint16_t TaskStackDepth = 2000;

    StackType_t taskStack[TaskStackDepth];

    InitializationTask() : Task("Initialization") {}

    void execute();

    void createTask() {
        xTaskCreateStatic(vClassTask<InitializationTask>, this->TaskName, InitializationTask::TaskStackDepth,
                          this, configMAX_PRIORITIES - 1, this->taskStack,
                          &(this->taskBuffer));
    }

};

inline std::optional<HousekeepingTask> InitializationTask;


#endif //OBC_SOFTWARE_INITIALIZATIONTASK_HPP
