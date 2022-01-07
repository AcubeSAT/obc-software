#include "FreeRTOSTasks.hpp"
#include "FreeRTOS.h"
#include "task.h"
#include "PlatformParameters.hpp"
#include "ServicePool.hpp"

namespace FreeRTOSTasks {
    void parameterReporting(void *) {
        Message request = Message(ParameterService::ServiceType,
                                  ParameterService::MessageType::ReportParameterValues,
                                  Message::TC, 1);
        const uint16_t numberOfIDs = 10;
        request.appendUint16(numberOfIDs);
        request.appendUint16(PlatformParameters::OnBoardYear);
        request.appendUint16(PlatformParameters::OnBoardMonth);
        request.appendUint16(PlatformParameters::OnBoardDay);
        request.appendUint16(PlatformParameters::OnBoardHour);
        request.appendUint16(PlatformParameters::OnBoardMinute);
        request.appendUint16(PlatformParameters::OnBoardSecond);
        request.appendUint16(PlatformParameters::AvailableStack);
        request.appendUint16(PlatformParameters::AvailableHeap);
        request.appendUint16(PlatformParameters::OBCBootCounter);
        request.appendUint16(PlatformParameters::OBCSystick);

        while (true) {
            request.readPosition = 0;
            MessageParser::execute(request);
            vTaskDelay(pdMS_TO_TICKS(300));
        }
    }

    void parameterUpdating(void *taskName) {
        TaskHandle_t parameterReportingHandle = xTaskGetHandle(*static_cast<const char **>(taskName));
        Message request = Message(ParameterService::ServiceType,
                                  ParameterService::MessageType::SetParameterValues,
                                  Message::TC, 1);
        const uint16_t numberOfIDs = 4;

        while (true) {
            request.readPosition = 0;
            request.dataSize = 0;
            request.appendUint16(numberOfIDs);
            request.appendUint16(PlatformParameters::AvailableStack);
            request.appendUint16(static_cast<uint16_t>(uxTaskGetStackHighWaterMark(parameterReportingHandle)));
            request.appendUint16(PlatformParameters::AvailableHeap);
            request.appendUint16(static_cast<uint16_t>(xPortGetFreeHeapSize()));
            request.appendUint16(PlatformParameters::OBCBootCounter);
            request.appendUint16(static_cast<uint16_t>(GPBRRead(bootCounterRegister)));
            request.appendUint16(PlatformParameters::OBCSystick);
            request.appendUint16(static_cast<uint16_t>(xTaskGetTickCount()));
            MessageParser::execute(request);
            vTaskDelay(pdMS_TO_TICKS(300));
        }
    }
}
