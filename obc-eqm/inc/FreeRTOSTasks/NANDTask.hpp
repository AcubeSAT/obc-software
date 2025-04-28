#pragma once

#include "TaskConfigs.hpp"
#include "NANDFlash.h"


class NANDTask : public Task {
private:
    const uint16_t DelayMs = 5000;

    StackType_t taskStack[NANDTaskStack];

public:
    void execute();

    NANDTask() : Task("NANDFlashInitilization") {}

    static inline TaskHandle_t nandTaskHandle;

    void createTask() {
        nandTaskHandle = xTaskCreateStatic(vClassTask<NANDTask>, this->TaskName,
                                           NANDTaskStack, this, NANDTaskPriority, this->taskStack,
                                           &(this->taskBuffer));
    }
};

inline std::optional<NANDTask> nandTask;