#pragma once

#include "LCLPWM.hpp"
#include "etl/array.h"

namespace LCLDefinitions {
    enum ProtectedDevices : uint8_t {
        NANDFlash = 0,
        MRAM = 1,
        CAN1 = 2,
        CAN2 = 3
    };

    static inline constexpr uint8_t NumberOfProtectedDevices = 4;

    inline static etl::array<LCLPWM<PeripheralNumber::Peripheral_0>, NumberOfProtectedDevices> lclArray = {
            LCLPWM<PeripheralNumber::Peripheral_0>(PWM_CHANNEL_0, PWM_CHANNEL_0_MASK, LCL_NAND_RST_PIN, LCL_NAND_SET_PIN, LCLPWM<PeripheralNumber::Peripheral_0>::PWMThreshold::NAND),
            LCLPWM<PeripheralNumber::Peripheral_0>(PWM_CHANNEL_1, PWM_CHANNEL_1_MASK, LCL_MRAM_RST_PIN, LCL_MRAM_SET_PIN, LCLPWM<PeripheralNumber::Peripheral_0>::PWMThreshold::MRAM),
            LCLPWM<PeripheralNumber::Peripheral_0>(PWM_CHANNEL_3, PWM_CHANNEL_3_MASK, LCL_CAN_1_RST_PIN, LCL_CAN_1_SET_PIN, LCLPWM<PeripheralNumber::Peripheral_0>::PWMThreshold::CAN),
            LCLPWM<PeripheralNumber::Peripheral_0>(PWM_CHANNEL_2, PWM_CHANNEL_2_MASK, LCL_CAN_2_RST_PIN, LCL_CAN_2_SET_PIN, LCLPWM<PeripheralNumber::Peripheral_0>::PWMThreshold::CAN)
    };
}