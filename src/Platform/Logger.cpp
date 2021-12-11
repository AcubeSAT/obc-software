//TODO: add UART to the project
#include <etl/String.hpp>
#include <ECSS_Definitions.hpp>
#include <Logger.hpp>
#include <iomanip>
#include <iostream>
#include <string>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#define PREFERRTT 1 //Prefer RTT communication instead of UART

#if PREFERRTT
    #include "SEGGER_RTT.h"
#else
    #include <peripheral/uart/plib_uart0.h>
#endif

void Logger::log(Logger::LogLevel level, etl::istring &message) {
    std::string name;

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

    std::ostringstream ss; // A string stream to create the log message
    ss << xTaskGetTickCount(); // The date
    ss << "[" << name << "] "; // The log level
    ss << message.c_str(); // The message itself
    ss << "\n";

    const std::string tmp = ss.str();
    const char *string = tmp.c_str();
    if (PREFERRTT) {
        SEGGER_RTT_WriteString(0, string);
    } else {
        UART0_Initialize();
        UART0_Write(&string, sizeof(&string));
    }
}
// Reimplementation of the log function for C++ strings
// This is kept in the Platform files, since we don't want to mess with std::strings in the microcontroller
Logger::LogEntry &Logger::LogEntry::operator<<(const std::string &value) {
    message.append(value.c_str());

    return *this;
}
