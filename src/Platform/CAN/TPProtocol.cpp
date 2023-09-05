#include "CAN/TPProtocol.hpp"
#include "CANGatekeeperTask.hpp"

using namespace CAN;

void TPProtocol::processSingleFrame(const CAN::Frame &message) {
    TPMessage tpMessage;
    tpMessage.decodeId(message.id);

    if (not (tpMessage.idInfo.isMulticast or tpMessage.idInfo.destinationAddress == NodeID)) {
        return;
    }

    size_t messageSize = message.data[0] & 0b111111;
    for (size_t idx = 1; idx <= messageSize; idx++) {
        tpMessage.appendUint8(message.data[idx]);
    }

    parseMessage(tpMessage);
}

void TPProtocol::processMultipleFrames() {
    TPMessage message;
    uint8_t incomingMessagesCount = canGatekeeperTask->getIncomingMessagesCount();
    uint16_t dataLength = 0;
    bool receivedFirstFrame = false;

    for (uint8_t messageCounter = 0; messageCounter < incomingMessagesCount; messageCounter++) {
        CAN::Frame frame = canGatekeeperTask->getFromQueue();
        auto frameType = static_cast<Frame>(frame.data[0] >> 6);

        if (not receivedFirstFrame) {
            if (frameType == First) {
                message.decodeId(frame.id);
                dataLength = ((frame.data[0] & 0b111111) << 8) | frame.data[1];
                receivedFirstFrame = true;
            }
        } else {
            uint8_t consecutiveFrameCount = frame.data[0] & 0b111111;
            if (not ErrorHandler::assertInternal(messageCounter == consecutiveFrameCount,
                                                 ErrorHandler::InternalErrorType::UnacceptablePacket)) { //TODO: Add a more appropriate enum value
                canGatekeeperTask->emptyIncomingQueue();
                return;
            }

            for (size_t idx = 1; idx < CAN::Frame::MaxDataLength; idx++) {
                message.appendUint8(frame.data[idx]);
                if (message.dataSize >= dataLength) {
                    break;
                }
            }
        }
    }

    if (not (message.idInfo.isMulticast or message.idInfo.destinationAddress == NodeID)) {
        return;
    }

    parseMessage(message);
}

void TPProtocol::parseMessage(TPMessage &message) {
    uint8_t messageType = static_cast<Application::MessageIDs>(message.data[0]);
    switch (messageType) {
        case CAN::Application::SendParameters:
            CAN::Application::parseSendParametersMessage(message);
            break;
        case CAN::Application::RequestParameters:
            CAN::Application::parseRequestParametersMessage(message);
            break;
        case CAN::Application::PerformFunction:
            break; //todo: use ST[08] to execute the perform function command
        case CAN::Application::EventReport:
            break; //todo: use the Event Report service
        case CAN::Application::TMPacket:
            CAN::Application::parseTMMessage(message);
            break;
        case CAN::Application::TCPacket:
            CAN::Application::parseTCMessage(message);
            break;
        case CAN::Application::CCSDSPacket:
            break; //todo send this to comms? idk
        case CAN::Application::Ping: {
            auto senderID = static_cast<CAN::NodeIDs>(message.idInfo.sourceAddress);
            auto senderName = CAN::Application::nodeIdToString.at(senderID);
            LOG_DEBUG << "Received ping from " << senderName.c_str();
            CAN::Application::sendPongMessage();
        }
            break;
        case CAN::Application::Pong: {
            auto senderID = static_cast<CAN::NodeIDs>(message.idInfo.sourceAddress);
            auto senderName = CAN::Application::nodeIdToString.at(senderID);
            LOG_DEBUG << "Received pong from " << senderName.c_str();
        }
            break;
        case CAN::Application::LogMessage: {
            auto senderID = static_cast<CAN::NodeIDs>(message.idInfo.sourceAddress);
            auto senderName = CAN::Application::nodeIdToString.at(senderID);
            String<ECSSMaxMessageSize> logSource = "Incoming Log from ";
            logSource.append(senderName);
            logSource.append(": ");
            auto logData = String<ECSSMaxMessageSize>(message.data + 1, message.dataSize - 1);
            LOG_DEBUG << logSource.c_str() << logData.c_str();
        }
            break;
        default:
            ErrorHandler::reportInternalError(ErrorHandler::UnknownMessageType);
            break;
    }
}

void TPProtocol::createCANTPMessage(const TPMessage &message, bool isISR) {
    size_t messageSize = message.dataSize;
    uint32_t id = message.encodeId();
    // Data fits in a Single Frame
    if (messageSize <= UsableDataLength) {
        etl::array<uint8_t, CAN::Frame::MaxDataLength> data = {
                static_cast<uint8_t>(((Single << 6) & 0xFF) | (messageSize & 0b111111))};
        for (size_t idx = 0; idx < messageSize; idx++) {
            data.at(idx + 1) = message.data[idx];
        }
        canGatekeeperTask->send({id, data}, isISR);

        return;
    }

    // First Frame
    {
        // 4 MSB bits is the Frame Type identifier and the 4 LSB are the leftmost 4 bits of the data length.
        uint8_t firstByte = (First << 6) | ((messageSize >> 8) & 0b111111);
        // Rest of the data length.
        uint8_t secondByte = messageSize & 0xFF;

        etl::array<uint8_t, CAN::Frame::MaxDataLength> firstFrame = {firstByte, secondByte};

        canGatekeeperTask->send({id, firstFrame}, isISR);
    }

    // Consecutive Frames
    uint8_t totalConsecutiveFramesNeeded = ceil(static_cast<float>(messageSize) / UsableDataLength);
    for (uint8_t currentConsecutiveFrameCount = 1;
         currentConsecutiveFrameCount <= totalConsecutiveFramesNeeded; currentConsecutiveFrameCount++) {

        uint8_t firstByte = (Consecutive << 6) | (currentConsecutiveFrameCount & 0b111111);
        if (currentConsecutiveFrameCount == totalConsecutiveFramesNeeded) {
            firstByte = ((Final << 6) & 0xFF) | (currentConsecutiveFrameCount & 0b111111);
        }
        etl::array<uint8_t, CAN::Frame::MaxDataLength> consecutiveFrame = {firstByte};

        for (uint8_t idx = 0; idx < UsableDataLength; idx++) {
            consecutiveFrame.at(idx + 1) = message.data[idx + UsableDataLength * (currentConsecutiveFrameCount - 1)];
        }

        canGatekeeperTask->send({id, consecutiveFrame}, isISR);
    }
}
