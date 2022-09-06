//
// Created by sourland on 28/8/2022.
//

#include "CANTPProtocol.hpp"


namespace CANTPProtocol {
    static CANMessage newMessage = {};

    void createCANTPMessage(uint16_t id, uint8_t messageMapKey,
                            const etl::vector<uint8_t, CAN::TPMessageMaximumSize> &messagePayload) {

        // 4 MSB bits is the frame type id and the 4 LSB are the 4 out of 12 bits for the data length code
        uint8_t idDLC = ((First << 12) | messagePayload.size()) & 0xFF;
        // Rest 8 bits of data length code
        uint8_t DLC = ((First << 12) | messagePayload.size()) >> 8;

        etl::array<uint8_t, CANMessage::MaxDataLength> firstFrame = {idDLC, DLC, messageMapKey};
        newMessage = {id, firstFrame};
        CANApplicationLayer::outgoingMessages.push(newMessage);
        newMessage.empty();

        uint8_t currentConsecutiveFrameCount = 0x01;
        uint8_t consecutiveFrameElements = (Consecutive << 4) | currentConsecutiveFrameCount;
        etl::array<uint8_t, CANMessage::MaxDataLength> consecutiveFrame = {consecutiveFrameElements, messageMapKey};

        for (uint8_t i = 0; i < messagePayload.size(); i++) {
            consecutiveFrame[i] = messagePayload[i];

            if ((i + 1) % 4 == 0) {
                //Create a can message and insert it to a queue.
                newMessage = {id, consecutiveFrame};
                CANApplicationLayer::outgoingMessages.push(newMessage);
                newMessage.empty();
                currentConsecutiveFrameCount++;

                //Fill the new consecutive frame with the necessary information
                consecutiveFrameElements = (Consecutive << 4) | currentConsecutiveFrameCount;
                consecutiveFrame = {consecutiveFrameElements, messageMapKey};

                //Fill
                if (currentConsecutiveFrameCount == 0x0F) currentConsecutiveFrameCount = 0x00;
            }
        }
    }
}