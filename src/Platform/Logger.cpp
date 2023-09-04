#include <etl/String.hpp>
#include <ECSS_Definitions.hpp>
#include <Logger.hpp>
#include <iomanip>
#include <string>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "SEGGER_RTT.h"
#include "ServicePool.hpp"
#include "UARTGatekeeperTask.hpp"

void Logger::log(Logger::LogLevel level, etl::istring &message) {
    etl::string<MaxLogNameSize> levelString;
    etl::string<MaxTickCountStringSize> time;

    if (level <= Logger::trace) {
        levelString.append("trace");
    } else if (level <= Logger::debug) {
        levelString.append("debug");
    } else if (level <= Logger::info) {
        levelString.append("info");
    } else if (level <= Logger::notice) {
        levelString.append("notice");
    } else if (level <= Logger::warning) {
        levelString.append("warning");
    } else if (level <= Logger::error) {
        levelString.append("error");
    } else {
        levelString = "emergency";
    }

    while (levelString.available()) {
        levelString.append(" ");
    }

    etl::to_string(xTaskGetTickCount(), time, format.width(MaxTickCountStringSize), 0);

    etl::string<LOGGER_MAX_MESSAGE_SIZE> output;
    output.append(time.c_str());
    output.append(" [");
    output.append(levelString.c_str());
    output.append("] ");

    etl::string<LogSource::MaximumLettersInSubsystemName + 1> subsystemString = LogSource::currentSubsystem;
    if (LogSource::currentSubsystem.empty()) {
        subsystemString = "None ";
    }
    while (subsystemString.available()) {
        subsystemString.append(" ");
    }
    output.append(subsystemString.c_str());

    output.append(message.c_str());
    output.append("\n");

    if (CommonParameters::useRTT.getValue()) {
        SEGGER_RTT_printf(0, output.c_str());
    }
    if (CommonParameters::useUART.getValue()) {
        if (uartGatekeeperTask) {
            uartGatekeeperTask->addToQueue(output);
        }
    }
    if (CommonParameters::useCAN.getValue()) {
        Services.dummyService.logAsECSSMessage(output);
    }
}

template<>
void convertValueToString(String<LOGGER_MAX_MESSAGE_SIZE>& message, char* value) {
    message.append(value);
}

template<>
void convertValueToString(String<LOGGER_MAX_MESSAGE_SIZE>& message, const char* value)  {
    message.append(value);
}
