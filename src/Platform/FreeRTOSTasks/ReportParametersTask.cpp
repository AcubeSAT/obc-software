#include "FreeRTOSTasks/ReportParametersTask.hpp"

void ReportParametersTask::execute() {
    Message request = Message(ParameterService::ServiceType,
                              ParameterService::MessageType::ReportParameterValues,
                              Message::TC, 1);
    request.appendUint16(numberOfIDs);
    request.appendUint16(PlatformParameters::OnBoardYear);
    request.appendUint16(PlatformParameters::OnBoardMonth);
    request.appendUint16(PlatformParameters::OnBoardDay);
    request.appendUint16(PlatformParameters::OnBoardHour);
    request.appendUint16(PlatformParameters::OnBoardMinute);
    request.appendUint16(PlatformParameters::OnBoardSecond);
    request.appendUint16(PlatformParameters::ReportParametersUnusedStack);
    request.appendUint16(PlatformParameters::AvailableHeap);
    request.appendUint16(PlatformParameters::OBCBootCounter);
    request.appendUint16(PlatformParameters::OBCSystick);
    request.appendUint16(PlatformParameters::OBCMCUTemperature);

    while (true) {
        MessageParser::execute(request);
        request.resetRead();
        vTaskDelay(pdMS_TO_TICKS(delayMs));
    }
}
