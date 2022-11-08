#pragma once

#include "LCL.hpp"
#include "peripheral/pio/plib_pio.h"

namespace LCLDefinitions {

//    /**
//     * @enum PWM channels used to set the current threshold for the TLC555 timer.
//     * PWM0 of ATSAMV71 is used for all thresholds.
//     */
//    enum class PWMChannelMasks : uint8_t {
//        NANDFlash = PWM_CHANNEL_0_MASK, ///< NAND Flash
//        MRAM = PWM_CHANNEL_1_MASK, ///< MRAM
//        CAN1 = PWM_CHANNEL_3_MASK, ///< CAN1
//        CAN2 = PWM_CHANNEL_2_MASK ///< CAN2
//    };
//
//    /**
//     * @enum PWM channels used to set the current threshold for the TLC555 timer.
//     */
//    enum class PWMChannelNumbers : uint8_t {
//        NANDFlash = PWM_CHANNEL_0, ///< NAND Flash
//        MRAM = PWM_CHANNEL_1, ///< MRAM
//        CAN1 = PWM_CHANNEL_3, ///< CAN1
//        CAN2 = PWM_CHANNEL_2 ///< CAN2
//    };
//
//    /**
//     * @enum GPIOs used reset the LCL, specifically the TLC555 IC.
//     * Active low.
//     * Initial value given by a pull-up resistor to prevent undefined behavior during MCU
//     * reset/start-up.
//     */
//    enum class ResetPins : uint8_t {
//        NANDFlash = PIO_PIN_PC15, ///< NAND Flash, LCL_CAN_1_RST_PIN plib_pio.h
//        MRAM = PIO_PIN_PE4, ///< MRAM
//        CAN1 = PIO_PIN_PD24, ///< CAN1
//        CAN2 = PIO_PIN_PA26 ///< CAN2
//    };
//
//    /**
//     * @enum GPIOs used reset the LCL, specifically the TLC555 IC.
//     * Active low.
//     * Initial value given by a pull-up resistor to prevent undefined behavior during MCU
//     * reset/start-up.
//     */
//    enum class SetPins : uint8_t {
//        NANDFlash = PIO_PIN_PC13, ///< MRAM
//        MRAM = PIO_PIN_PA17, ///< NAND Flash
//        CAN1 = PIO_PIN_PD26, ///< CAN1
//        CAN2 = PIO_PIN_PD22 ///< CAN2
//    };
//
//
//    /**
//     * @enum Devices protected by LCLs
//     */
//    enum class ProtectedDevices : uint8_t {
//        NANDFlash = 0,
//        MRAM = 1,
//        CAN1 = 2,
//        CAN2 = 3
//    };

    LCLControlPins nandFlashControlPins = {LCL_NAND_RST_PIN, LCL_NAND_SET_PIN};
    LCLControlPins mramControlPins = {LCL_MRAM_RST_PIN, LCL_MRAM_SET_PIN};
    LCLControlPins can1ControlPins = {LCL_CAN_1_RST_PIN, LCL_CAN_1_SET_PIN};
    LCLControlPins can2ControlPins = {LCL_CAN_2_RST_PIN, LCL_CAN_2_SET_PIN};

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


