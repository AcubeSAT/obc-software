#ifndef OBC_SOFTWARE_RM3100TASK_HPP
#define OBC_SOFTWARE_RM3100TASK_HPP

#include "Task.hpp"
#include "RM3100.hpp"

class RM3100Task : public Task {
private:
    const uint16_t delayMs = 100;
public:
    void execute();

    /**
     * Prints the rm3100 measurements.
     */
    void printData(RM3100 &rm3100);

    RM3100Task() : Task("RM3100Task", nullptr, 1000) {}
};

#endif
