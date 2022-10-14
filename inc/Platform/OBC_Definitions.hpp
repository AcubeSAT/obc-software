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
 * The maximum length of a TC received from usart.
 */
inline const uint8_t MaxUsartTCSize = 64;

/**
 * The capacity of the queue holding TC messages received externally.
 */
inline const uint8_t TCQueueCapacity = 10;

namespace CAN {
    /**
     * The ID for the current node as described in DDJF_OBDH
     */
    inline const uint8_t NodeID = 0x0;

    /**
     * The maximum of the length of the queue for incoming/outgoing CAN packets.
     */
    inline const uint8_t PacketQueueSize = 20;

    /**
     * The maximum size for the data field of a CAN-TP message.
     */
    inline const uint16_t TPMessageMaximumSize = 256;

    /**
     * The maximum numbers of parameters, function arguments etc. inside a single CAN-TP Message.
     */
    inline const uint8_t TPMessageMaximumArguments = 10;
}

#endif //OBC_SOFTWARE_OBC_DEFINITIONS_HPP
