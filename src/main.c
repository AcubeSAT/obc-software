/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"
#include "main.h"
#include "min.h"

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
struct min_context min_ctx;

uint32_t last_send;

void min_application_handler(uint8_t min_id, uint8_t const *min_payload, uint8_t len_payload, uint8_t port)
{
    min_id++;
    min_send_frame(&min_ctx, min_id, min_payload, len_payload);
}

int main(void) {
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    SYSTICK_TimerInitialize();
    min_init_context(&min_ctx,0);
    last_send = SYSTICK_TimerCounterGet();


    while(true){
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );

        uint8_t buf[32];
        size_t buf_len;

        buf_len = USART1_Read(buf, 32);
        min_poll(&min_ctx,(uint8_t *)buf, (uint8_t)buf_len);
        uint32_t ack = 0;
        min_queue_frame(&min_ctx,0x33U , (uint8_t *)&ack , 4U);
        uint32_t now = SYSTICK_TimerCounterGet();
        if(now-last_send>1000U){

            if(!min_queue_frame(&min_ctx,0x33U , (uint8_t *)&now , 4U)){
                USART1_Write((uint8_t *)"Can't queue at time\r\n", 21);
            }

            last_send = now;
        }

    }



    /* Execution should not come here during normal operation */

    return (EXIT_FAILURE);
}







/*******************************************************************************
 End of File
*/
