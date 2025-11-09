#include "CAN/Driver.hpp"
#include "Task.hpp"
#include <interrupts.h>
#include "CANGatekeeperTask.hpp"
#include "TimeKeepingTask.hpp"
#include "AcubeSATParameters.hpp"

using namespace AcubeSATParameters;

class RequestParamADCSTask : public Task {
private:
    static constexpr uint32_t DelayMs = 60000;

    static constexpr size_t BatchSize = 10;

    static constexpr uint16_t ParametersCount = 220;

    static constexpr uint16_t TaskStackDepth = 2500;

    StackType_t taskStack[TaskStackDepth]{};

public:
    /**
     * OBC request parameters from ADCS periodically
     */
    void execute();

    RequestParamADCSTask() : Task("RequestParamADCSTask") {}

    /**
     * Create freeRTOS Task
     */

     void createTask() {
        xTaskCreateStatic(vClassTask<RequestParamADCSTask> , this->TaskName, TaskStackDepth, this,
                        tskIDLE_PRIORITY + 2, this->taskStack, &(this->taskBuffer));
    }
};

inline std::optional<RequestParamADCSTask> requestParamADCSTask;