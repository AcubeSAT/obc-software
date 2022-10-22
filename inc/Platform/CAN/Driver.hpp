#ifndef OBC_SOFTWARE_CANDRIVER_H
#define OBC_SOFTWARE_CANDRIVER_H

#include <cstdint>
#include "ECSS_Definitions.hpp"
#include "Frame.hpp"
#include "peripheral/mcan/plib_mcan1.h"

namespace CAN {
    class Driver {
    public:
        static inline uint8_t mcan1MessageRAM[MCAN1_MESSAGE_RAM_CONFIG_SIZE] __attribute__((aligned (32)));

        /**
         * Buffer that stores a message that is ready to be sent
         */
        static inline MCAN_TX_BUFFER txFifo;

        /**
         * Buffer that stores a received message that is to be processed.
         */
        static inline MCAN_RX_BUFFER rxFifo0;

        /**
         * Possible states for the peripheral, to be used as arguments in the callback functions.
         */
        enum AppStates: uint8_t {
            Receive, Transmit,
        };

        /**
         * Logs a successful CAN Bus transmission.
         * It is registered as a callback to be automatically called by Microchip's HAL whenever
         * there is a message transmission on TX FIFO.
         *
         * @param context The state of the peripheral when the function is called.
         * The above parameter is a uintptr_t type for compatibility with the HAL, and is casted to APPStates.
         */
        static void txFifoCallback(uintptr_t context);

        /**
         * Initiates a message receipt from the peripheral to the processor.
         * It is registered as a callback to be automatically called by Microchip's HAL whenever
         * there is a message receipt on RX FIFO 0.
         *
         * @param numberOfMessages The number of messages to be received from the peripheral
         * @param context The state of the peripheral when the function is called.
         * The above parameter is a uintptr_t type for compatibility with the HAL, and is casted to APPStates.
         */
        static void rxFifo0Callback(uint8_t numberOfMessages, uintptr_t context);

        /**
         * Logs messages that are in the Rx buffer
         * @param rxBuf The RX Buffer that the messages are stored
         */
        static void logMessage(const MCAN_RX_BUFFER &rxBuf);

        /**
         * Decodes the data length code to get the largest expected size of the message.
         *
         * @param dlc The data length code
         * @return The length of the message in bytes
         */
        static uint8_t convertDlcToLength(uint8_t dlc);

        /**
         * Encodes the length of the message body to the smallest data length code that it fits in.
         *
         * @param length The length of the message in bytes
         * @return The data length code
         */
        static uint8_t convertLengthToDLC(uint8_t length);

        /**
         * Transforms a frame ID to conform to the CAN Standard
         * @param id The actual ID
         * @return The outgoing ID
         */
        static inline uint32_t writeId(uint32_t id) {
            return id << 18;
        }

        /**
         * Transforms the ID from the CAN Standard to match a frame ID
         * @param id The incoming ID
         * @return The actual ID
         */
        static inline uint32_t readId(uint32_t id) {
            return id >> 18;
        }

        /**
         * Sends a CAN Message
         * @param message The message to be sent.
         */
        static void send(const CAN::Frame &message);
    };
}

#endif //OBC_SOFTWARE_CANDRIVER_H
