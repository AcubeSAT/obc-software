#ifndef OBC_SOFTWARE_NANDERASEBLOCKTASK_HPP
#define OBC_SOFTWARE_NANDERASEBLOCKTASK_HPP


#include "Task.hpp"
#include "NANDFlash.h"


class NANDEraseBlockTask : public Task {
private:
    const uint16_t DelayMs = 1000;

    const static inline uint16_t TaskStackDepth = 1000;

    StackType_t taskStack[TaskStackDepth];

public:
    void execute();

    NANDEraseBlockTask() : Task("NANDFlashInitilization") {}

    void createTask() {
        xTaskCreateStatic(vClassTask<NANDEraseBlockTask>, this->TaskName,
                          NANDEraseBlockTask::TaskStackDepth, this, tskIDLE_PRIORITY + 2, this->taskStack,
                          &(this->taskBuffer)); // TODO: alter priorities, or enable the task through NANDWriteReadTask
    }

};

inline std::optional<NANDEraseBlockTask> nandEraseBlockTask;


#endif //OBC_SOFTWARE_NANDERASEBLOCKTASK_HPP
