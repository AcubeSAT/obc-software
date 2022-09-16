#include "CANTPProtocol.hpp"
#include "CANTPMessage.hpp"
#include "Services/ParameterService.hpp"
#include "Services/FunctionManagementService.hpp"
#include "Services/EventReportService.hpp"

namespace CANTPProtocol {
    static CANMessage newMessage = {};

    void createCANTPMessage(uint16_t id, uint8_t messageMapKey,
                            const etl::vector<uint8_t, CAN::TPMessageMaximumSize> &messagePayload) {

        // 4 MSB bits is the frame type id and the 4 LSB are the 4 out of 12 bits for the data length code
        uint8_t idDLC = (First << 4) | (messagePayload.size() >> 4);
        // Rest 8 bits of data length code
        uint8_t DLC = messagePayload.size() << 4;

        etl::vector<uint8_t, CANMessage::MaxDataLength> firstFrame = {idDLC, DLC, messageMapKey};
        newMessage = {id, firstFrame};
        CANApplicationLayer::outgoingMessages.push(newMessage);
        newMessage.empty();

        uint8_t currentConsecutiveFrameCount = 0x01;
        uint8_t consecutiveFrameElements = (Consecutive << 4) | currentConsecutiveFrameCount;
        etl::vector<uint8_t, CANMessage::MaxDataLength> consecutiveFrame = {consecutiveFrameElements, messageMapKey};

        for (uint8_t i = 0; i < messagePayload.size(); i++) {
            consecutiveFrame[i] = messagePayload[i];

            if ((i + 1) % bytesPerFrame == 0) {
                //Create a can message and insert it to a queue.
                newMessage = {id, consecutiveFrame};
                CANApplicationLayer::outgoingMessages.push(newMessage);
                newMessage.empty();
                currentConsecutiveFrameCount++;

                //Fill the new consecutive frame with the necessary information
                consecutiveFrameElements = (Consecutive << 4) | currentConsecutiveFrameCount;
                consecutiveFrame = {consecutiveFrameElements, messageMapKey};
                //Fill
                if (currentConsecutiveFrameCount == 0x0F) {
                    currentConsecutiveFrameCount = 0x00;
                }
            }
        }
    }

    void saveCANTPMessage(const CANMessage messageFrame) {
        uint8_t frame = messageFrame.data[0] >> 4;
        if (frame == First) {
            uint8_t messageMapKey = messageFrame.data[2];
            uint8_t dataLengthCodeLSB = messageFrame.data[0] << 4;
            uint8_t dataLengthCodeMSB = messageFrame.data[1];
            uint16_t dataLengthCode = (static_cast<uint16_t>(dataLengthCodeMSB) << 8) | dataLengthCodeLSB;
            incomingMessages.insert(etl::pair{messageMapKey, CANTPMessage{}});
            dataLengthCodes[messageMapKey] = dataLengthCode;
        } else if (frame == Consecutive) {
            //todo: clean up the starting payload bytes
            uint8_t messageMapKey = messageFrame.data[1];
            etl::vector<uint8_t, messageFrame.MaxDataLength> data;
            for (uint8_t i = 0; i < bytesPerFrame; i++) {
                data.push_back(messageFrame.data[bytesStartingPoint + i]);
            }
            incomingMessages[messageMapKey].insert(incomingMessages[messageMapKey].end(),
                                                   data.begin(), data.end());
            if (incomingMessages[messageMapKey].size() == dataLengthCodes[messageMapKey]) {
                parseMessage(incomingMessages[messageMapKey]);
            }
        }
    }

    //todo: answer with functionality
    void parseMessage(CANTPMessage message) {
        switch (message[0]) {
            case SendParameters:
                break;
            case RequestParameters:
                break;
            case PerformFunction:
                break;
            case EventReport:
                break;
            case TMPacket:
                break;
            case TCPacket:
                break;
            case CCSDSPacket:
                break;
            case Ping:
                CANApplicationLayer::sendPongMessage();
            case Pong:
                break;
            case LogMessage:
                break;
        }
    }
}