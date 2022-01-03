#include "FreeRTOSTasks.hpp"
#include "FreeRTOS.h"
#include "task.h"
#include "Parameters/PlatformParameters.hpp"
#include "ServicePool.hpp"

namespace FreeRTOSTasks {
    void ParameterReporting(void *) {
        const uint16_t numberOfIDs = 8;

        while (true) {
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
            request.appendUint16(PlatformParameters::AvailableStack);
            request.appendUint16(PlatformParameters::AvailableHeap);
            MessageParser::execute(request);
            vTaskDelay(pdMS_TO_TICKS(300));
        }
    }

    void ParameterUpdating(void *) {
        TaskHandle_t parameterReportingHandler = xTaskGetHandle("Task1");
        const uint16_t numberOfIDs = 2;

        while (true) {
            Message request = Message(ParameterService::ServiceType,
                                      ParameterService::MessageType::SetParameterValues,
                                      Message::TC, 1);
            request.appendUint16(numberOfIDs);
            request.appendUint16(PlatformParameters::AvailableStack);
            request.appendUint16(static_cast<uint16_t>(uxTaskGetStackHighWaterMark(parameterReportingHandler)));
            request.appendUint16(PlatformParameters::AvailableHeap);
            request.appendUint16(static_cast<uint16_t>(xPortGetFreeHeapSize()));
            MessageParser::execute(request);
            vTaskDelay(pdMS_TO_TICKS(300));
        }
    }
}