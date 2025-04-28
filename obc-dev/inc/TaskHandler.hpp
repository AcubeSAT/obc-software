//
// Created by kyriakum on 10/4/2025.
//

#include "InitializationTask.hpp"
#include "InternalFlashTestTask.hpp"

#ifndef TASKHANDLER_HPP
#define TASKHANDLER_HPP

namespace TaskHandler {
    inline void initialize() {
      initializationTask.emplace();
      internalFlashTestTask.emplace();

      initializationTask->createTask();
      internalFlashTestTask->createTask();

      vTaskStartScheduler();
    }
}

#endif //TASKHANDLER_HPP
