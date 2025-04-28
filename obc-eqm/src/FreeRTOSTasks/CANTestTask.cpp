#include "CANTestTask.hpp"
#include "CANGatekeeperTask.hpp"

void CANTestTask::execute() {

    while (true) {
        CAN::Application::sendPingMessage(CAN::ADCS, false);
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}