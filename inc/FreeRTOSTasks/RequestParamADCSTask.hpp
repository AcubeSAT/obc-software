#include "CAN/Driver.hpp"
#include "Task.hpp"

using namespace AcubeSATParameters;

class RequestParamADCSTask : public Task {
private:
    const uint16_t DelayMs = 60000;
public:
    const static inline uint16_t TaskStackDepth = 5000;

    StackType_t taskStack[TaskStackDepth];

    void execute();

    RequestParamADCSTask() : Task("OBC Request Parameters from ADCS through CAN") {}

    /**
     * Create freeRTOS Task
     */

     void createTask() {
        xTaskCreateStatic(vClassTask < RequestParamADCSTask > , this->TaskName, RequestParamADCSTask::TaskStackDepth, this,
                        tskIDLE_PRIORITY  +  2, this->taskStack, &(this->taskBuffer));
    }
};

inline std::optional<RequestParamADCSTask> requestParamADCSTask;