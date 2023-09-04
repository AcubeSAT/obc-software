#pragma once

#include "Definitions.hpp"
#include "plib_pio.h"

#define MCP9808_TWI_PORT 2

#define UART_PERIPHERAL_REGISTER USART1_REGS->US_THR

#define UART_Initialize USART1_Initialize

namespace CAN {
    /**
     * The ID for the current node as described in DDJF_OBDH
     */
    inline const CAN::NodeIDs NodeID = OBC;

    /**
     * The maximum of the length of the queue for incoming/outgoing CAN frames.
     */
    inline const uint8_t FrameQueueSize = 20;

    /**
     * The maximum size for the data field of a CAN-TP message.
     */
    inline const uint16_t TPMessageMaximumSize = 256;

    /**
     * The maximum numbers of parameters, function arguments etc. inside a single CAN-TP Message.
     */
    inline const uint8_t TPMessageMaximumArguments = 10;

    /**
     * CAN_SILENT pins for each CAN transceiver.
     */
    inline const PIO_PIN CAN_SILENT_1 = PIO_PIN_NONE;

    inline const PIO_PIN CAN_SILENT_2 = PIO_PIN_NONE;
}

/**
 * Used to control COBS Encoding for Log Messages in the UART Gatekeeper task.
 */
inline const bool LogsAreCOBSEncoded = false;