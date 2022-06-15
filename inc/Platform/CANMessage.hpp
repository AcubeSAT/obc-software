#ifndef OBC_SOFTWARE_CANMESSAGE_H
#define OBC_SOFTWARE_CANMESSAGE_H

#include <cstdint>
#include "OBC_Definitions.hpp"

class CANMessage {
private:
    const uint8_t pingDataPacket = 0x30;

    const uint8_t pongDataPacket = 0x31;

    inline uint16_t getHeartbeatID(const uint16_t nodeID) {
        return nodeID + 0x700;
    }

    inline uint16_t getBusSwitchoverID(const uint16_t nodeID) {
        return nodeID + 0x400;
    }

    inline uint8_t getBusToSwitchover() {
        return CAN::currentBus ? 0 : 1;
    }

    inline uint16_t getTimeID(const uint16_t nodeID) {
        return nodeID + 0x200;
    }

    inline bool isTPMessage(const uint16_t id) {
        return (((id >> 7) == 0b0111));
    }

public:
    struct MessageData{
        uint16_t id;
        uint8_t data[8];
    };

    MessageData createPingMessage();

    MessageData createPongMessage();

    MessageData createHeartbeatMessage();

    MessageData createBusSwitchoverMessage();
};


#endif //OBC_SOFTWARE_CANMESSAGE_H
