#pragma once

#include "etl/String.hpp"
#include "time.h"

namespace BootCounter {
    /**
     * Enumeration of the General Purpose Backup Registers (GPBR) used in the boot counter parameter
     * implementation.
     */
    enum BackupRegisters : uint8_t {
        /**
         * Defines which one of the eight backup registers will be used to distinguish software from
         * hardware resets.
         */
        UnexpectedResetRegister = 0,
        /**
         * Defines which one of the eight backup registers will be used to save the boot counter variable.
         */
        BootCounterRegister = 1
    };

    /**
     * When this value is detected inside the \ref UnexpectedResetRegister a software reset is acknowledged,
     * otherwise an unexpected reset has occurred.
     */
    inline const uint8_t SoftwareResetValue = 1;

    /**
     * Defines the backup register's value after it is cleared.
     */
    inline const uint8_t ClearRegisterValue = 0;

    /**
     * A counter limit for hardware reset simulation.
     * @see incrementBootCounter
     */
    inline const uint16_t BootCounterLimit = 1000;
}

/**
 * Number of bytes used for the basic time units of the CUC header for the RTC transform
 */
inline constexpr uint8_t CUCSecondsBytes = 4;

/**
 * Number of bytes used for the fractional time units of the CUC header for the RTC transform
 */
inline constexpr uint8_t CUCFractionalBytes = 0;

/**
 * Contains initial epoch values for spacecraft time
 */
inline const tm EpochTime = {.tm_sec = 0, .tm_min = 0, .tm_hour = 0, .tm_mday = 1, .tm_mon = 0, .tm_year = 2022};

namespace LogSource {
    /**
    * The maximum number of letters in a string representation of a subsystem's name.
    */
    inline constexpr uint8_t MaximumLettersInSubsystemName = 8;

    /**
     * The maximum number of Logging Sources
     */
    inline constexpr uint8_t NumberOfLogSources = 5;

    /**
     * The subsystem to be used, if no other source is defined using the stream operator.
     */
    extern String<MaximumLettersInSubsystemName> currentSubsystem;
}

namespace CAN {
    /**
     * CAN Nodes, as specified in DDJF_OBDH.
     */
    enum NodeIDs : uint8_t {
        OBC = 0x0, COMMS = 0x1, ADCS = 0x2, SU = 0x3, ExternalMCU = 0x4
    };
}
