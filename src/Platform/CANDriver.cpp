#include "CANDriver.hpp"
#include "Logger.hpp"

uint8_t CANDriver::convertDlcToLength(uint8_t dlc) {
    static constexpr uint8_t msgLength[] = {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 12U, 16U, 20U, 24U, 32U, 48U, 64U};
    return msgLength[dlc];
}

uint8_t CANDriver::convertLengthToDlc(uint8_t length) {
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

void CANDriver::txFifoCallback(uintptr_t context) {
    uint32_t status = MCAN1_ErrorGet() & MCAN_PSR_LEC_Msk;

    if (static_cast<APPStates>(context) == MCANTransmit &&
        not((status == MCAN_ERROR_NONE) || (status == MCAN_ERROR_LEC_NO_CHANGE))) {
        LOG_ERROR << "Could not transmit CAN message. The status is " << status;
    }
}

void CANDriver::rxFifo0Callback(uint8_t numberOfMessages, uintptr_t context) {
    uint32_t status = MCAN1_ErrorGet() & MCAN_PSR_LEC_Msk;

    if (((status == MCAN_ERROR_NONE) || (status == MCAN_ERROR_LEC_NO_CHANGE)) &&
        static_cast<APPStates>(context) == MCANReceive) {
        memset(&rxFifo0, 0x0, MCAN1_RX_FIFO0_ELEMENT_SIZE);
        if (MCAN1_MessageReceiveFifo(MCAN_RX_FIFO_0, numberOfMessages, &rxFifo0)) {
            logMessage(rxFifo0);
        }
    }
}

void CANDriver::logMessage(MCAN_RX_BUFFER rxBuf) {
    auto message = String<ECSSMaxStringSize>("CAN Message: ");
    uint32_t id = rxBuf.id >> 18;
    uint8_t msgLength = convertDlcToLength(rxBuf.dlc);
    message.append("Message - ID : ");
    etl::to_string(id, message, etl::format_spec().hex(), true);
    message.append(" Length : ");
    etl::to_string(msgLength, message, true);
    message.append(" Message : ");
    for (uint8_t idx = 0; idx < msgLength; idx++) {
        etl::to_string(rxBuf.data[idx], message, true);
    }
    LOG_INFO << message.c_str();
}