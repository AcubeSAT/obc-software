#ifndef OBC_SOFTWARE_CANBUS_H
#define OBC_SOFTWARE_CANBUS_H

#include "definitions.h"
#include "OBC_Definitions.hpp"

namespace CANBus{
    /**
     * Storage for MCAN1 input and output buffers.
     * When the MCAN addresses the Message RAM, it addresses 32-bit words, not single bytes.
     * The message RAM needs to reside in a separate section of memory, set up through the linker script.
     */
    static uint8_t MCAN1MessageRAM[MCAN1_MESSAGE_RAM_CONFIG_SIZE] __attribute__((aligned (32)))__attribute__((section (".ram_nocache")));

    /**
     * Transmission Buffer.
     */
    static uint8_t txFiFo[MCAN1_TX_FIFO_BUFFER_SIZE];

    /**
     * Receipt Buffer for RX_FIFO0.
     */
    volatile static uint8_t rxFiFo0[MCAN1_RX_FIFO0_SIZE];

    /**
     * Conversion of an extended ID format to a standard ID.
     * @param id A 29 bit long extended Node ID.
     * @return A 11 bit long standard Node ID.
     */
    inline uint32_t READ_ID(uint32_t id) { return id >> 18; }

    /**
     * Conversion of a standard ID to an extended ID format.
     * @param id An 11 bit long standard Node ID.
     * @return A 29 bit long extended Node ID.
     */
    inline uint32_t WRITE_ID(uint32_t id) { return id << 18; }

    /**
     * Node ID for the OBC Board.
     */
    static uint32_t obcID = 0x0;

    /**
     * Possible states for the peripheral, to be used as arguments in the callback functions.
     */
    typedef enum {
        APP_STATE_MCAN_RECEIVE,
        APP_STATE_MCAN_TRANSMIT,
    } APP_STATES;

    /**
     * This function decodes the parameters of the message along with it's data and prints it using logging functions
     * @param rxBuf The output of MessageReceive
     */
    void printMessage(MCAN_RX_BUFFER *rxBuf);

    /**
     * This function sets the static arrays for the storage of buffers and registers the interrupt callback functions.
     */
    void InitializeCANBus();

    /**
     * This function decodes the data length code to get the largest expected size of the message.
     *
     * @param dlc The data length code
     * @return The length of the message in bytes
     */
    uint8_t DlcToLengthGet(uint8_t dlc);

    /**
     * This function encodes the message of the message to the smallest data length code that it fits in.
     *
     * @param length The length of the message in bytes
     * @return The data length code
     */
    uint8_t LengthToDlcGet(uint8_t length);

    /**
     * You should not call this function by yourself.
     * This function logs a successful CAN Bus transmission.
     *
     * @param context The state of the peripheral when the function is called.
     */
    void TxFifoCallback(uintptr_t context);

    /**
     * You should not call this function by yourself.
     * This function initiates a message receipt from the peripheral to the processor.
     *
     * @param numberOfMessages The number of messages to be received from the peripheral
     * @param context The state of the peripheral when the function is called.
     */
    void RxFifo0Callback(uint8_t numberOfMessages, uintptr_t context);
}

#endif //OBC_SOFTWARE_CANBUS_H
