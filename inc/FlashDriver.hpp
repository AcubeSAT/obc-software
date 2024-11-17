#pragma once
#include <cstdint>
#include "plib_efc.h"

using FlashAddress = uint32_t;
using FlashData = uint32_t;
using FlashEraseLength = uint32_t;
#ifdef __cplusplus
extern "C" {
#endif
extern uint32_t _efixed;
extern uint32_t _settings_start;
extern uint32_t _settings_end;
#ifdef __cplusplus
}
#endif
class FlashDriver {
public:
    static constexpr uint32_t FLASH_PAGE_SIZE = 512;
    static constexpr uint32_t QUAD_WORD_SIZE = 16;


    bool isAligned(FlashAddress address, uint32_t alignment);
    bool isAddressSafe(FlashAddress address);

    FlashDriver();
    EFC_ERROR QuadWordWrite(FlashData* data, FlashAddress address);
    EFC_ERROR PageWrite(FlashData* data, FlashAddress address);
    EFC_ERROR Read(FlashData* data, FlashEraseLength length, FlashAddress address);
    EFC_ERROR SectorErase(FlashAddress address);
    bool IsReady();
};