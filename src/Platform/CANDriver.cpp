#include "CANDriver.hpp"
#include "Logger.hpp"

uint8_t CANDriver::convertDlcToLength(const uint8_t DLC) {
    static constexpr uint8_t msgLength[] = {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 12U, 16U, 20U, 24U, 32U, 48U, 64U};
    return msgLength[DLC];
}

uint8_t CANDriver::convertLengthToDlc(const uint8_t Length) {
    uint8_t dlc;

    if (Length <= 8U) {
        dlc = Length;
    } else if (Length <= 12U) {
        dlc = 0x9U;
    } else if (Length <= 16U) {
        dlc = 0xAU;
    } else if (Length <= 20U) {
        dlc = 0xBU;
    } else if (Length <= 24U) {
        dlc = 0xCU;
    } else if (Length <= 32U) {
        dlc = 0xDU;
    } else if (Length <= 48U) {
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

void CANDriver::rxFifo0Callback(const uint8_t NumberOfMessages, uintptr_t context) {
    uint32_t status = MCAN1_ErrorGet() & MCAN_PSR_LEC_Msk;

    if (((status == MCAN_ERROR_NONE) || (status == MCAN_ERROR_LEC_NO_CHANGE)) &&
        static_cast<APPStates>(context) == MCANReceive) {
        //TODO: Is it necessary to set all the elements to 0?
        memset(&rxFifo0, 0x0, MCAN1_RX_FIFO0_ELEMENT_SIZE);
        if (MCAN1_MessageReceiveFifo(MCAN_RX_FIFO_0, NumberOfMessages, &rxFifo0)) {
            logMessage(rxFifo0);
        }
    }
}

void CANDriver::logMessage(const MCAN_RX_BUFFER &RXBuf) {
    auto message = String<ECSSMaxStringSize>("CAN Message: ");
    uint32_t id = RXBuf.id >> 18;
    const uint8_t MsgLength = convertDlcToLength(RXBuf.dlc);
    message.append("Message - ID : ");
    etl::to_string(id, message, etl::format_spec().hex(), true);
    message.append(" Length : ");
    etl::to_string(MsgLength, message, true);
    message.append(" Message : ");
    for (uint8_t idx = 0; idx < MsgLength; idx++) {
        etl::to_string(RXBuf.data[idx], message, true);
    }
    LOG_INFO << message.c_str();
}