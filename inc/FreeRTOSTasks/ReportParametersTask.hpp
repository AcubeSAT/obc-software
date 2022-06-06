#ifndef OBC_SOFTWARE_REPORTPARAMETERSTASK_HPP
#define OBC_SOFTWARE_REPORTPARAMETERSTASK_HPP

#include "Task.hpp"

/**
 * FreeRTOS task for periodically reporting specific parameters using ParameterService functionality.
 * @see ParameterService
 */
class ReportParametersTask : public Task {
private:
    const uint16_t numberOfIDs = 11;
    const uint16_t delayMs = 1000;
public:
    void execute();

    ReportParametersTask() : Task("ParameterReporting", nullptr, 1000) {}
};

#endif
