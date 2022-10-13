#include "CAN/Driver.hpp"
#include "CAN/Packet.hpp"
#include "CANGatekeeperTask.hpp"

CANGatekeeperTask::CANGatekeeperTask() : Task("CANGatekeeperTask") {
    static StaticQueue_t xStaticQueue;
    uint8_t ucQueueStorageArea[CAN::MessageQueueSize * sizeof(CAN::Message)];
    xCanQueue = xQueueCreateStatic(CAN::MessageQueueSize, sizeof(CAN::Message), ucQueueStorageArea, &xStaticQueue);
}

void CANGatekeeperTask::execute() {
    CAN::Message message = {};

    while (true) {
        xQueueReceive(xCanQueue, &message, portMAX_DELAY);
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
