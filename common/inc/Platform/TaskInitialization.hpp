#pragma once

#include "FreeRTOSTasks/TaskList.hpp"
#include "FreeRTOS.h"
#include "SEGGER_RTT.h"

using namespace TaskList;

template<class T>
static void vClassTask(void *pvParameters) {
    (static_cast<T *>(pvParameters))->execute();
}

namespace Init {
    void initializeTasks();
}
