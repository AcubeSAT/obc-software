/*******************************************************************************
  MCAN Peripheral Library Interface Header File

  Company:
    Microchip Technology Inc.

  File Name:
    plib_mcan0.h

  Summary:
    MCAN PLIB interface declarations.

  Description:
    The MCAN plib provides a simple interface to manage the MCAN modules on
    Microchip microcontrollers. This file defines the interface declarations
    for the MCAN plib.

  Remarks:
    None.

*******************************************************************************/
//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
//DOM-IGNORE-END

#ifndef PLIB_MCAN0_H
#define PLIB_MCAN0_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

/*
 * This section lists the other files that are included in this file.
 */
#include <stdbool.h>
#include <string.h>

#include "device.h"
#include "plib_mcan_common.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
#define MCAN0_CLOCK_FREQUENCY    50000000U

/* MCAN0 Message RAM Configuration Size */
#define MCAN0_RX_FIFO0_ELEMENT_SIZE       72U
#define MCAN0_RX_FIFO0_SIZE               1440U
#define MCAN0_RX_FIFO1_ELEMENT_SIZE       72U
#define MCAN0_RX_FIFO1_SIZE               720U
#define MCAN0_TX_FIFO_BUFFER_ELEMENT_SIZE 72U
#define MCAN0_TX_FIFO_BUFFER_SIZE         720U
#define MCAN0_TX_EVENT_FIFO_SIZE          80U
#define MCAN0_STD_MSG_ID_FILTER_SIZE      4U

/* MCAN0_MESSAGE_RAM_CONFIG_SIZE to be used by application or driver
   for allocating buffer from non-cached contiguous memory */
#define MCAN0_MESSAGE_RAM_CONFIG_SIZE     2964U

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
void MCAN0_Initialize(void);
bool MCAN0_MessageTransmitFifo(uint8_t numberOfMessage, MCAN_TX_BUFFER *txBuffer);
uint8_t MCAN0_TxFifoFreeLevelGet(void);
bool MCAN0_TxBufferIsBusy(uint8_t bufferNumber);
bool MCAN0_TxEventFifoRead(uint8_t numberOfTxEvent, MCAN_TX_EVENT_FIFO *txEventFifo);
bool MCAN0_MessageReceiveFifo(MCAN_RX_FIFO_NUM rxFifoNum, uint8_t numberOfMessage, MCAN_RX_BUFFER *rxBuffer);
MCAN_ERROR MCAN0_ErrorGet(void);
void MCAN0_ErrorCountGet(uint8_t *txErrorCount, uint8_t *rxErrorCount);
void MCAN0_MessageRAMConfigSet(uint8_t *msgRAMConfigBaseAddress);
bool MCAN0_StandardFilterElementSet(uint8_t filterNumber, mcan_sidfe_registers_t *stdMsgIDFilterElement);
bool MCAN0_StandardFilterElementGet(uint8_t filterNumber, mcan_sidfe_registers_t *stdMsgIDFilterElement);
void MCAN0_SleepModeEnter(void);
void MCAN0_SleepModeExit(void);
bool MCAN0_BitTimingCalculationGet(MCAN_BIT_TIMING_SETUP *setup, MCAN_BIT_TIMING *bitTiming);
bool MCAN0_BitTimingSet(MCAN_BIT_TIMING *bitTiming);
void MCAN0_TxFifoCallbackRegister(MCAN_TX_FIFO_CALLBACK callback, uintptr_t contextHandle);
void MCAN0_TxEventFifoCallbackRegister(MCAN_TX_EVENT_FIFO_CALLBACK callback, uintptr_t contextHandle);
void MCAN0_RxFifoCallbackRegister(MCAN_RX_FIFO_NUM rxFifoNum, MCAN_RX_FIFO_CALLBACK callback, uintptr_t contextHandle);
void MCAN0_CallbackRegister(MCAN_CALLBACK callback, uintptr_t contextHandle);
// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
    }
#endif
// DOM-IGNORE-END

#endif // PLIB_MCAN0_H

/*******************************************************************************
 End of File
*/
