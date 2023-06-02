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

class InitializationTask: public Task {
public:
    const static inline uint16_t TaskStackDepth = 8300;

    StackType_t taskStack[TaskStackDepth];

    InitializationTask() : Task("InitializationTask") {}

    void execute();

    void createTask() {
        xTaskCreateStatic(vClassTask<InitializationTask>, this->TaskName, InitializationTask::TaskStackDepth,
                          this, configMAX_PRIORITIES - 1, this->taskStack,
                          &(this->taskBuffer));
    }
};

inline std::optional<InitializationTask> initializationTask;


#endif //OBC_SOFTWARE_INITIALIZATIONTASK_HPP
