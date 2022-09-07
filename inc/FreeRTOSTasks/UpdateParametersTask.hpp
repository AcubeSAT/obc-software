#ifndef OBC_SOFTWARE_UPDATEPARAMETERSTASK_HPP
#define OBC_SOFTWARE_UPDATEPARAMETERSTASK_HPP

#include "Task.hpp"

/**
 * FreeRTOS task for periodically updating specific parameters using ParameterService functionality.
 */
class UpdateParametersTask : public Task {
private:
    const uint16_t delayMs = 3000;
public:
    const static inline uint16_t TaskStackDepth = 6000;

    StackType_t taskStack[TaskStackDepth];

    void execute();

    UpdateParametersTask() : Task("ParameterUpdating") {}


    /**
     *
     * @brief Initialize the freeRTOS UpdateParametersTask Task
     *
     */
    void createTask() {
        xTaskCreateStatic(vClassTask<UpdateParametersTask>, this->TaskName,
                          UpdateParametersTask::TaskStackDepth,
                          this, tskIDLE_PRIORITY + 1, this->taskStack,
                          &(this->taskBuffer));
    }
};

inline std::optional<UpdateParametersTask> updateParametersTask;

#endif
