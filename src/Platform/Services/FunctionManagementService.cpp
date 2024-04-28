#include "ECSS_Configuration.hpp"

#ifdef SERVICE_FUNCTION

#include "Services/FunctionManagementService.hpp"
#include "Platform/FunctionManagementServiceTestFunctions.hpp"

void FunctionManagementService::initializeFunctionMap() {
    auto &functionManagement = Services.functionManagement;
    functionManagement.include((String<ECSSFunctionNameLength>("testCustomLogFunction"), &testCustomLogFunction);)
}

#endif