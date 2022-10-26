#ifndef OBC_SOFTWARE_CANDRIVER_H
#define OBC_SOFTWARE_CANDRIVER_H

#include <cstdint>
#include "ECSS_Definitions.hpp"
#include "Frame.hpp"
#include "peripheral/mcan/plib_mcan1.h"

namespace CAN {
    /**
     * A basic driver for the included CAN Peripheral. This driver includes encoding/decoding functions for the
     * Data Length Code as well as the ID when used in normal addressing mode. There are two interrupt callback functions,
     * one for registering a transmission plus logging an error if needed, and one for passing the incoming CAN::Frames
     * to the higher level services in the application.
     *
     * @note CAN Normal Addressing requires the NodeID to be at most 11 bits long.
     *
     * @example @code
     * uint32_t id = 0x4; //Specify the sending Node ID
     * etl::array<uint8_t, 8> data = {0,1,2,3,4,5,6,7}; //Specify an array of data
     * CAN::Frame message = {id, data}; //Create a CAN::Frame object
     * CAN::Driver::send(message); //Use the included send function
     * @endcode
     */
    class Driver {
    public:
        /**
         * An area of memory the HAL uses to house incoming/outgoing buffers for the peripheral.
         */
        static inline uint8_t mcan1MessageRAM[MCAN1_MESSAGE_RAM_CONFIG_SIZE] __attribute__((aligned (32))) __attribute__((section (".ram_nocache")));

        /**
         * Buffer that stores a message that is ready to be sent
         */
        static inline MCAN_TX_BUFFER txFifo;

        /**
         * Buffer that stores a received message that is to be processed.
         * In this setup, rxFifo0 is used to store TP Messages that usually span across multiple CAN::Frames
         */
        static inline MCAN_RX_BUFFER rxFifo0;

        /**
         * Buffer that stores a received message that is to be processed.
         * In this setup, rxFifo1 is used to store normal messages that are contained in a single CAN::Frame
         */
        static inline MCAN_RX_BUFFER rxFifo1;

        /**
         * Possible states for the peripheral, to be used as arguments in the callback functions.
         */
        enum AppStates : uint8_t {
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
         * In this setup, messages using the TP Protocol will be moved to RX FIFO 0, requiring further parsing
         * using the gatekeeper task.
         *
         * @param numberOfMessages The number of messages to be received from the peripheral
         * @param context The state of the peripheral when the function is called.
         * The above parameter is a uintptr_t type for compatibility with the HAL, and is casted to APPStates.
         */
        static void rxFifo0Callback(uint8_t numberOfMessages, uintptr_t context);

        /**
         * Initiates a message receipt from the peripheral to the processor.
         * It is registered as a callback to be automatically called by Microchip's HAL whenever
         * there is a message receipt on RX FIFO 1.
         *
         * In this setup, all received messages are contained in a single frame and will immediately be processed
         * in this callback.
         *
         * @param numberOfMessages The number of messages to be received from the peripheral
         * @param context The state of the peripheral when the function is called.
         * The above parameter is a uintptr_t type for compatibility with the HAL, and is casted to APPStates.
         */
        static void rxFifo1Callback(uint8_t numberOfMessages, uintptr_t context);

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
