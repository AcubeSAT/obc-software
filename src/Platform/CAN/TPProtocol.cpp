#include "CAN/TPProtocol.hpp"
#include "CANGatekeeperTask.hpp"

namespace CAN {
    void TPProtocol::saveCANTPMessage(const CAN::Frame &messageFrame) {
        uint8_t frameType = messageFrame.data[0] >> 4;
        if (frameType == First) {
            dataLengthCodes[0] = extractDataLengthCode(messageFrame);
        } else if (frameType == Consecutive) {
            for (uint8_t i = 1; i < BytesInConsecutiveFrame; i++) {
                tpMessage.appendUint8(messageFrame.data[i]);
            }

            if (tpMessage.dataSize == dataLengthCodes[0]) {
                parseMessage(tpMessage);
            }
        }
    }

    void TPProtocol::parseMessage(const TPMessage &message) {
        uint8_t frameType = static_cast<Frame>(message.data[0]);
        switch (frameType) {
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
                break; //todo Saul goodman
            case CAN::Application::LogMessage:
                break; //todo LOG this message.
            default:
                break; //todo Error handling
        }
    }

    void TPProtocol::createCANTPMessage(const TPMessage &message) {
        size_t messageSize = message.dataSize;
        uint32_t id = message.encodeId();
        static constexpr uint8_t usableDataLength = CAN::Frame::MaxDataLength - 1;

        // Data fits in a Single Frame
        if (messageSize < usableDataLength) {
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
        uint8_t totalConsecutiveFramesNeeded = ceil(messageSize / usableDataLength);
        for (uint8_t currentConsecutiveFrameCount = 1;
             currentConsecutiveFrameCount < totalConsecutiveFramesNeeded; currentConsecutiveFrameCount++) {

            uint8_t firstByte = (Consecutive << 4) | (currentConsecutiveFrameCount & 0b1111);
            etl::array<uint8_t, CAN::Frame::MaxDataLength> consecutiveFrame = {firstByte};

            for (uint8_t idx = 0; idx < usableDataLength; idx++) {
                consecutiveFrame[idx + 1] = message.data[idx + usableDataLength * (currentConsecutiveFrameCount - 1)];
            }

            canGatekeeperTask->send({id, consecutiveFrame});
        }
    }
}