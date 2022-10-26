#include "CAN/Driver.hpp"
#include "Logger.hpp"

uint8_t CAN::Driver::convertDlcToLength(uint8_t dlc) {
    static constexpr uint8_t msgLength[] = {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 12U, 16U, 20U, 24U, 32U, 48U, 64U};
    return msgLength[dlc];
}

uint8_t CAN::Driver::convertLengthToDLC(uint8_t length) {
    uint8_t dlc;

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

void CAN::Driver::txFifoCallback(uintptr_t context) {
    uint32_t status = MCAN1_ErrorGet() & MCAN_PSR_LEC_Msk;

    if (static_cast<AppStates>(context) == Transmit &&
        not((status == MCAN_ERROR_NONE) || (status == MCAN_ERROR_LEC_NO_CHANGE))) {
        LOG_ERROR << "Could not transmit CAN message. The status is " << status;
    }
}

void CAN::Driver::rxFifo0Callback(uint8_t numberOfMessages, uintptr_t context) {
    uint32_t status = MCAN1_ErrorGet() & MCAN_PSR_LEC_Msk;

    if (((status == MCAN_ERROR_NONE) || (status == MCAN_ERROR_LEC_NO_CHANGE)) &&
        static_cast<AppStates>(context) == Receive) {
        //TODO: Is it necessary to set all the elements to 0?
        memset(&rxFifo0, 0x0, MCAN1_RX_FIFO0_ELEMENT_SIZE);
        if (MCAN1_MessageReceiveFifo(MCAN_RX_FIFO_0, numberOfMessages, &rxFifo0)) {
            logMessage(rxFifo0);
        }
    }
}

void CAN::Driver::send(const CAN::Frame &message) {
    memset(&CAN::Driver::txFifo, 0, MCAN1_TX_FIFO_BUFFER_ELEMENT_SIZE);

    CAN::Driver::txFifo.brs = 1;
    CAN::Driver::txFifo.fdf = 1;
    CAN::Driver::txFifo.xtd = 0;
    CAN::Driver::txFifo.id = CAN::Driver::writeId(message.id);
    CAN::Driver::txFifo.dlc = CAN::Driver::convertLengthToDLC(message.data.size());

    for (uint8_t idx = 0; idx < message.data.size(); idx++) {
        CAN::Driver::txFifo.data[idx] = message.data[idx];
    }

    MCAN1_MessageTransmitFifo(1, &CAN::Driver::txFifo);
}

void CAN::Driver::logMessage(const MCAN_RX_BUFFER &rxBuf) {
    auto message = String<ECSSMaxStringSize>("CAN Message: ");
    uint32_t id = readId(rxBuf.id);
    const uint8_t msgLength = convertDlcToLength(rxBuf.dlc);
    message.append("ID : ");
    etl::to_string(id, message, etl::format_spec().hex(), true);
    message.append(" Length : ");
    etl::to_string(msgLength, message, true);
    message.append(" Data : ");
    for (uint8_t idx = 0; idx < msgLength; idx++) {
        etl::to_string(rxBuf.data[idx], message, true);
    }
    LOG_INFO << message.c_str();
}
