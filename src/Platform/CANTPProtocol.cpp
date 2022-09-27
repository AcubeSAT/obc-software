#include "CANTPProtocol.hpp"
#include "CANTPMessage.hpp"
#include "Services/ParameterService.hpp"
#include "Services/FunctionManagementService.hpp"
#include "Services/EventReportService.hpp"

namespace CANTPProtocol {
    void createCANTPMessage(uint16_t id, uint8_t messageMapKey,
                            const etl::vector<uint8_t, CAN::TPMessageMaximumSize> &messagePayload) {

        CANMessage message = {};

        // 4 MSB bits is the frame type id and the 4 LSB are the 4 out of 12 bits for the data length code.
        uint8_t idDLC = (First << 4) | (messagePayload.size() >> 4);
        // Rest 8 bits of data length code.
        uint8_t DLC = messagePayload.size() << 4;

        etl::vector<uint8_t, CANMessage::MaxDataLength> firstFrame = {idDLC, DLC, messageMapKey};
        message = {id, firstFrame};
        CANApplicationLayer::outgoingMessages.push(message);
        message.empty();

        //Start creating the consecutive frames.
        uint8_t currentConsecutiveFrameCount = 0x01;
        uint8_t consecutiveFrameElements = (Consecutive << 4) | currentConsecutiveFrameCount;
        etl::vector<uint8_t, CANMessage::MaxDataLength> consecutiveFrame = {consecutiveFrameElements, messageMapKey};
        uint16_t byteCounter = 0;

        for (uint8_t byte: messagePayload) {
            if ((byteCounter & 0x03) == 0) {
                byteCounter = 0;
                //Create a CAN message and insert it to a queue.
                message = {id, consecutiveFrame};
                CANApplicationLayer::outgoingMessages.push(message);
                message.empty();
                currentConsecutiveFrameCount++;

                //Fill the new consecutive frame with the necessary information
                consecutiveFrameElements = (Consecutive << 4) | currentConsecutiveFrameCount;
                consecutiveFrame = {consecutiveFrameElements, messageMapKey};
                //Reset the CF counter
                if (currentConsecutiveFrameCount == 0x0F) {
                    currentConsecutiveFrameCount = 0x00;
                }
            }
            consecutiveFrame[byteCounter++] = byte;
        }
    }

    MessageInformation extractMessageInformation(const CANMessage &messageFrame) {
        uint8_t dataLengthCodeLSB = messageFrame.data[0] << 4;
        uint8_t dataLengthCodeMSB = messageFrame.data[1];
        uint8_t messageMapKey = messageFrame.data[2];

        uint16_t dataLengthCode = (static_cast<uint16_t>(dataLengthCodeMSB) << 8) | dataLengthCodeLSB;

        return {dataLengthCode, messageMapKey};
    }

    void saveCANTPMessage(const CANMessage &messageFrame) {
        uint8_t frame = messageFrame.data[0] >> 4;
        if (frame == First) {
            auto information = extractMessageInformation(messageFrame);

            auto dataLengthCode = information.dataLengthCode;
            auto messageMapKey = information.messageMapKey;

            incomingMessages.insert(etl::pair{messageMapKey, CANTPMessage{}});
            dataLengthCodes[messageMapKey] = dataLengthCode;
        } else if (frame == Consecutive) {
            uint8_t messageMapKey = messageFrame.data[1];
            etl::vector<uint8_t, CANMessage::MaxDataLength> data;
            for (uint8_t i = 0; i < BytesPerFrame; i++) {
                data.push_back(messageFrame.data[BytesStartingPoint + i]);
            }
            incomingMessages[messageMapKey].insert(incomingMessages[messageMapKey].end(),
                                                   data.begin(), data.end());
            if (incomingMessages[messageMapKey].size() == dataLengthCodes[messageMapKey]) {
                parseMessage(incomingMessages[messageMapKey]);
            }
        }
    }

    //todo: answer with functionality
    void parseMessage(const CANTPMessage &message) {
        switch (message[0]) {
            case SendParameters:
                break; //todo: use ParameterService to update the values.
            case RequestParameters:
                break; //todo: send back the requested parameters.
            case PerformFunction:
                break; //todo: using ST[08] execute the perform function command
            case EventReport:
                break; //todo: use the Event Report service to... report the event.... hehe
            case TMPacket:
                break; //todo: idk
            case TCPacket:
                break; //execute the incoming TC
            case CCSDSPacket:
                break; //send this to comms? idk
            case Ping:
                CANApplicationLayer::sendPongMessage();
            case Pong:
                break; //Saul goodman
            case LogMessage:
                break; //LOG this message.
            default:
                break; //Error handling
        }
    }
}