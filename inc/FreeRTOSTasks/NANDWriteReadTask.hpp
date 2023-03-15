#ifndef OBC_SOFTWARE_NANDWRITEREADTASK_HPP
#define OBC_SOFTWARE_NANDWRITEREADTASK_HPP

#include "Task.hpp"
#include "NANDFlash.h"


class NANDWriteReadTask : public Task {
private:
    const uint16_t DelayMs = 1000;

    const static inline uint16_t TaskStackDepth = 1000;

    StackType_t taskStack[TaskStackDepth];

public:
    void execute();

    NANDWriteReadTask() : Task("NANDFlashInitilization") {}

    void createTask() {
        xTaskCreateStatic(vClassTask<NANDWriteReadTask>, this->TaskName,
                          NANDWriteReadTask::TaskStackDepth, this, tskIDLE_PRIORITY + 2, this->taskStack,
                          &(this->taskBuffer));
    }

};

inline std::optional<NANDWriteReadTask> nandWriteReadTask;


#endif //OBC_SOFTWARE_NANDWRITEREADTASK_HPP
