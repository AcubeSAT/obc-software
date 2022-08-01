#ifndef OBC_SOFTWARE_OBC_DEFINITIONS_HPP
#define OBC_SOFTWARE_OBC_DEFINITIONS_HPP

#include <cstdint>

/**
 * @defgroup Definitions of OBC_SOFTWARE Defined Constants
 *
 * This file contains constant definitions that are used in the OBC_SOFTWARE configuration.
 *
 */

/**
 * Maximum string size for a LogLevel is 9 characters long
 */
inline const uint8_t MaxLogNameSize = 9;

/**
 * TickType_t is a uint32_t number. Its string representation is at most 10 digits long.
 */
inline const uint8_t MaxTickCountStringSize = 10;

/**
 * Maximum size for a string representation of a service or message type identifier
 */
inline const uint8_t MaxTypeIDStringSize = 2;

/**
 * The maximum code number an analog signal can be converted into by the ADC of the AFEC peripheral with 12-bit resolution
 */
inline const uint16_t MaxADCValue = 4095;

/**
 * The positive voltage reference of the MCU
 */
inline const uint16_t PositiveVoltageReference = 3300;

/**
 * The typical slope of voltage versus temperature of the internal temperature sensor
 */
inline const float TemperatureSensitivity = 2.33;

/**
 * The reference temperature of the internal temperature sensor for the voltage-to-temperature conversion
 */
inline const uint8_t ReferenceTemperature = 25;

/**
 * The size of the queue used to communicate with the UART Gatekeeper task
 */
inline const uint8_t UARTQueueSize = 5;

/**
 * The typical voltage output of the DAC of the AFEC channel at 25 Celsius
 */
inline const uint16_t TypicalVoltageAt25 = 720;

/**
 * The maximum byte capacity of a byte buffer containing TC bytes
 */
inline const uint8_t TCByteBufferSize = 64;

/**
 * The maximum byte capacity of a byte queue that stores incoming TC bytes
 */
inline const uint8_t TCByteQueueLength = 64;

/**
 * Logger will output messages using RTT
 */
inline const bool useRTT = true;

/**
 * Logger will output messages using UART
 */
inline const bool useUART = true;

/**
 * Logger will output messages using CAN
 */
inline const bool useCAN = false;

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

#endif //OBC_SOFTWARE_OBC_DEFINITIONS_HPP
