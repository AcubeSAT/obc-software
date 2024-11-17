#pragma once

#include "Task.hpp"
#include "queue.h"
#include "Peripheral_Definitions.hpp"
#include "FlashDriver.hpp"

class FlashTestTask : public Task {

private:
    static constexpr uint32_t TASK_STACK_SIZE = 1024;
    static constexpr uint32_t TASK_PRIORITY = 3;

    // Test data structure
    struct TestData {
        uint32_t counter;
        uint32_t timestamp;
        uint32_t testValue;
        uint32_t checksum;
    };

    FlashDriver flash;
    TaskHandle_t taskHandle;
    static constexpr uint32_t TEST_FLASH_ADDR = 0x005F0000;
    const uint16_t DelayMs = 10000;

    const static inline uint16_t TaskStackDepth = 10000;

    StackType_t taskStack[TaskStackDepth];

    /**
     * This variable is used to store the maximum time the task should wait for the notification in ticks.
     * The number 1000ms was considered a good value arbitrarily
     */
    TickType_t MaxDelay = pdMS_TO_TICKS(1000);
public:
    FlashTestTask() : Task("FlashTest") {
        LOG_DEBUG << "Settings start: 0x" << reinterpret_cast<uint32_t>(_settings_start);
        LOG_DEBUG << "Settings end: 0x" << reinterpret_cast<uint32_t>(_settings_end);
    }
    void execute();

    void createTask() {
        xTaskCreateStatic(vClassTask<FlashTestTask>, this->TaskName,
                          FlashTestTask::TaskStackDepth, this, tskIDLE_PRIORITY + 2,
                          this->taskStack, &(this->taskBuffer));
    }
    uint32_t calculateChecksum(const TestData& data);

};

inline std::optional<FlashTestTask> flashTestTask;