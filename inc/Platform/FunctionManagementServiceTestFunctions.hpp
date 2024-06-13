#pragma once

#ifdef SERVICE_FUNCTION
#include "Services/FunctionManagementService.hpp"

/**
 * This file includes functions that are used for testing the FunctionManagementService integration in embedded systems.
 * These should be removed in the final version of the software.
 * For now they'll be used as placeholder/example on how custom function can be called through the
 * the FunctionManagementService, and through a TC (subsequently).
 */
void testCustomLogFunction(String<ECSSFunctionMaxArgLength> a) {
    LOG_DEBUG << "Custom log function called with its first argument: " << a[0];
    LOG_DEBUG << "Custom log function called with its second argument: " << a[1];
}

#endif
