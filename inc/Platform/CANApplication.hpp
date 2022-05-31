#ifndef OBC_SOFTWARE_CANAPPLICATNON_H
#define OBC_SOFTWARE_CANAPPLICATNON_H

#include <cstdint>

class CANApplication {
    enum BusID : uint8_t {
        CAN_MAIN_BUS = 0, CAN_REDUNDANT_BUS = 1
    };
    static inline BusID currentBus = CAN_MAIN_BUS;

public:
    static const uint8_t pingDataPacket = 0x30;

    static const uint8_t pongDataPacket = 0x31;

    static inline uint32_t getHeartbeatID(const uint32_t nodeID) {
        return nodeID + 0x700;
    }

    static inline uint32_t getBusSwitchoverID(const uint32_t nodeID) {
        return nodeID + 0x400;
    }

    static inline uint8_t getBusSwitchoverData() {
        return currentBus ? 1 : 0;
    }

    static inline uint32_t getTimeID(const uint32_t nodeID) {
        return nodeID + 0x200;
    }

    static inline bool isTPMessage(const uint8_t data[8]) {
        return (((data[0] >> 4) == 0b0111));
    }

    static void decodeTPMessage(const uint8_t data[8]);
};


#endif //OBC_SOFTWARE_CANAPPLICATNON_H
