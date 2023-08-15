#ifndef OBC_SOFTWARE_LITTLEFSTASK_HPP
#define OBC_SOFTWARE_LITTLEFSTASK_HPP

#include "LittleFS.hpp"
#include "Task.hpp"

class LittleFSTask : public Task {
private:

    const uint16_t DelayMs = 500;

    const static inline uint16_t TaskStackDepth = 1000;

    StackType_t taskStack[TaskStackDepth];

    LittleFS littleFs;

public:

    void execute();

    LittleFSTask() : Task("LittleFSTask") {}

    void createTask() {
        xTaskCreateStatic(vClassTask < LittleFSTask > , this->TaskName,
                          LittleFSTask::TaskStackDepth, this, tskIDLE_PRIORITY + 2, this->taskStack,
                          &(this->taskBuffer));
    }

};

inline std::optional<LittleFSTask> lfsTask;

#endif //OBC_SOFTWARE_LITTLEFSTASK_HPP
