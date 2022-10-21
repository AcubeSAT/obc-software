#include "CAN/Driver.hpp"
#include "CAN/Frame.hpp"
#include "CANGatekeeperTask.hpp"

CANGatekeeperTask::CANGatekeeperTask() : Task("CANGatekeeperTask") {
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
        xQueueReceive(outgoingQueue, &message, portMAX_DELAY);
        CAN::Driver::txFifo.brs = 1;
        CAN::Driver::txFifo.fdf = 1;
        CAN::Driver::txFifo.xtd = 0;
        CAN::Driver::txFifo.id = message.id << 18;
        CAN::Driver::txFifo.dlc = CAN::Driver::convertLengthToDLC(message.data.size());

        for (uint8_t idx = 0; idx < message.data.size(); idx++) {
            CAN::Driver::txFifo.data[idx] = message.data[idx];
        }

        MCAN1_MessageTransmitFifo(1, &CAN::Driver::txFifo);
    }
}
