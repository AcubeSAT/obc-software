#include "CAN/TPProtocol.hpp"
#include "CANGatekeeperTask.hpp"

namespace CAN {
    void TPProtocol::processSingleFrame(const CAN::Frame &message) {
        TPMessage tpMessage;
        tpMessage.decodeId(message.id);
        size_t messageSize = message.data[0] & 0b1111;

        for (size_t idx = 1; idx <= messageSize; idx++) {
            tpMessage.appendUint8(message.data[idx]);
        }

        parseMessage(tpMessage);
    }

    void TPProtocol::processMultipleFrames() {
        TPMessage tpMessage;
        uint8_t incomingMessagesCount = canGatekeeperTask->getIncomingMessagesCount();
        size_t dataLength = 0;

        for (uint8_t messageCounter = 0; messageCounter < incomingMessagesCount; messageCounter++) {
            CAN::Frame frame = canGatekeeperTask->getFromQueue();
            auto frameType = static_cast<Frame>(frame.data[0] >> 4);

        }
    }

    void TPProtocol::parseMessage(const TPMessage &message) {
        uint8_t messageType = static_cast<Application::MessageIDs>(message.data[0]);
        switch (messageType) {
            case CAN::Application::SendParameters:
                break; //todo: parse parameters
            case CAN::Application::RequestParameters:
                break; //todo: send back the requested parameters.
            case CAN::Application::PerformFunction:
                break; //todo: using ST[08] execute the perform function command
            case CAN::Application::EventReport:
                break; //todo: use the Event Report service to... report the event.... hehe
            case CAN::Application::TMPacket:
                break; //todo: idk
            case CAN::Application::TCPacket:
                break; //todo execute the incoming TC
            case CAN::Application::CCSDSPacket:
                break; //todo send this to comms? idk
            case CAN::Application::Ping:
                CAN::Application::sendPongMessage();
            case CAN::Application::Pong:
                break; //todo Register successful pong
            case CAN::Application::LogMessage:
                break; //todo LOG this message.
            default:
                ErrorHandler::reportInternalError(ErrorHandler::UnknownMessageType);
                break; //todo Error handling
        }
    }

    void TPProtocol::createCANTPMessage(const TPMessage &message) {
        size_t messageSize = message.dataSize;
        uint32_t id = message.encodeId();

        // Data fits in a Single Frame
        if (messageSize <= UsableDataLength) {
            etl::array<uint8_t, CAN::Frame::MaxDataLength> data = {
                    static_cast<uint8_t>((Single << 4) | (messageSize & 0b1111))};
            for (size_t idx = 0; idx < messageSize; idx++) {
                data[idx + 1] = message.data[idx];
            }
            canGatekeeperTask->send({id, data});

            return;
        }

        // First Frame
        {
            // 4 MSB bits is the Frame Type identifier and the 4 LSB are the leftmost 4 bits of the data length.
            uint8_t firstByte = (First << 4) | (messageSize >> 8);
            // Rest of the data length.
            uint8_t secondByte = messageSize & 0xFF;

            etl::array<uint8_t, CAN::Frame::MaxDataLength> firstFrame = {firstByte, secondByte};

            canGatekeeperTask->send({id, firstFrame});
        }

        //Consecutive Frames
        uint8_t totalConsecutiveFramesNeeded = ceil(static_cast<float>(messageSize) / UsableDataLength);
        for (uint8_t currentConsecutiveFrameCount = 1;
             currentConsecutiveFrameCount <= totalConsecutiveFramesNeeded; currentConsecutiveFrameCount++) {

            uint8_t firstByte = (Consecutive << 4) | (currentConsecutiveFrameCount & 0b1111);
            if (currentConsecutiveFrameCount == totalConsecutiveFramesNeeded) {
                firstByte = (Final << 4) | (currentConsecutiveFrameCount & 0b1111);
            }
            etl::array<uint8_t, CAN::Frame::MaxDataLength> consecutiveFrame = {firstByte};

            for (uint8_t idx = 0; idx < UsableDataLength; idx++) {
                consecutiveFrame[idx + 1] = message.data[idx + UsableDataLength * (currentConsecutiveFrameCount - 1)];
            }

            canGatekeeperTask->send({id, consecutiveFrame});
        }
    }
}