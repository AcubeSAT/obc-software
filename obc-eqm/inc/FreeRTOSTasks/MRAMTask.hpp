#pragma once

#include "MR4A08BUYS45.hpp"
#include "Task.hpp"
#include "etl/optional.h"
#include "LCLDefinitions.hpp"
#include <etl/array.h>
#include <etl/span.h>
#include <etl/random.h>
#include <etl/expected.h>

class MRAMTask : public Task {
public:
   const uint16_t DelayMs = 15000;
   
   constexpr static inline uint16_t TaskStackDepth = 5000;

   StackType_t taskStack[TaskStackDepth];

   void execute();

   MRAMTask() : Task("MRAMTask") {}


   static inline TaskHandle_t mramTaskHandle;

   void createTask() {
      mramTaskHandle = xTaskCreateStatic(vClassTask<MRAMTask>, this->TaskName,
                                          TaskStackDepth, this, tskIDLE_PRIORITY + 2, this->taskStack,
                                          &(this->taskBuffer));
   }
};

inline std::optional<MRAMTask> mramTask;