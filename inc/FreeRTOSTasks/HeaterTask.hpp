//
// Created by evangelia on 3/12/24.
//

#ifndef OBC_SOFTWARE_HEATERTASK_HPP
#define OBC_SOFTWARE_HEATERTASK_HPP

#include "Task.hpp"


class HeaterTask : public Task {
private:

    const static inline uint16_t TaskStackDepth = 2000;

    StackType_t taskStack[TaskStackDepth];

public:

    void execute();

    HeaterTask() : Task("Heater") {}

    /**
     * Create freeRTOS Task
     */
    void createTask() {
        xTaskCreateStatic(vClassTask<HeaterTask>, this->TaskName, HeaterTask::TaskStackDepth,
                          this, tskIDLE_PRIORITY + 2 , this->taskStack,
                          &(this->taskBuffer));
    }

};

inline std::optional<HeaterTask> heaterTask;


#endif //OBC_SOFTWARE_HEATERTASK_HPP
