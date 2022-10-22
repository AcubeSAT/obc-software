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
        uint8_t frameType; //todo Get Frame type
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

    void
    TPProtocol::createCANTPMessage(uint16_t id, const etl::vector<uint8_t, CAN::TPMessageMaximumSize> &messagePayload,
                                   uint16_t messageSize) {
        // 4 MSB bits is the frame type id and the 4 LSB are the 4 out of 12 bits for the data length code.
        uint8_t idDLC = (First << 4) | (messageSize >> 4);
        // Rest 8 bits of data length code.
        uint8_t DLC = messageSize << 4;

        etl::array<uint8_t, CAN::Frame::MaxDataLength> firstFrame = {idDLC, DLC};

        canGatekeeperTask->send({id, firstFrame});

        //Start creating the consecutive frames.
        uint8_t currentConsecutiveFrameCount = 0x01;
        uint8_t consecutiveFrameElements = (Consecutive << 4) | currentConsecutiveFrameCount;
        etl::array<uint8_t, CAN::Frame::MaxDataLength> consecutiveFrame = {consecutiveFrameElements};
        uint16_t byteCounter = 0;

        for (uint16_t idx = 1; idx < messageSize; idx++) {
            if (byteCounter % CAN::Frame::MaxDataLength == 0) {
                byteCounter = 1;

                canGatekeeperTask->send({id, consecutiveFrame});
                currentConsecutiveFrameCount++;

                consecutiveFrameElements = (Consecutive << 4) | currentConsecutiveFrameCount;
                consecutiveFrame = {consecutiveFrameElements};
                if (currentConsecutiveFrameCount == 0x0F) {
                    currentConsecutiveFrameCount = 0x00;
                }
            }
            consecutiveFrame[byteCounter++] = messagePayload[idx];
        }
    }
}