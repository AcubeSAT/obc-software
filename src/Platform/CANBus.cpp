#include "CANBus.hpp"
#include "Logger.hpp"
#include "ECSS_Definitions.hpp"

namespace CANBus {
    void InitializeCANBus() {
        MCAN1_MessageRAMConfigSet(MCAN1MessageRAM);

        MCAN1_TxFifoCallbackRegister(TxFifoCallback, APP_STATE_MCAN_TRANSMIT);
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

    void TxFifoCallback(uintptr_t context) {
        status = MCAN1_ErrorGet();

        if ((((status & MCAN_PSR_LEC_Msk) == MCAN_ERROR_NONE) ||
             ((status & MCAN_PSR_LEC_Msk) == MCAN_ERROR_LEC_NO_CHANGE)) &&
            static_cast<CANBus::APP_STATES>(context) == APP_STATE_MCAN_TRANSMIT) {
            LOG_INFO << "Successful CAN transmission\r\n";
        }
    }

    void RxFifo0Callback(uint8_t numberOfMessage, uintptr_t context) {
        status = MCAN1_ErrorGet();

        if ((((status & MCAN_PSR_LEC_Msk) == MCAN_ERROR_NONE) ||
             ((status & MCAN_PSR_LEC_Msk) == MCAN_ERROR_LEC_NO_CHANGE)) &&
            static_cast<CANBus::APP_STATES>(context) == APP_STATE_MCAN_RECEIVE) {
            memset(rxFiFo0, 0x00, (numberOfMessage * MCAN1_RX_FIFO0_ELEMENT_SIZE));
            if (MCAN1_MessageReceiveFifo(MCAN_RX_FIFO_0, numberOfMessage, (MCAN_RX_BUFFER *) rxFiFo0))
                printMessage(1, (MCAN_RX_BUFFER *) rxFiFo0, MCAN1_RX_FIFO0_SIZE, MCAN_RX_FIFO_0)   ;
        }
    }

    void printMessage(uint8_t numberOfMessage, MCAN_RX_BUFFER *rxBuf, uint8_t rxBufLen, uint8_t rxFifoBuf) {
        uint8_t length;
        uint8_t msgLength;
        uint32_t id;

        auto message = String<ECSSMaxStringSize>("CAN Message: ");
        id = rxBuf->xtd ? rxBuf->id : READ_ID(rxBuf->id);
        msgLength = CANBus::DlcToLengthGet(rxBuf->dlc);
        length = msgLength;
        message.append("Message - ID : ");
        etl::to_string(id, message, true);
        message.append(" Length : ");
        etl::to_string(msgLength, message, true);
        message.append(" Message : ");
        while (length) {
            etl::to_string(rxBuf->data[msgLength - length--], message, true);
        }
        LOG_INFO << message.c_str();
    }

}
