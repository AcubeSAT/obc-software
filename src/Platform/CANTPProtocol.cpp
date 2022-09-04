//
// Created by sourland on 28/8/2022.
//

#include "CANTPProtocol.hpp"


namespace CANTPProtocol {
    static CANMessage newMessage = {};

    void createCANTPMessage(uint16_t id, uint8_t messageKeyID,
                            const etl::vector<uint8_t, CAN::TPMessageMaximumSize> &messagePayload) {

        // 4 MSB bits is the frame type id and the 4 LSB are the 4 out of 12 bits for the data length code
        uint8_t idDLC = ((FirstFrame << 12) | messagePayload.size()) & 0xFF;
        // Rest 8 bits of data length code
        uint8_t DLC = ((FirstFrame << 12) | messagePayload.size()) >> 8;

        etl::array<uint8_t, CANMessage::MaxDataLength> firstFrame = {idDLC, DLC, messageKeyID};
        newMessage = {id, firstFrame};
        CANTPMessages.push(newMessage);
        newMessage.empty();

        uint8_t currentConsecutiveFrameCount = 0x01;
        uint8_t consecutiveFrameElements = (ConsecutiveFrame << 4) | currentConsecutiveFrameCount;
        etl::array<uint8_t, CANMessage::MaxDataLength> consecutiveFrame = {consecutiveFrameElements, messageKeyID};

        for (uint8_t i = 0; i < messagePayload.size(); i++) {
            consecutiveFrame[i] = messagePayload[i];

            if ((i + 1) % 4 == 0) {
                //Create a can message and insert it to a queue.
                newMessage = {id, consecutiveFrame};
                CANTPMessages.push(newMessage);
                newMessage.empty();
                currentConsecutiveFrameCount++;

                //Fill the new consecutive frame with the necessary information
                consecutiveFrameElements = (ConsecutiveFrame << 4) | currentConsecutiveFrameCount;
                consecutiveFrame = {consecutiveFrameElements, messageKeyID};

                //Fill
                if (currentConsecutiveFrameCount == 0xF) currentConsecutiveFrameCount = 0x00;
            }
        }
    }
}