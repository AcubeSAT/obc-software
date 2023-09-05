#include "CANTestTask.hpp"
#include "CANGatekeeperTask.hpp"

void CANTestTask::execute() {
    CAN::Application::switchBus(CAN::Driver::Redundant);
//    CAN::Frame message = {};
//
//    /**
//     * Simple 64 byte message sending
//     */
//    message.id = 0x10A;
//    for (uint8_t idx = 0; idx < CAN::Frame::MaxDataLength; idx++) {
//        message.data.push_back(idx);
//    }
//
//    while (true) {
//        canGatekeeperTask->send(message);
//        vTaskDelay(pdMS_TO_TICKS(1000));
//    }

    /**
     * Ping messages to OBC
     */
//    while (true) {
//        CAN::Application::sendPingMessage(CAN::Application::NodeIDs::OBC, false);
//        vTaskDelay(pdMS_TO_TICKS(1000));
//    }

    /**
     * Housekeeping parameters sending
     */
//    while (true) {
//        CAN::Application::createSendParametersMessage(CAN::Application::NodeIDs::OBC, false, {2, 7}, false);
//        vTaskDelay(pdMS_TO_TICKS(1000));
//    }

    /**
     * Log messages utilizing multiple messages
     */
    while (true) {
        const String<ECSSMaxMessageSize> logString = "This is a log message going from the development board to the eqm that consists of more than 64 chars";
        CAN::Application::createLogMessage(CAN::NodeIDs::OBC, true, logString, false);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}