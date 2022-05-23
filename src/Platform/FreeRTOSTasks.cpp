#include "FreeRTOSTasks.hpp"
#include "FreeRTOS.h"
#include "task.h"
#include "PlatformParameters.hpp"
#include "ServicePool.hpp"
#include "BootCounter.hpp"
#include "definitions.h"
#include "Logger.hpp"
#include "RTCHelper.hpp"
#include "Parameters/HousekeepingService.hpp"
#include "RM3100.hpp"


namespace FreeRTOSTasks {
    void reportParameters(void *) {
        Message request = Message(ParameterService::ServiceType,
                                  ParameterService::MessageType::ReportParameterValues,
                                  Message::TC, 1);
        const uint16_t numberOfIDs = 11;
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
            PlatformParameters::onBoardSecond.setValue(static_cast<uint64_t>(xTaskGetTickCount() / 1000));
            vTaskDelay(pdMS_TO_TICKS(300));
        }
    }

    void xUartDMA(void *pvParameters) {
        etl::string<17> usartData = "\rtesting";
        while (true) {
            LOG_DEBUG << usartData.data();
            vTaskDelay(pdMS_TO_TICKS(3000));
        }
    };

    void xTimeKeeping(void *pvParameters) {
        static tm dateTime;
        setEpoch(dateTime);
        RTC_TimeSet(&dateTime);

        while (true) {
            RTC_TimeGet(&dateTime);
            setTimePlatformParameters(dateTime);

            printOnBoardTime();
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    };

    void housekeeping(void *pvParameters) {
        auto &housekeeping = Services.housekeeping;
        uint32_t nextCollection = 0;
        uint32_t timeBeforeDelay = 0;
        TickType_t xLastWakeTime = xTaskGetTickCount();

        while (true) {
            nextCollection = housekeeping.reportPendingStructures(xTaskGetTickCount(), timeBeforeDelay, nextCollection);
            timeBeforeDelay = xTaskGetTickCount();
            vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(nextCollection));
        }
    }

    void temperatureTask(void *pvParameters) {
        while (true) {
            AFEC0_ConversionStart();
            vTaskDelay(pdMS_TO_TICKS(1));
            uint16_t ADCconversion = AFEC0_ChannelResultGet(AFEC_CH11);
            float voltageConversion = static_cast<float>(ADCconversion) * PositiveVoltageReference / MaxADCValue;
            const float MCUtemperature =
                    (voltageConversion - TypicalVoltageAt25) / TemperatureSensitivity + ReferenceTemperature;
            LOG_DEBUG << "The temperature of the MCU is: " << MCUtemperature << " degrees Celsius";
            PlatformParameters::mcuTemperature.setValue(MCUtemperature);
            vTaskDelay(pdMS_TO_TICKS(10000));
        }
    }

    void RM3100Magnetometer(void *pvParameters) {

        RM3100 rm3100(1, 0b01111001, 200, PIO_PIN_PB2, PIO_PIN_PB3);
        rm3100.checkREVID();

        while (true) {
            rm3100.readMeasurements();

            etl::string<80> Data = "";
            Data += "x=";
            etl::to_string(rm3100.x / rm3100.gain, Data, etl::format_spec().precision(6), true);
            Data += " y=";
            etl::to_string(rm3100.y / rm3100.gain, Data, etl::format_spec().precision(6), true);
            Data += " z=";
            etl::to_string(rm3100.z / rm3100.gain, Data, etl::format_spec().precision(6), true);
            Data += " magneticField=";
            etl::to_string(rm3100.magneticField, Data, etl::format_spec().precision(9), true);
            Data += "\r\n";

            LOG_DEBUG << Data.data();
            SYSTICK_DelayMs(100);
        }
    }
};
