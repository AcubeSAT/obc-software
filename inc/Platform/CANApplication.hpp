#ifndef OBC_SOFTWARE_CANAPPLICATNON_H
#define OBC_SOFTWARE_CANAPPLICATNON_H

#include <cstdint>

class CANApplication{
    static inline uint32_t addHeartbeatNodeID(uint32_t nodeID){
        return nodeID + 0x700;
    }

    static inline uint32_t addBusSwitchID(uint32_t nodeID){
        return nodeID + 0x400;
    }

    static inline uint32_t addTimeNodeID(uint32_t nodeID){
        return nodeID + 0x200;
    }


};


#endif //OBC_SOFTWARE_CANAPPLICATNON_H
