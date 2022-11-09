#pragma once

#include "LCL.hpp"

namespace LCLDefinitions {

    enum class ProtectedDevices : uint8_t {
        NANDFlash = 0,
        MRAM = 1,
        CAN1 = 2,
        CAN2 = 3,
    };

    enum class PWMChannelMasks : PWM_CHANNEL_MASK {
        NANDFlash = PWM_CHANNEL_0_MASK,
        MRAM = PWM_CHANNEL_1_MASK,
        CAN1 = PWM_CHANNEL_3_MASK,
        CAN2 = PWM_CHANNEL_2_MASK
    };

    enum class PWMChannelNumbers : PWM_CHANNEL_NUM {
        NANDFlash = PWM_CHANNEL_0,
        MRAM = PWM_CHANNEL_1,
        CAN1 = PWM_CHANNEL_3,
        CAN2 = PWM_CHANNEL_2
    };

    enum class ResetPins : uint32_t {
        NANDFlash = LCL_NAND_RST_PIN,
        MRAM = LCL_MRAM_RST_PIN,
        CAN1 = LCL_CAN_1_RST_PIN,
        CAN2 = LCL_CAN_2_RST_PIN
    };

    enum class SetPins : uint32_t {
        NANDFlash = LCL_NAND_SET_PIN,
        MRAM = LCL_MRAM_SET_PIN,
        CAN1 = LCL_CAN_1_SET_PIN,
        CAN2 = LCL_CAN_2_SET_PIN
    };

    LCLControlPins nandFlashControlPins = {ResetPins::NANDFlash, SetPins::NANDFlash,
                                           PWMChannelMasks::NANDFlash, PWMChannelNumbers::NANDFlash};
    LCLControlPins mramControlPins = {ResetPins::MRAM, SetPins::MRAM, PWMChannelMasks::MRAM,
                                      PWMChannelNumbers::MRAM};
    LCLControlPins can1ControlPins = {ResetPins::CAN1, SetPins::CAN1, PWMChannelMasks::CAN1,
                                      PWMChannelNumbers::CAN1};
    LCLControlPins can2ControlPins = {ResetPins::CAN2, SetPins::CAN2, PWMChannelMasks::CAN2,
                                      PWMChannelNumbers::CAN2};

    inline std::optional<LCL> nandFlashLCL(LCLDefinitions::nandFlashControlPins);
    inline std::optional<LCL> mramLCL(LCLDefinitions::mramControlPins);
    inline std::optional<LCL> can1LCL(LCLDefinitions::can1ControlPins);
    inline std::optional<LCL> can2LCL(LCLDefinitions::can2ControlPins);

    void turnOnLCLs() {
        nandFlashLCL->openLCL();
        mramLCL->openLCL();
        can1LCL->openLCL();
        can2LCL->openLCL();
    }
}


