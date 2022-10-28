#include "CAN/Driver.hpp"
#include "CAN/Frame.hpp"
#include "CANGatekeeperTask.hpp"

CANGatekeeperTask::CANGatekeeperTask() : Task("CANGatekeeperTask") {
    MCAN0_MessageRAMConfigSet(CAN::Driver::mcan0MessageRAM);
    MCAN1_MessageRAMConfigSet(CAN::Driver::mcan1MessageRAM);

    MCAN0_TxFifoCallbackRegister(CAN::Driver::mcan0TxFifoCallback, CAN::Driver::Transmit);
    MCAN0_RxFifoCallbackRegister(MCAN_RX_FIFO_0, CAN::Driver::mcan0RxFifo0Callback, CAN::Driver::Receive);
    MCAN0_RxFifoCallbackRegister(MCAN_RX_FIFO_1, CAN::Driver::mcan0RxFifo1Callback, CAN::Driver::Receive);

    MCAN1_TxFifoCallbackRegister(CAN::Driver::mcan1TxFifoCallback, CAN::Driver::Transmit);
    MCAN1_RxFifoCallbackRegister(MCAN_RX_FIFO_0, CAN::Driver::mcan1RxFifo0Callback, CAN::Driver::Receive);
    MCAN1_RxFifoCallbackRegister(MCAN_RX_FIFO_1, CAN::Driver::mcan1RxFifo1Callback, CAN::Driver::Receive);

    static StaticQueue_t outgoingQueueBuffer;
    static StaticQueue_t incomingQueueBuffer;
    uint8_t ucQueueStorageArea[CAN::FrameQueueSize * sizeof(CAN::Frame)];

    outgoingQueue = xQueueCreateStatic(CAN::FrameQueueSize, sizeof(CAN::Frame), ucQueueStorageArea,
                                       &outgoingQueueBuffer);
    vQueueAddToRegistry(outgoingQueue, "CAN Outgoing");

    incomingQueue = xQueueCreateStatic(CAN::FrameQueueSize, sizeof(CAN::Frame), ucQueueStorageArea,
                                       &incomingQueueBuffer);
    vQueueAddToRegistry(incomingQueue, "CAN Incoming");
}

void CANGatekeeperTask::execute() {
    CAN::Frame message = {};

    while (true) {
        message.empty();
        xQueueReceive(outgoingQueue, &message, portMAX_DELAY);

        CAN::Driver::send(message);
    }
}
