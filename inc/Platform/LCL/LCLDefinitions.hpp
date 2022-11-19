#pragma once

#include "LCL.hpp"

namespace LCLDefinitions {
    enum ProtectedDevices : uint8_t {
        NANDFlash = 0,
        MRAM = 1,
        CAN1 = 2,
        CAN2 = 3
    };

    static inline constexpr uint8_t NumberOfProtectedDevices = 4;

    inline static etl::map<ProtectedDevices, LCL, NumberOfProtectedDevices> lclMap = {
            {NANDFlash, LCL(
                    {PWM_CHANNEL_0_MASK, PWM_CHANNEL_0, LCL_NAND_RST_PIN, LCL_NAND_SET_PIN})},
            {MRAM,      LCL(
                    {PWM_CHANNEL_1_MASK, PWM_CHANNEL_1, LCL_MRAM_RST_PIN, LCL_MRAM_SET_PIN})},
            {CAN1,      LCL(
                    {PWM_CHANNEL_3_MASK, PWM_CHANNEL_3, LCL_CAN_1_RST_PIN, LCL_CAN_1_SET_PIN})},
            {CAN2,      LCL(
                    {PWM_CHANNEL_2_MASK, PWM_CHANNEL_2, LCL_CAN_2_RST_PIN, LCL_CAN_2_SET_PIN})}
    };

    void enableAllLCLs() {
        lclMap[NANDFlash].enableLCL();
        lclMap[MRAM].enableLCL();
        lclMap[CAN1].enableLCL();
        lclMap[CAN2].enableLCL();
    }
}


