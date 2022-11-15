#pragma once

#include "LCL.hpp"

namespace LCLDefinitions {
    enum ProtectedDevices : uint8_t {
        NANDFlash = 0,
        MRAM = 1,
    };
    static inline constexpr uint8_t NumberOfProtectedDevices = 4;

    static inline constexpr etl::array<LCLDeviceControl, NumberOfProtectedDevices>
            lclDevicesControlPins = {
            {"NANDFlash", PWM_CHANNEL_0_MASK, PWM_CHANNEL_0, LCL_NAND_RST_PIN, LCL_NAND_SET_PIN},
            {"MRAM", PWM_CHANNEL_1_MASK, PWM_CHANNEL_1, LCL_MRAM_RST_PIN, LCL_MRAM_SET_PIN},
            {"CAN1", PWM_CHANNEL_3_MASK, PWM_CHANNEL_3, LCL_CAN_1_RST_PIN, LCL_CAN_1_SET_PIN},
            {"CAN2", PWM_CHANNEL_2_MASK, PWM_CHANNEL_2, LCL_CAN_2_RST_PIN, LCL_CAN_2_SET_PIN}
    };

    inline std::optional<LCL> nandFlashLCL(protectedDevices[0]);
    inline std::optional<LCL> mramLCL(protectedDevices[1]);
    inline std::optional<LCL> can1LCL(protectedDevices[2]);
    inline std::optional<LCL> can2LCL(protectedDevices[3]);

    void turnOnLCLs() {
        nandFlashLCL->enableLCL();
        mramLCL->enableLCL();
        can1LCL->enableLCL();
        can2LCL->enableLCL();
    }
}


