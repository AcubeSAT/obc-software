//TODO: Add date, UART to the project, clean up
#include <Logger.hpp>
#include "FreeRTOS.h"
#include <etl/String.hpp>
#include <iostream>
#include <ECSS_Definitions.hpp>
#include "SEGGER_RTT.h"
#include <chrono>
#include <string>
#include <iomanip>
#include <peripheral/uart/plib_uart0.h>
#include "task.h"

#define PREFERRTT 0 //Prefer RTT communication instead of UART

void Logger::log(Logger::LogLevel level, etl::istring &message) {
    // Get the current time & date
//    std::time_t t = std::time(nullptr);
//    std::tm tm = *std::localtime(&t);
    // Get the log level and its colour
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
// ss << ; // The date
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
