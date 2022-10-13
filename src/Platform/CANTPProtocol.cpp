#include "CANTPProtocol.hpp"
#include "CAN/ApplicationLayer.hpp"
#include "Services/ParameterService.hpp"

namespace CANTPProtocol {
    void createCANTPMessage(uint16_t id, const etl::vector<uint8_t, CAN::TPMessageMaximumSize> &messagePayload, uint16_t messageSize) {
        // 4 MSB bits is the frame type id and the 4 LSB are the 4 out of 12 bits for the data length code.
        uint8_t idDLC = (First << 4) | (messageSize >> 4);
        // Rest 8 bits of data length code.
        uint8_t DLC = messageSize << 4;

        etl::vector<uint8_t, CAN::Packet::MaxDataLength> firstFrame = {idDLC, DLC};

        CANApplicationLayer::outgoingMessages.push({id, firstFrame});

        //Start creating the consecutive frames.
        uint8_t currentConsecutiveFrameCount = 0x01;
        uint8_t consecutiveFrameElements = (Consecutive << 4) | currentConsecutiveFrameCount;
        etl::vector<uint8_t, CAN::Packet::MaxDataLength> consecutiveFrame = {consecutiveFrameElements};
        uint16_t byteCounter = 0;

        for (uint16_t idx = 1; idx < messageSize; idx++) {
            if (byteCounter % CAN::Packet::MaxDataLength == 0) {
                byteCounter = 1;
                CANApplicationLayer::outgoingMessages.push({id, consecutiveFrame});
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

    uint16_t extractDataLengthCode(const CAN::Packet &messageFrame) {
        uint8_t dataLengthCodeLSB = messageFrame.data[0] << 4;
        uint8_t dataLengthCodeMSB = messageFrame.data[1];

        uint16_t DLC = (static_cast<uint16_t>(dataLengthCodeMSB) << 8) | dataLengthCodeLSB;

        return DLC;
    }

    void saveCANTPMessage(const CAN::Packet &messageFrame) {
        uint8_t frame = messageFrame.data[0] >> 4;
        if (frame == First) {
            dataLengthCodes[0] = (extractDataLengthCode(messageFrame));

        } else if (frame == Consecutive) {
            for (uint8_t i = 1; i < BytesPerFrame; i++) {
                canTPMessage.push_back(messageFrame.data[i]);
            }

            if (canTPMessage.size() == dataLengthCodes[0]) {
                parseMessage(canTPMessage);

            }
        }
    }

    //todo: answer with functionality
    void parseMessage(const CANTPMessage &message) {
        switch (message[0]) {
            case CAN::Application::SendParameters:
                break; //todo: use ParameterService to update the values.
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
}