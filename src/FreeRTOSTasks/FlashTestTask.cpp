#include "inc/FreeRTOSTasks/FlashTestTask.hpp"

uint32_t FlashTestTask::calculateChecksum(const TestData& data) {
    return data.counter ^ data.timestamp ^ data.testValue;
}

void FlashTestTask::execute() {
    LOG_DEBUG << "----------- Flash Test Task Starting -----------";
    LOG_DEBUG << "Test Flash Address: 0x" << std::hex << TEST_FLASH_ADDR;
    LOG_DEBUG << "Settings Start: 0x" << std::hex << reinterpret_cast<uint32_t>(&_settings_start);
    LOG_DEBUG << "Settings End: 0x" << std::hex << reinterpret_cast<uint32_t>(&_settings_end);

    TestData writeData = {0};
    TestData readData = {0};
    const TickType_t delayTime = pdMS_TO_TICKS(5000);

    while(1) {
        if(!flash.IsReady()) {
            LOG_DEBUG << "Flash busy, waiting...";
            vTaskDelay(pdMS_TO_TICKS(100));
            continue;
        }

        // Prepare test data
        writeData.counter++;
        writeData.timestamp = xTaskGetTickCount();
        writeData.testValue = 0xDEADBEEF;
        writeData.checksum = calculateChecksum(writeData);

        LOG_DEBUG << "Attempting to erase sector at 0x"  << TEST_FLASH_ADDR;

        EFC_ERROR result = flash.SectorErase(TEST_FLASH_ADDR);
        if(result != EFC_ERROR_NONE) {
            LOG_DEBUG << "Failed to erase sector at address 0x"  << TEST_FLASH_ADDR << " with error: 0x" << result;
            vTaskDelay(delayTime);
            continue;
        }

        result = flash.QuadWordWrite(reinterpret_cast<FlashData*>(&writeData), TEST_FLASH_ADDR);
        if(result != EFC_ERROR_NONE) {
            LOG_DEBUG << "Failed to write data at address 0x"  << TEST_FLASH_ADDR << " with error: 0x" << result;
            vTaskDelay(delayTime);
            continue;
        }

        result = flash.Read(reinterpret_cast<FlashData*>(&readData), sizeof(TestData), TEST_FLASH_ADDR);
        if(result != EFC_ERROR_NONE) {
            LOG_DEBUG << "Failed to read data from address 0x"  << TEST_FLASH_ADDR << " with error: 0x" << result;
            vTaskDelay(delayTime);
            continue;
        }

        if (memcmp(&writeData, &readData, sizeof(TestData)) == 0) {
            LOG_DEBUG << "Test " << std::dec << writeData.counter << " successful";
            LOG_DEBUG << "Written: Counter=" << writeData.counter
                      << ", Time=" << writeData.timestamp
                      << ", Value=0x"  << writeData.testValue;

            uint32_t readChecksum = calculateChecksum(readData);
            if(readChecksum != readData.checksum) {
                LOG_DEBUG << "Checksum error! Calc: 0x"  << readChecksum
                          << ", Stored: 0x" << readData.checksum;
            }
        } else {
            LOG_DEBUG << "Data verification failed!";
            LOG_DEBUG << "Written: Counter=" << std::dec << writeData.counter
                      << ", Time=" << writeData.timestamp
                      << ", Value=0x"  << writeData.testValue;
            LOG_DEBUG << "Read: Counter=" << std::dec << readData.counter
                      << ", Time=" << readData.timestamp
                      << ", Value=0x"  << readData.testValue;
        }

        vTaskDelay(delayTime);
    }
}
