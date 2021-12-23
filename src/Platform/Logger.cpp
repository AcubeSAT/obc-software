#include <etl/String.hpp>
#include <ECSS_Definitions.hpp>
#include <Logger.hpp>
#include <iomanip>
#include <string>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "OBC_Definitions.h"
#include "SEGGER_RTT.h"
#include <peripheral/uart/plib_uart0.h>


void Logger::log(Logger::LogLevel level, etl::istring &message) {
    etl::string<9> name;
    etl::string<10> time;

    if (level <= Logger::trace) {
        name = "trace";
    } else if (level <= Logger::debug) {
        name = "debug";
    } else if (level <= Logger::info) {
        name = "info";
    } else if (level <= Logger::notice) {
        name = "notice";
    } else if (level <= Logger::warning) {
        name = "warning";
    } else if (level <= Logger::error) {
        name = "error";
    } else {
        name = "emergency";
    }

    etl::to_string(xTaskGetTickCount(), time, format.width(10), 0);

    char tmp[LOGGER_MAX_MESSAGE_SIZE];
    snprintf(tmp, LOGGER_MAX_MESSAGE_SIZE, "%s [%9s] %s\n", time.c_str(), name.c_str(), message.c_str());


    if (PreferRTT) {
        SEGGER_RTT_printf(0, tmp);
    } else {
        UART0_Initialize();
        UART0_Write(&tmp, sizeof(&tmp));
    }
}

// Reimplementation of the log function for C++ strings
// This is kept in the Platform files, since we don't want to mess with std::strings in the microcontroller
Logger::LogEntry &Logger::LogEntry::operator<<(const std::string &value) {
    message.append(value.c_str());

    return *this;
}
