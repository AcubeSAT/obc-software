#include "ECSS_Configuration.hpp"

#ifdef SERVICE_FUNCTION
#include "Platform/FunctionManagementServiceTestFunctions.hpp"
#include "ServicePool.hpp"

void FunctionManagementService::initializeFunctionMap() {
    auto &functionManagement = Services.functionManagement;
    functionManagement.include(String<ECSSFunctionNameLength>("testCustomLogFunction"), &testCustomLogFunction);
}

#endif