#include "CAN/Driver.hpp"
#include "Task.hpp"

using namespace AcubeSATParameters;

class RequestParamADCSTask : public Task {
public:
    const static inline uint16_t TaskStackDepth = 2300;

    StackType_t taskStack[TaskStackDepth];

    void execute();

    RequestParamADCSTask() : Task("") {}

    /**
     * Create freeRTOS Task
     */

     void createTask() {
        xTaskCreateStatic(vClassTask < RequestParamADCSTask > , this->TaskName, RequestParamADCSTask::TaskStackDepth, this,
                        tskIDLE_PRIORITY  +  2, this->taskStack, &(this->taskBuffer));
    }
};

inline std::optional<RequestParamADCSTask> requestParamADCSTask;