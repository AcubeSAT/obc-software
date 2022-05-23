#ifndef OBC_SOFTWARE_CANBUS_H
#define OBC_SOFTWARE_CANBUS_H

#include "definitions.h"
#include "OBC_Definitions.hpp"

namespace CANBus{
    static uint8_t MCAN1MessageRAM[MCAN1_MESSAGE_RAM_CONFIG_SIZE] __attribute__((aligned (32)))__attribute__((section (".ram_nocache")));

    static uint8_t txFiFo[MCAN1_TX_FIFO_BUFFER_SIZE];
    static uint8_t rxFiFo0[MCAN1_RX_FIFO0_SIZE];

    inline uint8_t READ_ID(uint32_t id) { return id >> 18; }
    inline uint8_t WRITE_ID(uint32_t id) { return id << 18; }

    static uint32_t obcID = 0x0;
    static uint32_t status = 0;

    typedef enum {
        APP_STATE_MCAN_RECEIVE,
        APP_STATE_MCAN_TRANSMIT,
        APP_STATE_MCAN_IDLE,
    } APP_STATES;

    volatile static APP_STATES state = APP_STATE_MCAN_IDLE;

    void printMessage(uint8_t numberOfMessage, MCAN_RX_BUFFER *rxBuf, uint8_t rxBufLen, uint8_t rxFifoBuf);

    void InitializeCANBus();

    uint8_t DlcToLengthGet(uint8_t dlc);

    uint8_t LengthToDlcGet(uint8_t length);

    void TxFifoCallback(uintptr_t context);

    void RxFifo0Callback(uint8_t numberOfMessage, uintptr_t context);
}

#endif //OBC_SOFTWARE_CANBUS_H
