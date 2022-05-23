#include "CANBus.hpp"

namespace CANBus{
    void InitializeCANBus(){
        MCAN1_MessageRAMConfigSet(MCAN1MessageRAM);
    }
}
