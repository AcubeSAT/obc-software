#include <etl/String.hpp>
#include <ECSS_Definitions.hpp>
#include <Logger.hpp>
#include <iomanip>
#include <string>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "OBC_Definitions.hpp"
#include "SEGGER_RTT.h"
#include "definitions.h"

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
    output.append(message.c_str());
    output.append("\n");

    if (PreferRTT) {
        SEGGER_RTT_printf(0, output.c_str());
    } else {
        xQueueSendToBack(xUartQueue, &output, portMAX_DELAY);
    }
}

// Reimplementation of the log function for C++ strings
// This is kept in the Platform files, since we don't want to mess with std::strings in the microcontroller
Logger::LogEntry &Logger::LogEntry::operator<<(const std::string &value) {
    message.append(value.c_str());

    return *this;
}
