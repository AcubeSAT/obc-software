#ifndef OBC_SOFTWARE_CANDRIVER_H
#define OBC_SOFTWARE_CANDRIVER_H

#include <cstdint>
#include "ECSS_Definitions.hpp"
#include "Frame.hpp"
#include "peripheral/mcan/plib_mcan1.h"
#include "peripheral/mcan/plib_mcan0.h"

namespace CAN {
    /**
     * A basic driver for the CAN Peripherals of the SAMV71 family of processors. This driver includes encoding/decoding
     * functions for the Data Length Code as well as the ID when used in normal addressing mode. There are two interrupt
     * callback functions, one for registering a transmission plus logging an error if needed, and one for passing the
     * incoming CAN::Frames to the higher level services in the application. This driver handles both peripherals,
     * while keeping only one active through a parameter for transmission, and disabling interrupts for receipt.
     *
     * @note CAN Normal Addressing requires the NodeID to be at most 11 bits long.
     *
     * @note There are two peripherals for the CAN Bus. The main bus is considered as MCAN1, since that is the one
     * available on the development board.
     *
     * @example @code
     * uint32_t id = 0x4; // Specify the sending Node ID.
     * etl::vector<uint8_t, 8> data = {0,1,2,3,4,5,6,7}; // Specify an array of data, up to 64 bytes.
     * CAN::Frame message = {id, data}; // Create a CAN::Frame object.
     * CAN::Driver::send(message, Application::Main); // Use the included send function to send a message on the Main bus.
     * @endcode
     */
    class Driver {
    private:
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

    public:
        /**
         * An area of memory the HAL uses to house incoming/outgoing buffers for the peripheral.
         */
        static inline uint8_t mcan0MessageRAM[MCAN0_MESSAGE_RAM_CONFIG_SIZE] __attribute__((aligned (32))) __attribute__((section (".ram_nocache")));

        /**
         * An area of memory the HAL uses to house incoming/outgoing buffers for the peripheral.
         */
        static inline uint8_t mcan1MessageRAM[MCAN1_MESSAGE_RAM_CONFIG_SIZE] __attribute__((aligned (32))) __attribute__((section (".ram_nocache")));

        /**
         * Possible states for the peripheral, to be used as arguments in the callback functions.
         */
        enum AppStates : uint8_t {
            Receive, Transmit,
        };

        /**
         * The available buses to use.
         */
        enum ActiveBus : uint8_t {
            Redundant = 0x0, Main = 0x1
        };

        /**
         * Sets the appropriate interrupt handlers, configures the storage area for incoming/outgoing buffers and
         * keeps only a single peripheral's interrupts active.
         */
        static void initialize();

        /**
         * Logs a successful CAN Bus transmission.
         * It is registered as a callback to be automatically called by Microchip's HAL whenever
         * there is a message transmission on TX FIFO.
         *
         * @param context The state of the peripheral when the function is called.
         * The above parameter is a uintptr_t type for compatibility with the HAL, and is casted to APPStates.
         */
        static void mcan0TxFifoCallback(uintptr_t context);

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
        static void mcan0RxFifo0Callback(uint8_t numberOfMessages, uintptr_t context);

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
        static void mcan0RxFifo1Callback(uint8_t numberOfMessages, uintptr_t context);

        /**
         * Logs a successful CAN Bus transmission.
         * It is registered as a callback to be automatically called by Microchip's HAL whenever
         * there is a message transmission on TX FIFO.
         *
         * @param context The state of the peripheral when the function is called.
         * The above parameter is a uintptr_t type for compatibility with the HAL, and is casted to APPStates.
         */
        static void mcan1TxFifoCallback(uintptr_t context);

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
        static void mcan1RxFifo0Callback(uint8_t numberOfMessages, uintptr_t context);

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
        static void mcan1RxFifo1Callback(uint8_t numberOfMessages, uintptr_t context);

        /**
         * Logs messages that are in the Rx buffer
         * @param rxBuf The RX Buffer that the messages are stored
         */
        static void logMessage(const MCAN_RX_BUFFER &rxBuf, ActiveBus incomingBus);

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
         * Transforms a frame ID to conform to the CAN Standard.
         * The implementation shifts non-extended IDs by 18 bits to ease debugging with example projects.
         * @param id The ID as specified in the standard.
         * @return The ID that's sent over the network.
         *
         * @note All IDs should be at most 11 bits long as the non-extended ID scheme is used. The function gets/returns
         * a 32-bit ID to accomodate the shift.
         */
        static inline uint32_t writeId(uint32_t id) {
            return id << 18;
        }

        /**
         * Transforms the ID from the CAN Standard to match a frame ID.
         * @param id The ID that was received from the network.
         * @return The ID as specified in the standard.
         *
         * @note All IDs should be at most 11 bits long as the non-extended ID scheme is used. The function gets/returns
         * a 32-bit ID to accomodate the shift.
         */
        static inline uint32_t readId(uint32_t id) {
            return id >> 18;
        }

        /**
         * Immediately ends a CAN Message
         * @param message The message to be sent.
         */
        static void send(const CAN::Frame &message);

        /**
         * Converts an MCAN_RX_BUFFER object into a CAN::Frame.
         * @param rxBuffer The incoming buffer.
         * @return A CAN::Frame.
         */
        static CAN::Frame getFrame(const MCAN_RX_BUFFER &rxBuffer);
    };
}

#endif //OBC_SOFTWARE_CANDRIVER_H
