#include "CAN/Driver.hpp"
#include "Task.hpp"
#include <interrupts.h>
#include "CANGatekeeperTask.hpp"
#include "TimeKeepingTask.hpp"
#include "AcubeSATParameters.hpp"

using namespace AcubeSATParameters;

class RequestParamADCSTask : public Task {
private:
    const uint16_t DelayMs = 60000;

    static constexpr size_t BATCH_SIZE = 10;

    static constexpr uint16_t parametersCount = 220;

    static constexpr uint16_t TaskStackDepth = 2500;

    StackType_t taskStack[TaskStackDepth]{};

public:
    void execute();

    RequestParamADCSTask() : Task("OBC Request Parameters from ADCS through CAN") {}

    /**
     * Create freeRTOS Task
     */

     void createTask() {
        xTaskCreateStatic(vClassTask<RequestParamADCSTask> , this->TaskName, TaskStackDepth, this,
                        tskIDLE_PRIORITY + 2, this->taskStack, &(this->taskBuffer));
    }
};

inline std::optional<RequestParamADCSTask> requestParamADCSTask;