#include  "TimeRequestUponResetTask.hpp"
#include <TimeSyncTask.hpp>

void TimeRequestUponResetTask::execute() {

    while (true) {
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS,false,{AcubeSATParameters::ADCSOnBoardTime},false);
        vTaskSuspend(TimeRequestUponResetTaskHandle);
    }

}
