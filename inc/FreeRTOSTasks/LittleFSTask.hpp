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


    const struct lfs_config cfg = {
            // block device operations
            .read = {},
//            .prog  = &MT29F::abstactWriteNAND,
//            .erase = &MT29F::eraseBlock,
//            .sync  = ,
            // block device configuration
            .read_size = 16,
            .prog_size = 16,
            .block_size = 4096,
            .block_count = 128,
            .block_cycles = 500,
            .cache_size = 16,
            .lookahead_size = 16
    };

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
