#ifndef OBC_SOFTWARE_NANDCHECKIDTASK_HPP
#define OBC_SOFTWARE_NANDCHECKIDTASK_HPP


#include "Task.hpp"
#include "NANDFlash.h"


class NANDCheckIDTask : public Task {
private:
    const uint16_t DelayMs = 1000;

    const static inline uint16_t TaskStackDepth = 1000;

    StackType_t taskStack[TaskStackDepth];

public:
    void execute();

    NANDCheckIDTask() : Task("NANDFlashInitilization") {}

    void createTask() {
        xTaskCreateStatic(vClassTask<NANDCheckIDTask>, this->TaskName,
                          NANDCheckIDTask::TaskStackDepth, this, tskIDLE_PRIORITY + 2, this->taskStack,
                          &(this->taskBuffer));
    }

};

inline std::optional<NANDCheckIDTask> nandCheckIDTask;

#endif //OBC_SOFTWARE_NANDCHECKIDTASK_HPP
