#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>
#include "definitions.h"                // SYS function prototypes

#define RX_BUFFER_SIZE                  10

#define LED_On()                        LED_Clear()
#define LED_Off()                       LED_Set()

char messageStart[] = "****  USART READ DEMO  ****\r\n";
char receiveBuffer[RX_BUFFER_SIZE];
char echoBuffer[RX_BUFFER_SIZE + 4];
char messageError[] = "**** USART error occurred ****\r\n";

bool errorStatus = false;
bool writeStatus = false;
bool readStatus = false;

void writeCallBackHandler(uintptr_t context)
{
    writeStatus = true;
}

void readCallBackHandler(uintptr_t context)
{
    if(USART1_ErrorGet() != USART_ERROR_NONE)
    {
        /* ErrorGet clears errors, set error flag to notify console */
        errorStatus = true;
    }
    else
    {
        readStatus = true;
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

extern "C" void main_cpp ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
//    LED_Off();

    /* Register callback functions and send start message */
    USART1_WriteCallbackRegister(&writeCallBackHandler, 0);
    USART1_ReadCallbackRegister(&readCallBackHandler, 0);
    USART1_Write(&messageStart, sizeof(messageStart));

    while ( true )
    {
        if(errorStatus == true)
        {
            /* Send error message to console */
            errorStatus = false;
            USART1_Write(&messageError, sizeof(messageError));
        }
        else if(readStatus == true)
        {
            /* Echo back received buffer */
            readStatus = false;

            echoBuffer[0] = '\n';
            echoBuffer[1] = '\r';
            memcpy(&echoBuffer[2], receiveBuffer,sizeof(receiveBuffer));
            echoBuffer[RX_BUFFER_SIZE+2] = '\n';
            echoBuffer[RX_BUFFER_SIZE+3] = '\r';

            USART1_Write(&echoBuffer, sizeof(echoBuffer));
        }
        else if(writeStatus == true)
        {
            /* Submit buffer to read user data */
            writeStatus = false;
            USART1_Read(&receiveBuffer, sizeof(receiveBuffer));
        }
        else
        {
            /* Repeat the loop */
            ;
        }
    }
}

//#include <stddef.h>                     // Defines NULL
//#include <stdbool.h>                    // Defines true
//#include <stdlib.h>                     // Defines EXIT_FAILURE
//#include <string.h>
//#include <stdio.h>
//#include "definitions.h"                // SYS function prototypes
//
//uint8_t txBuffer[50];
//uint8_t rxBuffer[10];
//volatile uint32_t nBytesRead = 0;
//volatile bool txThresholdEventReceived = false;
//volatile bool rxThresholdEventReceived = false;
//
//// *****************************************************************************
//// *****************************************************************************
//// Section: Main Entry Point
//// *****************************************************************************
//// *****************************************************************************
//
//void usartReadEventHandler(USART_EVENT event, uintptr_t context )
//{
//    uint32_t nBytesAvailable = 0;
//
//    if (event == USART_EVENT_READ_THRESHOLD_REACHED)
//    {
//        /* Receiver should atleast have the thershold number of bytes in the ring buffer */
//        nBytesAvailable = USART1_ReadCountGet();
//
//        nBytesRead += USART1_Read((uint8_t*)&rxBuffer[nBytesRead], nBytesAvailable);
//    }
//}
//
//void usartWriteEventHandler(USART_EVENT event, uintptr_t context )
//{
//    txThresholdEventReceived = true;
//}
//
//int main ( void )
//{
//    uint32_t nBytes = 0;
//
//    /* Initialize all modules */
//    SYS_Initialize ( NULL );
//    USART1_Initialize();
//
//    /* Register a callback for write events */
//    USART1_WriteCallbackRegister(usartWriteEventHandler, (uintptr_t) NULL);
//
//    /* Register a callback for read events */
//    USART1_ReadCallbackRegister(usartReadEventHandler, (uintptr_t) NULL);
//
//    /* Print the size of the read buffer on the terminal */
//    nBytes = sprintf((char*)txBuffer, "RX Buffer Size = %d\r\n", (int)USART1_ReadBufferSizeGet());
//
//    USART1_Write((uint8_t*)txBuffer, nBytes);
//
//    /* Print the size of the write buffer on the terminal */
//    nBytes = sprintf((char*)txBuffer, "TX Buffer Size = %d\r\n", (int)USART1_WriteBufferSizeGet());
//
//    USART1_Write((uint8_t*)txBuffer, nBytes);
//
//    USART1_Write((uint8_t*)"Adding 10 characters to the TX buffer - ", sizeof("Adding 10 characters to the TX buffer - "));
//
//    /* Wait for all bytes to be transmitted out */
//    while (USART1_WriteCountGet() != 0);
//
//    USART1_Write((uint8_t*)"0123456789", 10);
//
//    /* Print the amount of free space available in the TX buffer. This should be 10 bytes less than the configured write buffer size. */
//    nBytes = sprintf((char*)txBuffer, "\r\nFree Space in Transmit Buffer = %d\r\n", (int)USART1_WriteFreeBufferCountGet());
//
//    USART1_Write((uint8_t*)txBuffer, nBytes);
//
//    /* Let's enable notifications to get notified when the TX buffer is empty */
//    USART1_WriteThresholdSet(USART1_WriteBufferSizeGet());
//
//    /* Enable notifications */
//    USART1_WriteNotificationEnable(true, false);
//
//    /* Wait for the TX buffer to become empty. Flag "txThresholdEventReceived" is set in the callback. */
//    while (txThresholdEventReceived == false);
//
//    txThresholdEventReceived = false;
//
//    /* Disable TX notifications */
//    USART1_WriteNotificationEnable(false, false);
//
//    USART1_Write((uint8_t*)"Enter 10 characters. The received characters are echoed back. \r\n>", sizeof("Enter 10 characters. The received characters are echoed back. \r\n>"));
//
//    /* Wait till 10 (or more) characters are received */
//    while (USART1_ReadCountGet() < 10);
//
//    /* At-least 10 characters are available in the RX buffer. Read out into the application buffer */
//    USART1_Read((uint8_t*)rxBuffer, 10);
//
//    /* Echo the received data */
//    USART1_Write((uint8_t*)rxBuffer, 10);
//
//    /* Now demonstrating receiver notifications */
//    USART1_Write((uint8_t*)"\r\n Now turning on RX notifications \r\n>", sizeof("\r\n Now turning on RX notifications \r\n>"));
//
//    /* For demonstration purpose, set a threshold value to receive a callback after every 5 characters are received */
//    USART1_ReadThresholdSet(5);
//
//    /* Enable RX event notifications */
//    USART1_ReadNotificationEnable(true, false);
//
//    while(1)
//    {
//        /* Wait until at-least 10 characters are entered by the user */
//        while (nBytesRead < 10);
//
//        /* Echo the received data */
//        USART1_Write((uint8_t*)rxBuffer, nBytesRead);
//
//        USART1_Write((uint8_t*)"\r\n>", 3);
//
//        nBytesRead = 0;
//    }
//
//    /* Execution should not come here during normal operation */
//
//    return ( EXIT_FAILURE );
//}
