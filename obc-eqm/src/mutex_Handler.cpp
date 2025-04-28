#include "mutex_Handler.h"


SemaphoreHandle_t Semaphore_Group_A = NULL;
SemaphoreHandle_t Semaphore_Group_B = NULL;
SemaphoreHandle_t Semaphore_Group_C = NULL;

StaticSemaphore_t Semaphore_Group_A_buffer;
StaticSemaphore_t Semaphore_Group_B_buffer;
StaticSemaphore_t Semaphore_Group_C_buffer;

void initializeSemaphores() {
    Semaphore_Group_A = xSemaphoreCreateMutexStatic(&Semaphore_Group_A_buffer);
    Semaphore_Group_B = xSemaphoreCreateMutexStatic(&Semaphore_Group_B_buffer);
    Semaphore_Group_C = xSemaphoreCreateMutexStatic(&Semaphore_Group_C_buffer);

    configASSERT(Semaphore_Group_A);
    configASSERT(Semaphore_Group_B);
    configASSERT(Semaphore_Group_C);
}

/**
 * @brief Function that handles the acquisition of Semaphores for the different available Groups.
 * !important : Do not use this function from an ISR
 *
 * @param group Semaphore GROUP A,B or C
 * @return true
 * @return false
 */
bool takeSemaphoreGroup(smphr_groups group) {
    switch (group) {
        case GROUP_A: {
            if (xSemaphoreTake(Semaphore_Group_A, (TickType_t) 10) == pdTRUE) {
                return true;
            }
        } break;
        case GROUP_B: {
            if (xSemaphoreTake(Semaphore_Group_B, (TickType_t) 10) == pdTRUE) {
                return true;
            }
        } break;
        case GROUP_C: {
            if (xSemaphoreTake(Semaphore_Group_C, (TickType_t) 10) == pdTRUE) {
                return true;
            }
        } break;
        default:
            break;
    }
    return false;
}

void releaseSemaphoreGroup(smphr_groups group) {
    switch (group) {
        case GROUP_A:
            xSemaphoreGive(Semaphore_Group_A);
        break;
        case GROUP_B:
            xSemaphoreGive(Semaphore_Group_B);
        break;
        case GROUP_C:
            xSemaphoreGive(Semaphore_Group_C);
        break;
        default:
            break;
    }
}