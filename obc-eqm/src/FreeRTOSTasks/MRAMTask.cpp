#include "MRAMTask.hpp"
#include "MRAMTestData.hpp"

void printMramError(MRAMError error) {
    switch (error) {
        case MRAMError::TIMEOUT:
            LOG_DEBUG << "MRAM Error Timeout";
            break;
        case MRAMError::NOT_READY:
            LOG_DEBUG << "MRAM Error Not Ready";
            break;
        case MRAMError::ADDRESS_OUT_OF_BOUNDS:
            LOG_DEBUG << "MRAM Address Out Of Bounds";
            break;
        case MRAMError::DATA_MISMATCH:
            LOG_DEBUG << "MRAM Data Mismatch";
            break;
        default:
            LOG_DEBUG << "Unknown MRAM Error: " << static_cast<uint8_t>(error);
            break;
    }
}

etl::expected<void, MRAMError> mramSingleByteRwTest(MRAM& mramModule) {
    uint8_t data = 'A';
    etl::random_xorshift rng;
    uint32_t randomAddress = rng() % 0x1FFFFE;
    LOG_DEBUG << "Testing Address: " << randomAddress;

    if (auto error = mramModule.mramWriteByte(randomAddress, data); error != MRAMError::NONE) {
        printMramError(error);
        return etl::unexpected(error);
    }

    data = 0;
    if (auto error = mramModule.mramReadByte(randomAddress, data); error != MRAMError::NONE) {
        printMramError(error);
        return etl::unexpected(error);
    }

    if (data != 'A') {
        LOG_DEBUG << "Read unexpected value: " << data;
        return etl::unexpected(MRAMError::DATA_MISMATCH);
    }

    return {};
}

etl::expected<void, MRAMError> mramMultipleBytesRwTest(MRAM& mramModule) {
    etl::random_xorshift rng;
    // Prevent overflow by subtracting from the maximum address the length of the array to be written
    uint32_t randomAddress = rng() % (0x1FFFFD - mramTestData.size());
    LOG_DEBUG << "Testing Address: " << randomAddress;

    etl::span<const uint8_t> dataSpanWrite(mramTestData.data(), mramTestData.size());
    if (auto error = mramModule.mramWriteData(randomAddress, dataSpanWrite); error != MRAMError::NONE) {
        printMramError(error);
        return etl::unexpected(error);
    }

    etl::array<uint8_t, 200> readData{};
    etl::span<uint8_t> dataSpanRead(readData.data(), readData.size());

    if (auto error = mramModule.mramReadData(randomAddress, dataSpanRead); error != MRAMError::NONE) {
        printMramError(error);
        return etl::unexpected(error);
    }

    if ((dataSpanRead[0] != mramTestData[0]) || 
        (dataSpanRead[dataSpanRead.size() - 1] != mramTestData[mramTestData.size() - 1])) {
        LOG_DEBUG << "Read unexpected data";
        LOG_DEBUG << "First read byte: " << dataSpanRead[0];
        LOG_DEBUG << "Last read byte: " << dataSpanRead[dataSpanRead.size() - 1];
        return etl::unexpected(MRAMError::DATA_MISMATCH);
    }

    return {};
}

etl::expected<void, MRAMError> testMramBoundaryConditions(MRAM& mramModule) {
    uint8_t testByte = 0x55;
    if (auto error = mramModule.mramWriteByte(0, testByte); error != MRAMError::NONE) {
        LOG_DEBUG << "Failed writing to address 0";
        return etl::unexpected(error);
    }

    if (auto error = mramModule.mramWriteByte(0x1FFFFA, testByte); error != MRAMError::NONE) {
        LOG_DEBUG << "Failed writing to max address";
        return etl::unexpected(error);
    }

    if (auto error = mramModule.mramWriteByte(0x1FFFFB, testByte); error != MRAMError::ADDRESS_OUT_OF_BOUNDS) {
        LOG_DEBUG << "Failed to detect address out of bounds";
        return etl::unexpected(error);
    }

    return {};
}

etl::expected<void, MRAMError> testMramDataPatterns(MRAM& mramModule) {
    constexpr uint32_t testAddr = 0x1000;
    constexpr size_t patternSize = 16;
    
    etl::array<uint8_t, patternSize> allOnes;
    etl::array<uint8_t, patternSize> allZeros;
    etl::array<uint8_t, patternSize> alternating;
    etl::array<uint8_t, patternSize> readBuffer;
    
    allOnes.fill(0xFF);
    allZeros.fill(0x00);
    
    for(size_t i = 0; i < patternSize; ++i) {
        alternating[i] = (i % 2) ? 0x55 : 0xAA;
    }

    {
        etl::span<const uint8_t> writeSpan(allOnes.data(), allOnes.size());
        if (auto error = mramModule.mramWriteData(testAddr, writeSpan); error != MRAMError::NONE) {
            LOG_DEBUG << "Failed writing all ones pattern";
            return etl::unexpected(error);
        }

        etl::span<uint8_t> readSpan(readBuffer.data(), readBuffer.size());
        if (auto error = mramModule.mramReadData(testAddr, readSpan); error != MRAMError::NONE) {
            LOG_DEBUG << "Failed reading all ones pattern";
            return etl::unexpected(error);
        }

        for (size_t i = 0; i < patternSize; ++i) {
            if (readBuffer[i] != 0xFF) {
                LOG_DEBUG << "All ones pattern verification failed at index " << i;
                return etl::unexpected(MRAMError::DATA_MISMATCH);
            }
        }
    }

    {
        etl::span<const uint8_t> writeSpan(allZeros.data(), allZeros.size());
        if (auto error = mramModule.mramWriteData(testAddr, writeSpan); error != MRAMError::NONE) {
            LOG_DEBUG << "Failed writing all zeros pattern";
            return etl::unexpected(error);
        }

        etl::span<uint8_t> readSpan(readBuffer.data(), readBuffer.size());
        if (auto error = mramModule.mramReadData(testAddr, readSpan); error != MRAMError::NONE) {
            LOG_DEBUG << "Failed reading all zeros pattern";
            return etl::unexpected(error);
        }
    }

    return {};
}

etl::expected<void, MRAMError> testMramPerformance(MRAM& mramModule) {
    constexpr uint32_t StartAddr = 0x1000;
    constexpr size_t BlockSize = 128;
    constexpr size_t NumBlocks = 10;
    
    etl::array<uint8_t, BlockSize> writeBuffer {0};
    etl::array<uint8_t, BlockSize> readBuffer {0};
    
    for(size_t i = 0; i < NumBlocks; ++i) {
        uint32_t currentAddr = StartAddr + (i * BlockSize);
        writeBuffer.fill(static_cast<uint8_t>(i));
        
        etl::span<const uint8_t> writeSpan(writeBuffer.data(), writeBuffer.size());
        if (auto error = mramModule.mramWriteData(currentAddr, writeSpan); error != MRAMError::NONE) {
            LOG_DEBUG << "Sequential write failed at block " << i;
            return etl::unexpected(error);
        }
    }
    
    for(size_t i = 0; i < NumBlocks; ++i) {
        const uint32_t currentAddr = StartAddr + (i * BlockSize);
        etl::span<uint8_t> readSpan(readBuffer.data(), readBuffer.size());
        
        if (auto error = mramModule.mramReadData(currentAddr, readSpan); error != MRAMError::NONE) {
            LOG_DEBUG << "Sequential read failed at block " << i;
            return etl::unexpected(error);
        }
        
        if (readBuffer[0] != static_cast<uint8_t>(i)) {
            LOG_DEBUG << "Data verification failed at block " << i;
            return etl::unexpected(MRAMError::DATA_MISMATCH);
        }
    }
    
    return {};
}

void testMramModule(MRAM& mramModule) {
    constexpr uint8_t NumTests = 5;
    uint8_t correctResults = 0;

    if (auto result = testMramBoundaryConditions(mramModule)) {
        LOG_DEBUG << "MRAM BOUNDARY CONDITIONS TEST SUCCEEDED";
        correctResults++;
    } else {
        LOG_DEBUG << "MRAM BOUNDARY CONDITIONS TEST FAILED";
    }

    if (auto result = testMramDataPatterns(mramModule)) {
        LOG_DEBUG << "MRAM DATA PATTERNS TEST SUCCEEDED";
        correctResults++;
    } else {
        LOG_DEBUG << "MRAM DATA PATTERNS TEST FAILED";
    }

    if (auto result = testMramPerformance(mramModule)) {
        LOG_DEBUG << "MRAM PERFORMANCE TEST SUCCEEDED";
        correctResults++;
    } else {
        LOG_DEBUG << "MRAM PERFORMANCE TEST FAILED";
    }

    if (auto result = mramSingleByteRwTest(mramModule)) {
        LOG_DEBUG << "MRAM SINGLE BYTE RW TEST SUCCEEDED";
        correctResults++;
    } else {
        LOG_DEBUG << "MRAM SINGLE BYTE RW TEST FAILED";
    }

    if (auto result = mramMultipleBytesRwTest(mramModule)) {
        LOG_DEBUG << "MRAM MULTIPLE BYTES RW TEST SUCCEEDED";
        correctResults++;
    } else {
        LOG_DEBUG << "MRAM MULTIPLE BYTES RW TEST FAILED";
    }

    LOG_DEBUG << "MRAM TESTS COMPLETED";
    LOG_DEBUG << "Correct Results: " << correctResults << "/" << NumTests;
}


void MRAMTask::execute() {
    MRAM mram{SMC::NCS0};

    auto mramLcl = LCLDefinitions::lclArray[LCLDefinitions::MRAM];
    mramLcl.enableLCL();

    auto error = mram.isMRAMAlive();
    if (error != MRAMError::READY) {
        printMramError(error);
        mram.errorHandler(error);
        vTaskSuspend(nullptr);
        return;
    }
    
    LOG_DEBUG << "MRAM Init Success";

    while (true) {
        testMramModule(mram);
        vTaskDelay(pdMS_TO_TICKS(DelayMs));
    }
}