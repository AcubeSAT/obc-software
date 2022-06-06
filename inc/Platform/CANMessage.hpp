#ifndef OBC_SOFTWARE_CANMESSAGE_H
#define OBC_SOFTWARE_CANMESSAGE_H

#include <cstdint>

class CANMessage {
    enum BusID : uint8_t {
        CAN_MAIN_BUS = 0, CAN_REDUNDANT_BUS = 1
    };
    BusID currentBus = CAN_MAIN_BUS;

public:
    const uint8_t pingDataPacket = 0x30;

    const uint8_t pongDataPacket = 0x31;

    inline uint32_t getHeartbeatID(const uint16_t nodeID) {
        return nodeID + 0x700;
    }

    inline uint32_t getBusSwitchoverID(const uint16_t nodeID) {
        return nodeID + 0x400;
    }

    inline uint8_t getBusSwitchoverData() {
        return currentBus ? 0 : 1;
    }

    inline uint32_t getTimeID(const uint16_t nodeID) {
        return nodeID + 0x200;
    }

    inline bool isTPMessage(const uint16_t canID) {
        return (((canID >> 7) == 0b0111));
    }

    static void decodeTPMessage(uint16_t canID);
};


#endif //OBC_SOFTWARE_CANMESSAGE_H