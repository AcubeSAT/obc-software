#include "CANBus.hpp"
#include "Logger.hpp"

namespace CANBus {
    void InitializeCANBus() {
        MCAN1_MessageRAMConfigSet(MCAN1MessageRAM);

        MCAN1_TxEventFifoCallbackRegister(TxFifoCallback, APP_STATE_MCAN_TRANSMIT);
        MCAN1_RxFifoCallbackRegister(MCAN_RX_FIFO_0, RxFifo0Callback, APP_STATE_MCAN_RECEIVE);
    }

    uint8_t DlcToLengthGet(uint8_t dlc) {
        uint8_t msgLength[] = {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 12U, 16U, 20U, 24U, 32U, 48U, 64U};
        return msgLength[dlc];
    }

    uint8_t LengthToDlcGet(uint8_t length) {
        uint8_t dlc = 0;

        if (length <= 8U) {
            dlc = length;
        } else if (length <= 12U) {
            dlc = 0x9U;
        } else if (length <= 16U) {
            dlc = 0xAU;
        } else if (length <= 20U) {
            dlc = 0xBU;
        } else if (length <= 24U) {
            dlc = 0xCU;
        } else if (length <= 32U) {
            dlc = 0xDU;
        } else if (length <= 48U) {
            dlc = 0xEU;
        } else {
            dlc = 0xFU;
        }
        return dlc;
    }

    void TxFifoCallback(uint8_t numberOfTxEvent, uintptr_t context) {
        status = MCAN1_ErrorGet();

        if ((((status & MCAN_PSR_LEC_Msk) == MCAN_ERROR_NONE) ||
             ((status & MCAN_PSR_LEC_Msk) == MCAN_ERROR_LEC_NO_CHANGE)) &&
            static_cast<CANBus::APP_STATES>(context) == APP_STATE_MCAN_TRANSMIT) {
            LOG_INFO << "\r\nSuccessful CAN transmission\r\n";
        }
    }

    void RxFifo0Callback(uint8_t numberOfMessage, uintptr_t context) {
        status = MCAN1_ErrorGet();

        if ((((status & MCAN_PSR_LEC_Msk) == MCAN_ERROR_NONE) ||
             ((status & MCAN_PSR_LEC_Msk) == MCAN_ERROR_LEC_NO_CHANGE)) &&
            static_cast<CANBus::APP_STATES>(context) == APP_STATE_MCAN_RECEIVE) {
            memset(rxFiFo0, 0x00, (numberOfMessage * MCAN1_RX_FIFO0_ELEMENT_SIZE));
            if (MCAN1_MessageReceiveFifo(MCAN_RX_FIFO_0, numberOfMessage, (MCAN_RX_BUFFER *) rxFiFo0))
                LOG_INFO << "\r\nSuccessful CAN receipt\r\n";
            printMessage(numberOfMessage, (MCAN_RX_BUFFER *) rxFiFo0, MCAN1_RX_FIFO0_ELEMENT_SIZE, 0);
        }
    }
}
