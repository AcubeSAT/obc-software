#ifndef OBC_SOFTWARE_CANTRANSMITTASK_HPP
#define OBC_SOFTWARE_CANTRANSMITTASK_HPP

#include "CANDriver.hpp"
#include "Task.hpp"

class CANTransmitTask : public Task{
private:

public:
    const static inline uint16_t taskStackDepth = 1500;

    StackType_t taskStack[taskStackDepth];

    void execute();

    CANTransmitTask() : Task("CAN Transmit") {
        MCAN1_MessageRAMConfigSet(CANDriver::mcan1MessageRAM);

        MCAN1_TxFifoCallbackRegister(CANDriver::txFifoCallback, CANDriver::MCANTransmit);
        MCAN1_RxFifoCallbackRegister(MCAN_RX_FIFO_0, CANDriver::rxFifo0Callback, CANDriver::MCANReceive);
    }
};

#endif //OBC_SOFTWARE_CANTRANSMITTASK_HPP