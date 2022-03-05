#include "FreeRTOSTasks.hpp"
#include "FreeRTOS.h"
#include "task.h"
#include "PlatformParameters.hpp"
#include "ServicePool.hpp"
#include "BootCounter.hpp"
#include "definitions.h"
#include "Logger.hpp"
#include "Helpers/TimeFormats.hpp"
#include <iostream>

namespace FreeRTOSTasks {
    void reportParameters(void *) {
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
        request.appendUint16(PlatformParameters::ReportParametersUnusedStack);
        request.appendUint16(PlatformParameters::AvailableHeap);
        request.appendUint16(PlatformParameters::OBCBootCounter);
        request.appendUint16(PlatformParameters::OBCSystick);

        while (true) {
            MessageParser::execute(request);
            request.resetRead();
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }

    void updateParameters(void *taskName) {
        TaskHandle_t reportParametersHandle = xTaskGetHandle(*static_cast<const char **>(taskName));

        while (true) {
            PlatformParameters::reportParametersUnusedStack.setValue(
                    uxTaskGetStackHighWaterMark(reportParametersHandle));
            PlatformParameters::availableHeap.setValue(
                    static_cast<uint16_t>(xPortGetFreeHeapSize()));
            PlatformParameters::obcBootCounter.setValue(
                    static_cast<uint16_t>(BootCounter::GPBRRead(BootCounter::BootCounterRegister)));
            PlatformParameters::obcSysTick.setValue(static_cast<uint64_t>(xTaskGetTickCount()));
            vTaskDelay(pdMS_TO_TICKS(300));
        }
    }

    void xUartDMA(void *pvParameters) {
        etl::string<17> usartData = "testing";
        while (true) {
            LOG_DEBUG << usartData.data();
            vTaskDelay(pdMS_TO_TICKS(3000));
        }
    };

    void xTimeKeeping(void *pvParameters) {
        struct tm dateTime;

        dateTime.tm_sec = PlatformParameters::onBoardSecond.getValue();
        dateTime.tm_min = PlatformParameters::onBoardMinute.getValue();
        dateTime.tm_hour = PlatformParameters::onBoardHour.getValue();
        dateTime.tm_mon = PlatformParameters::onBoardMonth.getValue()-1;
        dateTime.tm_mday = PlatformParameters::onBoardDay.getValue();
        dateTime.tm_year = PlatformParameters::onBoardYear.getValue()-1900;
        dateTime.tm_wday = 6;

        UTC_Timestamp timestamp = UTC_Timestamp(PlatformParameters::onBoardYear.getValue(), PlatformParameters::onBoardMonth.getValue(),
                                                PlatformParameters::onBoardDay.getValue(), PlatformParameters::onBoardHour.getValue(),
                                                PlatformParameters::onBoardMinute.getValue(), PlatformParameters::onBoardSecond.getValue());
        RTC_TimeSet( &dateTime );
        while ( true ) {
            RTC_TimeGet(&dateTime);
            PlatformParameters::onBoardSecond.setValue(dateTime.tm_sec);
            PlatformParameters::onBoardMinute.setValue(dateTime.tm_min);
            PlatformParameters::onBoardHour.setValue(dateTime.tm_hour);
            PlatformParameters::onBoardDay.setValue(dateTime.tm_mday);
            PlatformParameters::onBoardMonth.setValue(dateTime.tm_mon+1);
            PlatformParameters::onBoardYear.setValue(1900 + dateTime.tm_year);
            UTC_Timestamp timestamp = UTC_Timestamp(PlatformParameters::onBoardYear.getValue(), PlatformParameters::onBoardMonth.getValue(),
                                                    PlatformParameters::onBoardDay.getValue(), PlatformParameters::onBoardHour.getValue(),
                                                    PlatformParameters::onBoardMinute.getValue(), PlatformParameters::onBoardSecond.getValue());
            //LOG_DEBUG <<timestamp; //not working
            LOG_DEBUG
            << "\rTime:" + std::to_string(dateTime.tm_hour) + "-" + std::to_string(dateTime.tm_min) + "-" + std::to_string(dateTime.tm_sec)
            + " -- " + std::to_string(PlatformParameters::onBoardDay.getValue()) + "/" +std::to_string(PlatformParameters::onBoardMonth.getValue()) + "/" + std::to_string(PlatformParameters::onBoardYear.getValue())<< "\n";
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    };
}
