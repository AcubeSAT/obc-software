#ifndef OBC_SOFTWARE_NANDINITIALIZETASK_HPP
#define OBC_SOFTWARE_NANDINITIALIZETASK_HPP

#include "Task.hpp"
#include "NANDFlash.h"


class NANDInitializeTask : public Task {
private:
    const uint16_t DelayMs = 1000;

    uint8_t status = 1;

    const static inline uint16_t TaskStackDepth = 1000;

    StackType_t taskStack[TaskStackDepth];

public:
    void execute();

    NANDInitializeTask() : Task("NANDFlashInitilization") {}

    void createTask() {
        xTaskCreateStatic(vClassTask<NANDInitializeTask>, this->TaskName,
                          NANDInitializeTask::TaskStackDepth, this, tskIDLE_PRIORITY + 2, this->taskStack,
                          &(this->taskBuffer));
    }

};

inline std::optional<NANDInitializeTask> nandInitializeTask;


#endif //OBC_SOFTWARE_NANDINITIALIZETASK_HPP
