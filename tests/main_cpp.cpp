#include "definitions.h"
#include <iostream>
#include <catch2/catch_all.hpp>
#include "main.h"
#include "definitions.h"
#include "InitializationTask.hpp"
#include "FreeRTOSHandlers.hpp"

#define IDLE_TASK_SIZE 100

#if configSUPPORT_STATIC_ALLOCATION
/* static memory allocation for the IDLE task */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[IDLE_TASK_SIZE];

extern "C" void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer,
                                              uint32_t *pulIdleTaskStackSize) {
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
    *ppxIdleTaskStackBuffer = &xIdleStack[0];
    *pulIdleTaskStackSize = IDLE_TASK_SIZE;
}

#endif


extern "C" {

void main_cpp() {
    std::cout << "DIAGNOSTICS:" << std::endl;
    std::cout << "  CPU clock: " << CPU_CLOCK_FREQUENCY / 1e6 << " MHz" << std::endl;
    std::cout << std::endl;

    std::cout << "[" << SYSTICK_TimerCounterGet() << "] Initializing tests..." << std::endl;

    static Catch::Session session; // There must be exactly one instance

    // This is the equivalent of passing command-line argument
    auto configData = Catch::ConfigData();
    configData.showDurations = Catch::ShowDurations::Always;
//    configData.useColour = Catch::UseColour::Yes;
    session.useConfigData(configData);

    std::cout << "[" << SYSTICK_TimerCounterGet() << "] Running tests..." << std::endl;

    int numFailed = session.run();
    if (numFailed == 0) {
        std::cerr << "Success" << std::endl;
    } else {
        std::cerr << "Failed" << std::endl;
    }

    std::cerr << "@RETURN " << +numFailed << std::endl;
}

}
