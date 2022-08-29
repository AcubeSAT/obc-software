//
// Created by sourland on 28/8/2022.
//

#include "CANTPProtocol.hpp"

using namespace CANTPMessage;
namespace CANTPProtocol {

    void encodeCANTPMessage(uint8_t messageID, const etl::vector<uint8_t, CAN::TPMessageMaximumSize> &messagePayload) {
        uint16_t firstFrameElements = (FirstFrame << 12) | messagePayload.size();
        uint8_t idDLC = firstFrameElements & 0xFF;
        uint8_t DLC = firstFrameElements >> 8;
        etl::vector<uint8_t, CANMessage::MaxDataLength> firstFrame = {idDLC, DLC};

        for (uint8_t i = 0; i < FirstFramePayloadLength; i++) {
            firstFrame.push_back(messagePayload[i]);
        }

        etl::vector<uint8_t, 256> totalFrame;

        uint8_t currentConsecutiveFrameNumber = 0x01;
        uint8_t consecutiveFrameElements = (ConsecutiveFrame << 4) | currentConsecutiveFrameNumber;
        etl::vector<uint8_t, CANMessage::MaxDataLength> consecutiveFrame = {consecutiveFrameElements};

        for (uint8_t i = 0; i < messagePayload.size(); i++) {
            uint8_t messagePosition = FirstFramePayloadLength + i;
            consecutiveFrame.push_back(messagePayload[messagePosition]);
            if ((i + 1) % 7 == 0){
                totalFrame.push_back(consecutiveFrame);
                consecutiveFrame.clear();

                currentConsecutiveFrameNumber++;

                consecutiveFrameElements = (ConsecutiveFrame << 4) | currentConsecutiveFrameNumber;
                consecutiveFrame.push_back(consecutiveFrameElements);

                if(currentConsecutiveFrameNumber == 15) currentConsecutiveFrameNumber = 0;
            }
        }

        outgoingMessages.insert(std::make_pair(messageID, totalFrame));
    }
}