#include "CAN/Driver.hpp"
#include "CAN/Frame.hpp"
#include "CANGatekeeperTask.hpp"

CANGatekeeperTask::CANGatekeeperTask() : Task("CANGatekeeperTask") {
    CAN::Driver::initialize();

    outgoingQueue = xQueueCreateStatic(CAN::FrameQueueSize, sizeof(CAN::Frame), outgoingQueueStorageArea,
                                       &outgoingQueueBuffer);
    vQueueAddToRegistry(outgoingQueue, "CAN Outgoing");

    incomingQueue = xQueueCreateStatic(CAN::FrameQueueSize, sizeof(CAN::Frame), incomingQueueStorageArea,
                                       &incomingQueueBuffer);
    vQueueAddToRegistry(incomingQueue, "CAN Incoming");
}

void CANGatekeeperTask::execute() {
#ifdef OBC_EQM_LCL
    LCLDefinitions::lclArray[LCLDefinitions::CAN1].enableLCL();
    LCLDefinitions::lclArray[LCLDefinitions::CAN2].enableLCL();
#endif

    PIO_PinWrite(CAN::CAN_SILENT_1, false);
    PIO_PinWrite(CAN::CAN_SILENT_2, false);

    CAN::Frame message = {};

    while (true) {
        xQueueReceive(outgoingQueue, &message, portMAX_DELAY);

        CAN::Driver::send(message);
    }
}
