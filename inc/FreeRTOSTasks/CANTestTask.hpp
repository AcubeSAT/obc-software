#ifndef OBC_SOFTWARE_CANTESTTASK_HPP
#define OBC_SOFTWARE_CANTESTTASK_HPP

#include "CAN/Driver.hpp"
#include "pio.h"
#include "Task.hpp"

class CANTestTask : public Task {
private:

public:
    const static inline uint16_t TaskStackDepth = 1500;

    StackType_t taskStack[TaskStackDepth];

    void execute();

    CANTestTask() : Task("CAN Test") {
        PIO_PinWrite(PIO_PIN_PA11, false); //CAN_SILENT_1
        PIO_PinWrite(PIO_PIN_PD17, false); //CAN_SILENT_2
    }

    /**
     * Create freeRTOS Task
     */
    void createTask() {
        xTaskCreateStatic(vClassTask < CANTestTask > , this->TaskName, CANTestTask::TaskStackDepth, this,
                          configMAX_PRIORITIES - 1, this->taskStack, &(this->taskBuffer));
    }
};

inline std::optional<CANTestTask> canTestTask;

#endif //OBC_SOFTWARE_CANTESTTASK_HPP
