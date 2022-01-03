#include "main.h"
#include "SEGGER_RTT.h"
#include "ServicePool.hpp"
#include "FreeRTOS.h"
#include "queue.h"
#include "list.h"
#include "task.h"
#include "definitions.h"
#include "OBC_Definitions.h"
#include "Parameters/PlatformParameters.hpp"

void dateParameterReportingTask(void *pvParameters) {
    const uint16_t numberOfParametersToReport = 6;

    while (true) {
        Message request = Message(ParameterService::ServiceType, ParameterService::MessageType::ReportParameterValues,
                                  Message::TC, 1);
        request.appendUint16(numberOfParametersToReport);
        request.appendUint16(PlatformParameters::OnBoardYear);
        request.appendUint16(PlatformParameters::OnBoardMonth);
        request.appendUint16(PlatformParameters::OnBoardDay);
        request.appendUint16(PlatformParameters::OnBoardHour);
        request.appendUint16(PlatformParameters::OnBoardMinute);
        request.appendUint16(PlatformParameters::OnBoardSecond);
        MessageParser::execute(request);
    }
}

void stackUsageParameterReportingTask(void *pvParameters) {
    const uint16_t numberOfParametersToReport = 2;

    while (true) {
        Message request = Message(ParameterService::ServiceType, ParameterService::MessageType::ReportParameterValues,
                                  Message::TC, 1);
        request.appendUint16(numberOfParametersToReport);
        request.appendUint16(PlatformParameters::StackUsage1);
        request.appendUint16(PlatformParameters::StackUsage2);
        MessageParser::execute(request);
    }
}

void stackUsageParameterUpdatingTask(void *pvParameters) {

    TaskHandle_t dateParameterReportingTaskHandler = xTaskGetHandle("Task1"),
            stackUsageParameterReportingTaskHandler = xTaskGetHandle("Task2");
    const uint16_t numberOfParametersToSet = 2;

    while (true) {
        Message request = Message(ParameterService::ServiceType, ParameterService::MessageType::SetParameterValues,
                                  Message::TC, 1);
        request.appendUint16(numberOfParametersToSet);
        request.appendUint16(PlatformParameters::StackUsage1);
        request.appendUint16(FreeRTOSTaskStackDepth -
                             static_cast<uint16_t>(uxTaskGetStackHighWaterMark(dateParameterReportingTaskHandler)));
        request.appendUint16(PlatformParameters::StackUsage2);
        request.appendUint16(FreeRTOSTaskStackDepth - static_cast<uint16_t>(uxTaskGetStackHighWaterMark(
                stackUsageParameterReportingTaskHandler)));
        MessageParser::execute(request);
    }
}

extern "C" void main_cpp() {
    SYS_Initialize(NULL);

    xTaskCreate(dateParameterReportingTask, "Task1", FreeRTOSTaskStackDepth, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(stackUsageParameterReportingTask, "Task2", FreeRTOSTaskStackDepth, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(stackUsageParameterUpdatingTask, "Task3", FreeRTOSTaskStackDepth, NULL, tskIDLE_PRIORITY + 1, NULL);

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}