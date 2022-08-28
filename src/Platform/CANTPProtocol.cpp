//
// Created by sourland on 28/8/2022.
//

#include "CANTPProtocol.hpp"

using namespace CANTPMessage;
namespace CANTPProtocol {

    void encodeCANTPMessage(const etl::vector<uint8_t, CAN::TPMessageMaximumSize> &messagePayload){
        uint16_t firstFrameElements = (FirstFrame << 12) | messagePayload.size();
        uint8_t idDLC = firstFrameElements & 0xFF;
        uint8_t DLC = firstFrameElements >> 8;
        etl::vector<uint8_t, CANMessage::MaxDataLength> firstFrame = {idDLC, DLC};
        uint8_t counter = 0;
        for (uint8_t byte:messagePayload){
            firstFrame.push_back(byte);
            counter++;
            if (counter == 6) break;
        }

        etl::queue<etl::vector<uint8_t, CANMessage::MaxDataLength>, 256> hmm;

        uint8_t currentConsecutiveFrameNumber = 0x01;
        uint8_t consecutiveFrameElements = (ConsecutiveFrame << 4) | currentConsecutiveFrameNumber;
        etl::vector<uint8_t, CANMessage::MaxDataLength> consecutiveFrame = {consecutiveFrameElements};



    }
}