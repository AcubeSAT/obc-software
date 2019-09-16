/**
 * @file
 * This file specifies the Log handlers for any logging messages. Logs are all sent through UART1.
 */

#include <cstring>
#include "Logger.hpp"
#include "main.h"

void Logger::log(Logger::LogLevel level, etl::istring & message) {
    char uartMessage[256];
    char name[10];

    if (level <= Logger::trace) {
        strcpy(name, "trace");
    } else if (level <= Logger::debug) {
        strcpy(name, "debug");
    } else if (level <= Logger::info) {
        strcpy(name, "info");
    } else if (level <= Logger::notice) {
        strcpy(name, "notice");
    } else if (level <= Logger::warning) {
        strcpy(name, "warning");
    } else if (level <= Logger::error) {
        strcpy(name, "error");
    } else {
        strcpy(name, "emergency");
    }

    snprintf(uartMessage, 256, "%-7lu [%-7s] %s\r\n", HAL_GetTick(), name, message.c_str());
    HAL_UART_Transmit(&huart1, reinterpret_cast<uint8_t *>(uartMessage), strlen(uartMessage), HAL_MAX_DELAY);
}
