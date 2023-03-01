#include "CAN/Driver.hpp"
#include "CAN/Frame.hpp"
#include "CANGatekeeperTask.hpp"

CANGatekeeperTask::CANGatekeeperTask() : Task("CANGatekeeperTask") {
    CAN::Driver::initialize();
    CAN::Driver::toggleActiveBus(CAN::Driver::Redundant);
    outgoingQueue = xQueueCreateStatic(CAN::FrameQueueSize, sizeof(CAN::Frame), outgoingQueueStorageArea,
                                       &outgoingQueueBuffer);
    vQueueAddToRegistry(outgoingQueue, "CAN Outgoing");

    incomingQueue = xQueueCreateStatic(CAN::FrameQueueSize, sizeof(CAN::Frame), incomingQueueStorageArea,
                                       &incomingQueueBuffer);
    vQueueAddToRegistry(incomingQueue, "CAN Incoming");
}

void CANGatekeeperTask::execute() {
    CAN::Frame message = {};

    while (true) {

        xQueueReceive(outgoingQueue, &message, portMAX_DELAY);

        CAN::Driver::send(message);
    }
}
