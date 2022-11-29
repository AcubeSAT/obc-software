#include "CANTestTask.hpp"
#include "CANGatekeeperTask.hpp"

void CANTestTask::execute() {
    CAN::Frame message = {};

    message.id = 0x44A;
    for (uint8_t idx = 0; idx < CAN::Frame::MaxDataLength; idx++) {
        message.data.push_back(idx);
    }

    while (true) {
        canGatekeeperTask->send(message);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}