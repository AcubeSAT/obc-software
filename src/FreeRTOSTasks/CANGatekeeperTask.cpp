#include "CAN/Driver.hpp"
#include "CAN/Frame.hpp"
#include "CANGatekeeperTask.hpp"

CANGatekeeperTask::CANGatekeeperTask() : Task("CANGatekeeperTask") {
    MCAN1_MessageRAMConfigSet(CAN::Driver::mcan1MessageRAM);

    MCAN1_TxFifoCallbackRegister(CAN::Driver::txFifoCallback, CAN::Driver::Transmit);
    MCAN1_RxFifoCallbackRegister(MCAN_RX_FIFO_0, CAN::Driver::rxFifo0Callback, CAN::Driver::Receive);
    MCAN1_RxFifoCallbackRegister(MCAN_RX_FIFO_1, CAN::Driver::rxFifo1Callback, CAN::Driver::Receive);

    static StaticQueue_t outgoingQueueBuffer;
    static StaticQueue_t incomingQueueBuffer;
    uint8_t ucQueueStorageArea[CAN::FrameQueueSize * sizeof(CAN::Frame)];
    outgoingQueue = xQueueCreateStatic(CAN::FrameQueueSize, sizeof(CAN::Frame), ucQueueStorageArea,
                                       &outgoingQueueBuffer);
    incomingQueue = xQueueCreateStatic(CAN::FrameQueueSize, sizeof(CAN::Frame), ucQueueStorageArea,
                                       &incomingQueueBuffer);
}

void CANGatekeeperTask::execute() {
    CAN::Frame message = {};

    while (true) {
        message.empty();
        xQueueReceive(outgoingQueue, &message, portMAX_DELAY);

        CAN::Driver::send(message);
    }
}
