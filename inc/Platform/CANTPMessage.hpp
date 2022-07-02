#ifndef OBC_SOFTWARE_CANTPMESSAGE_H
#define OBC_SOFTWARE_CANTPMESSAGE_H

#include <cstdint>
#include "CANMessage.hpp"

class CANTPMessage : CANMessage{
    struct IdInfo{
        uint8_t sourceAddress;
        uint8_t destinationAddress;
        bool isMulticast;
    };
    
    IdInfo decodeId(uint16_t canID);

    uint16_t encodeId(IdInfo idInfo);

}

#endif //OBC_SOFTWARE_CANTPMESSAGE_H
