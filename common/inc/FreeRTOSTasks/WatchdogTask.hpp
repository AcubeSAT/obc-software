#ifndef OBC_SOFTWARE_WATCHDOGTASK_H
#define OBC_SOFTWARE_WATCHDOGTASK_H

#include "../../../inc/FreeRTOSTasks/Task.hpp"

class WatchdogTask : public Task{
private:
    /**
     * The delay in milliseconds between each watchdog reset. It is set to 14000ms, since the
     * maximum timeout is 16000ms, so the timer needs to clear before the next reset.
     * @see config/default/peripheral/wdt.c for the specific configuration.
     * Do not change this value, without also modifying the value in Harmony configurator.
     */
    const uint16_t watchdogWindow = 14000;
public:
    const static inline uint16_t taskStackDepth = 500;

    StackType_t taskStack[taskStackDepth];

    void execute();

    WatchdogTask() : Task("Watchdog") {}
};


#endif //OBC_SOFTWARE_WATCHDOGTASK_H
