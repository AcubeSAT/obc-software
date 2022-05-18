#ifndef OBC_SOFTWARE_TASKLIST_H
#define OBC_SOFTWARE_TASKLIST_H

namespace TaskList{
    static XUartDMATask xUartDMATask = XUartDMATask("test", NULL, 1000, 900);
    static XTimeKeepingTask xTimeKeepingTask = XTimeKeepingTask("test2", NULL, 1000, 1100);
}

#endif //OBC_SOFTWARE_TASKLIST_H
