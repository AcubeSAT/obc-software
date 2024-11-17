// FlashDriver.cpp
#include "FlashDriver.hpp"
#include "Logger.hpp"
FlashDriver::FlashDriver() {
    EFC_Initialize();
}

bool FlashDriver::isAligned(FlashAddress address, uint32_t alignment) {
    return (address % alignment) == 0;
}

bool FlashDriver::isAddressSafe(FlashAddress address) {
    // Check if address is within settings area
    LOG_DEBUG << "_settings_start: " << _settings_start << "_settings_end" << _settings_end << "Adress: " << address;
    return (address >= reinterpret_cast<uint32_t>(_settings_start) &&
            address < reinterpret_cast<uint32_t>(_settings_end));
}

EFC_ERROR FlashDriver::QuadWordWrite(FlashData* data, FlashAddress address) {
//    if (!isAligned(address, QUAD_WORD_SIZE) || !isAddressSafe(address)) {
//        return EFC_CMD_ERROR;
//    }

    return EFC_QuadWordWrite((uint32_t*)data, address) ? EFC_ERROR_NONE : EFC_CMD_ERROR;
}

EFC_ERROR FlashDriver::PageWrite(FlashData* data, FlashAddress address) {
//    if (!isAligned(address, FLASH_PAGE_SIZE) || !isAddressSafe(address)) {
//        return EFC_CMD_ERROR;
//    }

    return EFC_PageWrite((uint32_t*)data, address) ? EFC_ERROR_NONE : EFC_CMD_ERROR;
}

EFC_ERROR FlashDriver::Read(FlashData* data, FlashEraseLength length, FlashAddress address) {
//    if (!isAligned(address, 4)) {
//        return EFC_CMD_ERROR;
//    }

    return EFC_Read((uint32_t*)data, length, address) ? EFC_ERROR_NONE : EFC_CMD_ERROR;
}

EFC_ERROR FlashDriver::SectorErase(FlashAddress address) {
    LOG_DEBUG << "FlashDriver::SectorErase called with address 0x" << address;

//    if (!isAligned(address, FLASH_PAGE_SIZE)) {
//        LOG_DEBUG << "Address not aligned to page size";
//        return EFC_CMD_ERROR;
//    }
//
//    if (!isAddressSafe(address)) {
//        LOG_DEBUG << "Address not in safe range";
//        return EFC_CMD_ERROR;
//    }

    bool success = EFC_SectorErase(address);
    LOG_DEBUG << "EFC_SectorErase returned: " << success;

    return success ? EFC_ERROR_NONE : EFC_CMD_ERROR;
}

bool FlashDriver::IsReady() {
    return !EFC_IsBusy();
}