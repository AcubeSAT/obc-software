#include "OBTtoADCSTask.hpp"
#include "CANGatekeeperTask.hpp"
#include "TimeKeepingTask.hpp"
#include "AcubeSATParameters.hpp"

void OBTtoADCSTask::execute() {
    CAN::Application::switchBus(CAN::Driver::Main);
    CAN::Frame frame = {CAN::NodeID};
    for (auto i = 0; i < CAN::Frame::MaxDataLength; i++) {
        frame.data.at(i) = i;
    }

    while (true) {
        using namespace AcubeSATParameters;
        CAN::Application::createSendParametersMessage(CAN::NodeIDs::ADCS, false,{OBCOnBoardTime}, false);
		canGatekeeperTask->send(frame);

        vTaskDelay(pdMS_TO_TICKS(2500));
    }

}



