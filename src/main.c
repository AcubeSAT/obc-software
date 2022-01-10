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

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************


void USART1_Callback(uintptr_t context) {
    if (USART1_ErrorGet() != USART_ERROR_NONE) {
        //Handle error case
    } else {
        //Transfer completed successfully
    }
}

int main(void) {
    char data[17] = "\r\n testing \r\n";
    USART1_Initialize();
    USART1_WriteCallbackRegister(USART1_Callback, (uintptr_t) NULL);
    USART1_Write(&data, 17);

//    main_cpp();

    /* Execution should not come here during normal operation */

    return (EXIT_FAILURE);
}






/*******************************************************************************
 End of File
*/
