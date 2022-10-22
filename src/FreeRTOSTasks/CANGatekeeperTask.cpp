#include "CAN/Driver.hpp"
#include "CAN/Frame.hpp"
#include "CANGatekeeperTask.hpp"

CANGatekeeperTask::CANGatekeeperTask() : Task("CANGatekeeperTask") {
    MCAN1_MessageRAMConfigSet(CAN::Driver::mcan1MessageRAM);

    MCAN1_TxFifoCallbackRegister(CAN::Driver::txFifoCallback, CAN::Driver::Transmit);
    MCAN1_RxFifoCallbackRegister(MCAN_RX_FIFO_0, CAN::Driver::rxFifo0Callback, CAN::Driver::Receive);

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
        memset(&CAN::Driver::txFifo, 0, MCAN1_TX_FIFO_BUFFER_ELEMENT_SIZE);

        xQueueReceive(outgoingQueue, &message, portMAX_DELAY);
        CAN::Driver::txFifo.brs = 1;
        CAN::Driver::txFifo.fdf = 1;
        CAN::Driver::txFifo.xtd = 0;
        CAN::Driver::txFifo.id = CAN::Driver::writeId(message.id);
        CAN::Driver::txFifo.dlc = CAN::Driver::convertLengthToDLC(message.data.size());

        for (uint8_t idx = 0; idx < message.data.size(); idx++) {
            CAN::Driver::txFifo.data[idx] = message.data[idx];
        }

        MCAN1_MessageTransmitFifo(1, &CAN::Driver::txFifo);
    }
}
