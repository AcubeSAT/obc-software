#include "InternalFlashTestTask.hpp"
#include <etl/array.h>
#include <etl/random.h>

FlashDriver::EFCError
InternalFlashTestTask::testQuadWordWriteRead(FlashDriver& flash) {
    etl::random_xorshift rng;
    constexpr uint32_t availableSpace = FlashDriver::EndAddress - FlashDriver::StartAddress;
    const uint32_t offset = (rng() % (availableSpace - (FlashDriver::WordsPerQuadWord * sizeof(uint32_t))));
    const uint32_t testAddress = FlashDriver::StartAddress + offset;

    LOG_DEBUG << "Testing QuadWord at Address: 0x" << std::hex << testAddress;

    etl::array<uint32_t, FlashDriver::WordsPerQuadWord> writeData{
        0x12345678,
        0x9ABCDEF0,
        0x13579BDF,
        0x2468ACE0
    };

    auto writeError = flash.writeQuadWord(writeData, testAddress);
    if (writeError != FlashDriver::EFCError::NONE) {
        LOG_DEBUG << "QuadWord Write Failed";
        printFlashError(writeError);
        return writeError;
    }

    etl::array<uint32_t, FlashDriver::WordsPerQuadWord> readData{};
    auto readError = flash.readFromMemory(readData,
        FlashDriver::WordsPerQuadWord * sizeof(uint32_t), testAddress);

    if (readError != FlashDriver::EFCError::NONE) {
        LOG_DEBUG << "QuadWord Read Failed";
        printFlashError(readError);
        return readError;
    }

    for (size_t i = 0; i < FlashDriver::WordsPerQuadWord; ++i) {
        if (writeData[i] != readData[i]) {
            LOG_DEBUG << "Data mismatch at index " << i;
            LOG_DEBUG << "Expected: 0x" << std::hex << writeData[i]
                     << " Got: 0x" << readData[i];
            return FlashDriver::EFCError::FLASH_ERROR;
        }
    }

    return FlashDriver::EFCError::NONE;
}

FlashDriver::EFCError
InternalFlashTestTask::testPageWriteRead(FlashDriver& flash) {
    constexpr uint32_t testAddress = FlashDriver::StartAddress;
    LOG_DEBUG << "Testing Page Write at Address: 0x" << std::hex << testAddress;

    etl::array<uint32_t, FlashDriver::WordsPerPage> writeData{};
    for (size_t i = 0; i < FlashDriver::WordsPerPage; ++i) {
        writeData[i] = i | (i << 8) | (i << 16) | (i << 24);
    }

    auto writeError = flash.writePage(writeData, testAddress);
    if (writeError != FlashDriver::EFCError::NONE) {
        LOG_DEBUG << "Page Write Failed";
        printFlashError(writeError);
        return writeError;
    }

    etl::array<uint32_t, FlashDriver::WordsPerPage> readData{};
    auto readError = flash.readFromMemory(readData,
        FlashDriver::WordsPerPage * sizeof(uint32_t), testAddress);

    if (readError != FlashDriver::EFCError::NONE) {
        LOG_DEBUG << "Page Read Failed";
        printFlashError(readError);
        return readError;
    }

    for (size_t i = 0; i < FlashDriver::WordsPerPage; ++i) {
        if (writeData[i] != readData[i]) {
            LOG_DEBUG << "Data mismatch at index " << i;
            LOG_DEBUG << "Expected: 0x" << std::hex << writeData[i]
                     << " Got: 0x" << readData[i];
            return FlashDriver::EFCError::FLASH_ERROR;
        }
    }

    return FlashDriver::EFCError::NONE;
}

FlashDriver::EFCError
InternalFlashTestTask::testBoundaryConditions(FlashDriver& flash) {
    LOG_DEBUG << "Testing Boundary Conditions";

    etl::array<uint32_t, FlashDriver::WordsPerQuadWord> testData{};

    auto error = flash.writeQuadWord(testData, FlashDriver::StartAddress - 4);
    if (error != FlashDriver::EFCError::ADDRESS_UNSAFE) {
        LOG_DEBUG << "Failed to detect address below start address (0x5F0000)";
        return FlashDriver::EFCError::FLASH_ERROR;
    }

    error = flash.writeQuadWord(testData, FlashDriver::EndAddress);
    if (error != FlashDriver::EFCError::ADDRESS_UNSAFE) {
        LOG_DEBUG << "Failed to detect address beyond end address (0x600000)";
        return FlashDriver::EFCError::FLASH_ERROR;
    }

    error = flash.writeQuadWord(testData, FlashDriver::StartAddress);
    if (error == FlashDriver::EFCError::ADDRESS_UNSAFE) {
        LOG_DEBUG << "Failed to write at start address";
        return error;
    }

    constexpr uint32_t lastValidAddress = FlashDriver::EndAddress -
                                          (FlashDriver::WordsPerQuadWord * sizeof(uint32_t));
    error = flash.writeQuadWord(testData, lastValidAddress);
    if (error == FlashDriver::EFCError::ADDRESS_UNSAFE) {
        LOG_DEBUG << "Failed to write at last valid address";
        return error;
    }

    return FlashDriver::EFCError::NONE;
}

void InternalFlashTestTask::execute() {
    FlashDriver flash;

    LOG_DEBUG << "Starting Internal Flash Tests";
    LOG_DEBUG << "Flash Memory Range: 0x" << std::hex << FlashDriver::StartAddress
              << " - 0x" << FlashDriver::EndAddress;

    while (true) {
        testFlashModule(flash);
        vTaskDelay(pdMS_TO_TICKS(DelayMs));
    }
}