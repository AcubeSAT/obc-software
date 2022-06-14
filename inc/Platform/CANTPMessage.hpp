#ifndef OBC_SOFTWARE_CANTPMESSAGE_H
#define OBC_SOFTWARE_CANTPMESSAGE_H

#include <cstdint>

namespace CANTPMessage{
    struct idInfo{
        uint8_t sourceAddress;
        uint8_t destinationAddress;
        bool isMulticast;
    };
    
    static idInfo decodeId(uint16_t canID);
    static uint16_t encodeId(idInfo idInfo);

}

#endif //OBC_SOFTWARE_CANTPMESSAGE_H
