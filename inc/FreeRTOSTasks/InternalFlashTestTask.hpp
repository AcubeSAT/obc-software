#pragma once

#include "Task.hpp"
#include "InternalFlash.hpp"
#include <etl/expected.h>

/**
 * FreeRTOS task to test the internal flash memory of the MCU
 */
class InternalFlashTestTask : public Task {
private:
    static constexpr TickType_t DelayMs = 5000;

    static constexpr uint16_t TaskStackDepth = 5000;

    StackType_t taskStack[TaskStackDepth]{};

public:
    static FlashDriver::EFCError testQuadWordWriteRead(FlashDriver& flash);

    static FlashDriver::EFCError testPageWriteRead(FlashDriver& flash);

    static FlashDriver::EFCError testBoundaryConditions(FlashDriver& flash);

    static void testFlashModule(FlashDriver& flash) {
        constexpr uint8_t NumTests = 3;
        uint8_t correctResults = 0;

        if (auto result = testBoundaryConditions(flash); result == FlashDriver::EFCError::NONE) {
            LOG_DEBUG << "FLASH BOUNDARY CONDITIONS TEST SUCCEEDED";
            correctResults++;
        } else {
            LOG_DEBUG << "FLASH BOUNDARY CONDITIONS TEST FAILED";
            printFlashError(result);
        }

        if (auto result = testQuadWordWriteRead(flash); result == FlashDriver::EFCError::NONE) {
            LOG_DEBUG << "FLASH QUAD WORD RW TEST SUCCEEDED";
            correctResults++;
        } else {
            LOG_DEBUG << "FLASH QUAD WORD RW TEST FAILED";
            printFlashError(result);
        }

        if (auto result = testPageWriteRead(flash); result == FlashDriver::EFCError::NONE) {
            LOG_DEBUG << "FLASH PAGE RW TEST SUCCEEDED";
            correctResults++;
        } else {
            LOG_DEBUG << "FLASH PAGE RW TEST FAILED";
            printFlashError(result);
        }

        LOG_DEBUG << "FLASH TESTS COMPLETED";
        LOG_DEBUG << "Correct Results: " << correctResults << "/" << NumTests;
    }

    static void printFlashError(FlashDriver::EFCError error) {
        switch (error) {
            case FlashDriver::EFCError::TIMEOUT:
                LOG_DEBUG << "Flash Error: Timeout";
            break;
            case FlashDriver::EFCError::ADDRESS_UNSAFE:
                LOG_DEBUG << "Flash Error: Address Unsafe";
            break;
            case FlashDriver::EFCError::INVALID_COMMAND:
                LOG_DEBUG << "Flash Error: Invalid Command";
            break;
            case FlashDriver::EFCError::REGION_LOCKED:
                LOG_DEBUG << "Flash Error: Region Locked";
            break;
            case FlashDriver::EFCError::FLASH_ERROR:
                LOG_DEBUG << "Flash Error: Flash Error";
            break;
            case FlashDriver::EFCError::ECC_ERROR:
                LOG_DEBUG << "Flash Error: ECC Error";
            break;
            case FlashDriver::EFCError::UNDEFINED:
                LOG_DEBUG << "Flash Error: Undefined";
            break;
            default:
                LOG_DEBUG << "Flash Error: Unknown";
            break;
        }
    }

    InternalFlashTestTask() : Task("InternalFlashTestTask") {}

    void execute();

    void createTask() {
        xTaskCreateStatic(vClassTask<InternalFlashTestTask>, this->TaskName,
                         TaskStackDepth, this, tskIDLE_PRIORITY + 2,
                         this->taskStack, &(this->taskBuffer));
    }
};

inline std::optional<InternalFlashTestTask> internalFlashTestTask;