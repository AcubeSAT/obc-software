#pragma once

#include <cstdint>
#include "Definitions.hpp"
#include "plib_pio.h"

#define MCP9808_TWI_PORT 1

#define UART_PERIPHERAL_REGISTER UART0_REGS->UART_THR
#define UART_Initialize UART0_Initialize

#define TC_HANDLING_UART_ReadCallbackRegister UART0_ReadCallbackRegister
#define TC_HANDLING_UART_ReadCountGet UART0_ReadCountGet
#define TC_HANDLING_UART_ErrorGet UART0_ErrorGet
#define TC_HANDLING_UART_Read UART0_Read
#define TC_HANDLING_UART_ERROR UART_ERROR
#define OBC_EQM_LCL

namespace CAN {
    /**
     * The ID for the current node as described in DDJF_OBDH
     */
    inline const NodeIDs NodeID = OBC;

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
    inline const PIO_PIN CAN_SILENT_1 = CAN_SILENT_1_PIN;

    inline const PIO_PIN CAN_SILENT_2 = CAN_SILENT_2_PIN;
}

/**
 * Used to control COBS Encoding for Log Messages in the UART Gatekeeper task.
 */
inline const bool LogsAreCOBSEncoded = true;
