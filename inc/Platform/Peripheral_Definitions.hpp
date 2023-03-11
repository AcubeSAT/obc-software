#pragma once

#define MCP9808_TWI_PORT 2

namespace CAN {
    /**
     * The ID for the current node as described in DDJF_OBDH
     */
    inline const uint8_t NodeID = 0x0;

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
}

/**
 * Used to control COBS Encoding for Log Messages in the UART Gatekeeper task.
 */
inline const bool LogsAreCOBSEncoded = false;