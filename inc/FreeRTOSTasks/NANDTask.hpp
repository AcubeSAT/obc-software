#ifndef OBC_SOFTWARE_NANDTASK_HPP
#define OBC_SOFTWARE_NANDTASK_HPP

#include "Task.hpp"
#include "NANDFlash.h"


class NANDTask : public Task {
private:
    const uint16_t DelayMs = 500;

    const static inline uint16_t TaskStackDepth = 1000;

    StackType_t taskStack[TaskStackDepth];

public:
    void execute();

    NANDTask() : Task("NANDFlashInitilization") {}

    void createTask() {
        xTaskCreateStatic(vClassTask<NANDTask>, this->TaskName,
                          NANDTask::TaskStackDepth, this, tskIDLE_PRIORITY + 2, this->taskStack,
                          &(this->taskBuffer));
    }

};

inline std::optional<NANDTask> nandTask;



#endif //OBC_SOFTWARE_NANDTASK_HPP
