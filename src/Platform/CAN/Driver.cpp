#include "CAN/Driver.hpp"
#include "CAN/TPProtocol.hpp"
#include "CANGatekeeperTask.hpp"
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

void CAN::Driver::mcan0TxFifoCallback(uintptr_t context) {
    uint32_t status = MCAN0_ErrorGet() & MCAN_PSR_LEC_Msk;
    bool isStatusOk = (status == MCAN_ERROR_NONE) || (status == MCAN_ERROR_LEC_NO_CHANGE);
    auto appState = static_cast<AppStates>(context);

    if (appState == Transmit && not isStatusOk) {
        LOG_ERROR << "Could not transmit CAN message. The status is " << status;
    }
}

void CAN::Driver::mcan0RxFifo0Callback(uint8_t numberOfMessages, uintptr_t context) {
    uint32_t status = MCAN0_ErrorGet() & MCAN_PSR_LEC_Msk;
    bool isStatusOk = (status == MCAN_ERROR_NONE) || (status == MCAN_ERROR_LEC_NO_CHANGE);
    auto appState = static_cast<AppStates>(context);

    if (not(isStatusOk && appState == Receive)) {
        return;
    }

    for (size_t messageNumber = 0; messageNumber < numberOfMessages; messageNumber++) {
        memset(&rxFifo0, 0x0, (numberOfMessages * MCAN0_RX_FIFO0_ELEMENT_SIZE));
        if (MCAN0_MessageReceiveFifo(MCAN_RX_FIFO_0, 1, &rxFifo0)) {
            if (rxFifo0.data[0] >> 6 == CAN::TPProtocol::Frame::Single) {
                logMessage(rxFifo0, Redundant);
                TPProtocol::processSingleFrame(getFrame(rxFifo0));
                continue;
            }

            canGatekeeperTask->addToIncoming(getFrame(rxFifo0));

            if (rxFifo0.data[0] >> 6 == CAN::TPProtocol::Frame::Final) {
                CAN::TPProtocol::processMultipleFrames();
            }
        }
    }
}

void CAN::Driver::mcan0RxFifo1Callback(uint8_t numberOfMessages, uintptr_t context) {
    uint32_t status = MCAN0_ErrorGet() & MCAN_PSR_LEC_Msk;
    bool isStatusOk = (status == MCAN_ERROR_NONE) || (status == MCAN_ERROR_LEC_NO_CHANGE);
    auto appState = static_cast<AppStates>(context);

    if (not(isStatusOk && appState == Receive)) {
        return;
    }

    for (size_t messageNumber = 0; messageNumber < numberOfMessages; messageNumber++) {
        memset(&rxFifo1, 0x0, MCAN0_RX_FIFO0_ELEMENT_SIZE);
        if (MCAN0_MessageReceiveFifo(MCAN_RX_FIFO_1, 1, &rxFifo1)) {
            logMessage(rxFifo1, Main);
            CAN::Application::parseMessage(getFrame(rxFifo1));
        }
    }
}

void CAN::Driver::mcan1TxFifoCallback(uintptr_t context) {
    uint32_t status = MCAN1_ErrorGet() & MCAN_PSR_LEC_Msk;
    bool isStatusOk = (status == MCAN_ERROR_NONE) || (status == MCAN_ERROR_LEC_NO_CHANGE);
    auto appState = static_cast<AppStates>(context);

    if (appState == Transmit && not isStatusOk) {
        LOG_ERROR << "Could not transmit CAN message. The status is " << status;
    }
}

void CAN::Driver::mcan1RxFifo0Callback(uint8_t numberOfMessages, uintptr_t context) {
    uint32_t status = MCAN1_ErrorGet() & MCAN_PSR_LEC_Msk;
    bool isStatusOk = (status == MCAN_ERROR_NONE) || (status == MCAN_ERROR_LEC_NO_CHANGE);
    auto appState = static_cast<AppStates>(context);

    if (not(isStatusOk && appState == Receive)) {
        return;
    }

    for (size_t messageNumber = 0; messageNumber < numberOfMessages; messageNumber++) {
        memset(&rxFifo0, 0x0, (numberOfMessages * MCAN1_RX_FIFO0_ELEMENT_SIZE));
        if (MCAN1_MessageReceiveFifo(MCAN_RX_FIFO_0, 1, &rxFifo0)) {
            if (rxFifo0.data[0] >> 6 == CAN::TPProtocol::Frame::Single) {
                TPProtocol::processSingleFrame(getFrame(rxFifo0));
                continue;
            }

            canGatekeeperTask->addToIncoming(getFrame(rxFifo0));

            if (rxFifo0.data[0] >> 6 == CAN::TPProtocol::Frame::Final) {
                CAN::TPProtocol::processMultipleFrames();
            }
        }
    }
}

void CAN::Driver::mcan1RxFifo1Callback(uint8_t numberOfMessages, uintptr_t context) {
    uint32_t status = MCAN1_ErrorGet() & MCAN_PSR_LEC_Msk;
    bool isStatusOk = (status == MCAN_ERROR_NONE) || (status == MCAN_ERROR_LEC_NO_CHANGE);
    auto appState = static_cast<AppStates>(context);

    if (not(isStatusOk && appState == Receive)) {
        return;
    }

    for (size_t messageNumber = 0; messageNumber < numberOfMessages; messageNumber++) {
        memset(&rxFifo1, 0x0, MCAN1_RX_FIFO0_ELEMENT_SIZE);
        if (MCAN1_MessageReceiveFifo(MCAN_RX_FIFO_1, 1, &rxFifo1)) {
            logMessage(rxFifo1, Redundant);
            CAN::Application::parseMessage(getFrame(rxFifo1));
        }
    }
}

void CAN::Driver::send(const CAN::Frame &message) {
    using namespace CAN;

    memset(&Driver::txFifo, 0, MCAN1_TX_FIFO_BUFFER_ELEMENT_SIZE);

    Driver::txFifo.brs = 1;
    Driver::txFifo.fdf = 1;
    Driver::txFifo.xtd = 0;
    Driver::txFifo.id = Driver::writeId(message.id);
    Driver::txFifo.dlc = Driver::convertLengthToDLC(message.data.size());

    std::copy(message.data.begin(), message.data.end(), Driver::txFifo.data);

    if (AcubeSATParameters::obcCANBUSActive.getValue() == Main) {
        MCAN1_MessageTransmitFifo(1, &Driver::txFifo);
    } else {
        MCAN0_MessageTransmitFifo(1, &Driver::txFifo);
    }
}

void CAN::Driver::logMessage(const MCAN_RX_BUFFER &rxBuf, ActiveBus incomingBus) {
    auto message = String<ECSSMaxStringSize>("CAN Message: ");
    if (incomingBus == Main) {
        message.append("MCAN0 ");
    } else {
        message.append("MCAN1 ");
    }
    uint32_t id = readId(rxBuf.id);
    const uint8_t msgLength = convertDlcToLength(rxBuf.dlc);
    message.append("ID : ");
    etl::to_string(id, message, etl::format_spec().hex(), true);
    message.append(" Length : ");
    etl::to_string(msgLength, message, true);
    message.append(" Data : ");
    for (uint8_t idx = 0; idx < msgLength; idx++) {
        etl::to_string(rxBuf.data[idx], message, true);
        message.append(" ");
    }
    LOG_INFO << message.c_str();
}

CAN::Frame CAN::Driver::getFrame(const MCAN_RX_BUFFER &rxBuffer) {
    CAN::Frame frame;
    const uint8_t messageLength = convertDlcToLength(rxBuffer.dlc);

    frame.id = readId(rxBuffer.id);
    for (uint8_t idx = 0; idx < messageLength; idx++) {
        frame.data.at(idx) = rxBuffer.data[idx];
    }

    return frame;
}

void CAN::Driver::initialize() {
    MCAN0_MessageRAMConfigSet(CAN::Driver::mcan0MessageRAM);
    MCAN1_MessageRAMConfigSet(CAN::Driver::mcan1MessageRAM);

    MCAN0_TxFifoCallbackRegister(CAN::Driver::mcan0TxFifoCallback, CAN::Driver::Transmit);
    MCAN0_RxFifoCallbackRegister(MCAN_RX_FIFO_0, CAN::Driver::mcan0RxFifo0Callback, CAN::Driver::Receive);
    MCAN0_RxFifoCallbackRegister(MCAN_RX_FIFO_1, CAN::Driver::mcan0RxFifo1Callback, CAN::Driver::Receive);

    MCAN1_TxFifoCallbackRegister(CAN::Driver::mcan1TxFifoCallback, CAN::Driver::Transmit);
    MCAN1_RxFifoCallbackRegister(MCAN_RX_FIFO_0, CAN::Driver::mcan1RxFifo0Callback, CAN::Driver::Receive);
    MCAN1_RxFifoCallbackRegister(MCAN_RX_FIFO_1, CAN::Driver::mcan1RxFifo1Callback, CAN::Driver::Receive);
}
