/*******************************************************************************
  PIO PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_pio.h

  Summary:
    PIO PLIB Header File

  Description:
    This library provides an interface to control and interact with Parallel
    Input/Output controller (PIO) module.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

#ifndef PLIB_PIO_H
#define PLIB_PIO_H

#include "device.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data types and constants
// *****************************************************************************
// *****************************************************************************


/*** Macros for MEM_D0 pin ***/
#define MEM_D0_Get()               ((PIOC_REGS->PIO_PDSR >> 0) & 0x1)
#define MEM_D0_PIN                  PIO_PIN_PC0

/*** Macros for MEM_A9 pin ***/
#define MEM_A9_Get()               ((PIOC_REGS->PIO_PDSR >> 27) & 0x1)
#define MEM_A9_PIN                  PIO_PIN_PC27

/*** Macros for MEM_A8 pin ***/
#define MEM_A8_Get()               ((PIOC_REGS->PIO_PDSR >> 26) & 0x1)
#define MEM_A8_PIN                  PIO_PIN_PC26

/*** Macros for MEM_A13 pin ***/
#define MEM_A13_Get()               ((PIOC_REGS->PIO_PDSR >> 31) & 0x1)
#define MEM_A13_PIN                  PIO_PIN_PC31

/*** Macros for MEM_A12 pin ***/
#define MEM_A12_Get()               ((PIOC_REGS->PIO_PDSR >> 30) & 0x1)
#define MEM_A12_PIN                  PIO_PIN_PC30

/*** Macros for MEM_A11 pin ***/
#define MEM_A11_Get()               ((PIOC_REGS->PIO_PDSR >> 29) & 0x1)
#define MEM_A11_PIN                  PIO_PIN_PC29

/*** Macros for CAN_RX_2 pin ***/
#define CAN_RX_2_Get()               ((PIOC_REGS->PIO_PDSR >> 12) & 0x1)
#define CAN_RX_2_PIN                  PIO_PIN_PC12

/*** Macros for LCL_MRAM_RST pin ***/
#define LCL_MRAM_RST_Set()               (PIOC_REGS->PIO_SODR = (1<<15))
#define LCL_MRAM_RST_Clear()             (PIOC_REGS->PIO_CODR = (1<<15))
#define LCL_MRAM_RST_Toggle()            (PIOC_REGS->PIO_ODSR ^= (1<<15))
#define LCL_MRAM_RST_OutputEnable()      (PIOC_REGS->PIO_OER = (1<<15))
#define LCL_MRAM_RST_InputEnable()       (PIOC_REGS->PIO_ODR = (1<<15))
#define LCL_MRAM_RST_Get()               ((PIOC_REGS->PIO_PDSR >> 15) & 0x1)
#define LCL_MRAM_RST_PIN                  PIO_PIN_PC15

/*** Macros for LCL_MRAM_SET pin ***/
#define LCL_MRAM_SET_Set()               (PIOC_REGS->PIO_SODR = (1<<13))
#define LCL_MRAM_SET_Clear()             (PIOC_REGS->PIO_CODR = (1<<13))
#define LCL_MRAM_SET_Toggle()            (PIOC_REGS->PIO_ODSR ^= (1<<13))
#define LCL_MRAM_SET_OutputEnable()      (PIOC_REGS->PIO_OER = (1<<13))
#define LCL_MRAM_SET_InputEnable()       (PIOC_REGS->PIO_ODR = (1<<13))
#define LCL_MRAM_SET_Get()               ((PIOC_REGS->PIO_PDSR >> 13) & 0x1)
#define LCL_MRAM_SET_PIN                  PIO_PIN_PC13

/*** Macros for LCL_PWM_MRAM pin ***/
#define LCL_PWM_MRAM_Get()               ((PIOB_REGS->PIO_PDSR >> 1) & 0x1)
#define LCL_PWM_MRAM_PIN                  PIO_PIN_PB1

/*** Macros for LCL_PWM_NAND pin ***/
#define LCL_PWM_NAND_Get()               ((PIOB_REGS->PIO_PDSR >> 0) & 0x1)
#define LCL_PWM_NAND_PIN                  PIO_PIN_PB0

/*** Macros for MEM_A16 pin ***/
#define MEM_A16_Get()               ((PIOA_REGS->PIO_PDSR >> 20) & 0x1)
#define MEM_A16_PIN                  PIO_PIN_PA20

/*** Macros for MEM_A15 pin ***/
#define MEM_A15_Get()               ((PIOA_REGS->PIO_PDSR >> 19) & 0x1)
#define MEM_A15_PIN                  PIO_PIN_PA19

/*** Macros for MEM_A14 pin ***/
#define MEM_A14_Get()               ((PIOA_REGS->PIO_PDSR >> 18) & 0x1)
#define MEM_A14_PIN                  PIO_PIN_PA18

/*** Macros for LCL_NAND_SET pin ***/
#define LCL_NAND_SET_Set()               (PIOA_REGS->PIO_SODR = (1<<17))
#define LCL_NAND_SET_Clear()             (PIOA_REGS->PIO_CODR = (1<<17))
#define LCL_NAND_SET_Toggle()            (PIOA_REGS->PIO_ODSR ^= (1<<17))
#define LCL_NAND_SET_OutputEnable()      (PIOA_REGS->PIO_OER = (1<<17))
#define LCL_NAND_SET_InputEnable()       (PIOA_REGS->PIO_ODR = (1<<17))
#define LCL_NAND_SET_Get()               ((PIOA_REGS->PIO_PDSR >> 17) & 0x1)
#define LCL_NAND_SET_PIN                  PIO_PIN_PA17

/*** Macros for CAN_TX_1 pin ***/
#define CAN_TX_1_Get()               ((PIOB_REGS->PIO_PDSR >> 2) & 0x1)
#define CAN_TX_1_PIN                  PIO_PIN_PB2

/*** Macros for LCL_NAND_RST pin ***/
#define LCL_NAND_RST_Set()               (PIOE_REGS->PIO_SODR = (1<<4))
#define LCL_NAND_RST_Clear()             (PIOE_REGS->PIO_CODR = (1<<4))
#define LCL_NAND_RST_Toggle()            (PIOE_REGS->PIO_ODSR ^= (1<<4))
#define LCL_NAND_RST_OutputEnable()      (PIOE_REGS->PIO_OER = (1<<4))
#define LCL_NAND_RST_InputEnable()       (PIOE_REGS->PIO_ODR = (1<<4))
#define LCL_NAND_RST_Get()               ((PIOE_REGS->PIO_PDSR >> 4) & 0x1)
#define LCL_NAND_RST_PIN                  PIO_PIN_PE4

/*** Macros for ADM_DEPLOY_3 pin ***/
#define ADM_DEPLOY_3_Set()               (PIOE_REGS->PIO_SODR = (1<<5))
#define ADM_DEPLOY_3_Clear()             (PIOE_REGS->PIO_CODR = (1<<5))
#define ADM_DEPLOY_3_Toggle()            (PIOE_REGS->PIO_ODSR ^= (1<<5))
#define ADM_DEPLOY_3_OutputEnable()      (PIOE_REGS->PIO_OER = (1<<5))
#define ADM_DEPLOY_3_InputEnable()       (PIOE_REGS->PIO_ODR = (1<<5))
#define ADM_DEPLOY_3_Get()               ((PIOE_REGS->PIO_PDSR >> 5) & 0x1)
#define ADM_DEPLOY_3_PIN                  PIO_PIN_PE5

/*** Macros for CAN_RX_1 pin ***/
#define CAN_RX_1_Get()               ((PIOB_REGS->PIO_PDSR >> 3) & 0x1)
#define CAN_RX_1_PIN                  PIO_PIN_PB3

/*** Macros for ADM_DEPLOY_2 pin ***/
#define ADM_DEPLOY_2_Set()               (PIOD_REGS->PIO_SODR = (1<<30))
#define ADM_DEPLOY_2_Clear()             (PIOD_REGS->PIO_CODR = (1<<30))
#define ADM_DEPLOY_2_Toggle()            (PIOD_REGS->PIO_ODSR ^= (1<<30))
#define ADM_DEPLOY_2_OutputEnable()      (PIOD_REGS->PIO_OER = (1<<30))
#define ADM_DEPLOY_2_InputEnable()       (PIOD_REGS->PIO_ODR = (1<<30))
#define ADM_DEPLOY_2_Get()               ((PIOD_REGS->PIO_PDSR >> 30) & 0x1)
#define ADM_DEPLOY_2_PIN                  PIO_PIN_PD30

/*** Macros for MCU_RTC_IN pin ***/
#define MCU_RTC_IN_Get()               ((PIOA_REGS->PIO_PDSR >> 7) & 0x1)
#define MCU_RTC_IN_PIN                  PIO_PIN_PA7

/*** Macros for MCU_RTC_OUT pin ***/
#define MCU_RTC_OUT_Get()               ((PIOA_REGS->PIO_PDSR >> 8) & 0x1)
#define MCU_RTC_OUT_PIN                  PIO_PIN_PA8

/*** Macros for ADM_ENABLE_1 pin ***/
#define ADM_ENABLE_1_Set()               (PIOA_REGS->PIO_SODR = (1<<22))
#define ADM_ENABLE_1_Clear()             (PIOA_REGS->PIO_CODR = (1<<22))
#define ADM_ENABLE_1_Toggle()            (PIOA_REGS->PIO_ODSR ^= (1<<22))
#define ADM_ENABLE_1_OutputEnable()      (PIOA_REGS->PIO_OER = (1<<22))
#define ADM_ENABLE_1_InputEnable()       (PIOA_REGS->PIO_ODR = (1<<22))
#define ADM_ENABLE_1_Get()               ((PIOA_REGS->PIO_PDSR >> 22) & 0x1)
#define ADM_ENABLE_1_PIN                  PIO_PIN_PA22

/*** Macros for MEM_D1 pin ***/
#define MEM_D1_Get()               ((PIOC_REGS->PIO_PDSR >> 1) & 0x1)
#define MEM_D1_PIN                  PIO_PIN_PC1

/*** Macros for MEM_D2 pin ***/
#define MEM_D2_Get()               ((PIOC_REGS->PIO_PDSR >> 2) & 0x1)
#define MEM_D2_PIN                  PIO_PIN_PC2

/*** Macros for MEM_D3 pin ***/
#define MEM_D3_Get()               ((PIOC_REGS->PIO_PDSR >> 3) & 0x1)
#define MEM_D3_PIN                  PIO_PIN_PC3

/*** Macros for MEM_D4 pin ***/
#define MEM_D4_Get()               ((PIOC_REGS->PIO_PDSR >> 4) & 0x1)
#define MEM_D4_PIN                  PIO_PIN_PC4

/*** Macros for ADM_DEPLOY_1 pin ***/
#define ADM_DEPLOY_1_Set()               (PIOA_REGS->PIO_SODR = (1<<13))
#define ADM_DEPLOY_1_Clear()             (PIOA_REGS->PIO_CODR = (1<<13))
#define ADM_DEPLOY_1_Toggle()            (PIOA_REGS->PIO_ODSR ^= (1<<13))
#define ADM_DEPLOY_1_OutputEnable()      (PIOA_REGS->PIO_OER = (1<<13))
#define ADM_DEPLOY_1_InputEnable()       (PIOA_REGS->PIO_ODR = (1<<13))
#define ADM_DEPLOY_1_Get()               ((PIOA_REGS->PIO_PDSR >> 13) & 0x1)
#define ADM_DEPLOY_1_PIN                  PIO_PIN_PA13

/*** Macros for MEM_A19 pin ***/
#define MEM_A19_Get()               ((PIOA_REGS->PIO_PDSR >> 23) & 0x1)
#define MEM_A19_PIN                  PIO_PIN_PA23

/*** Macros for I2C_MTQ_SDA pin ***/
#define I2C_MTQ_SDA_Get()               ((PIOD_REGS->PIO_PDSR >> 27) & 0x1)
#define I2C_MTQ_SDA_PIN                  PIO_PIN_PD27

/*** Macros for MEM_D7 pin ***/
#define MEM_D7_Get()               ((PIOC_REGS->PIO_PDSR >> 7) & 0x1)
#define MEM_D7_PIN                  PIO_PIN_PC7

/*** Macros for ADM_ENABLE_2 pin ***/
#define ADM_ENABLE_2_Set()               (PIOA_REGS->PIO_SODR = (1<<14))
#define ADM_ENABLE_2_Clear()             (PIOA_REGS->PIO_CODR = (1<<14))
#define ADM_ENABLE_2_Toggle()            (PIOA_REGS->PIO_ODSR ^= (1<<14))
#define ADM_ENABLE_2_OutputEnable()      (PIOA_REGS->PIO_OER = (1<<14))
#define ADM_ENABLE_2_InputEnable()       (PIOA_REGS->PIO_ODR = (1<<14))
#define ADM_ENABLE_2_Get()               ((PIOA_REGS->PIO_PDSR >> 14) & 0x1)
#define ADM_ENABLE_2_PIN                  PIO_PIN_PA14

/*** Macros for LCL_CAN_1_SET pin ***/
#define LCL_CAN_1_SET_Set()               (PIOD_REGS->PIO_SODR = (1<<26))
#define LCL_CAN_1_SET_Clear()             (PIOD_REGS->PIO_CODR = (1<<26))
#define LCL_CAN_1_SET_Toggle()            (PIOD_REGS->PIO_ODSR ^= (1<<26))
#define LCL_CAN_1_SET_OutputEnable()      (PIOD_REGS->PIO_OER = (1<<26))
#define LCL_CAN_1_SET_InputEnable()       (PIOD_REGS->PIO_ODR = (1<<26))
#define LCL_CAN_1_SET_Get()               ((PIOD_REGS->PIO_PDSR >> 26) & 0x1)
#define LCL_CAN_1_SET_PIN                  PIO_PIN_PD26

/*** Macros for MEM_D6 pin ***/
#define MEM_D6_Get()               ((PIOC_REGS->PIO_PDSR >> 6) & 0x1)
#define MEM_D6_PIN                  PIO_PIN_PC6

/*** Macros for LCL_CAN_1_RST pin ***/
#define LCL_CAN_1_RST_Set()               (PIOD_REGS->PIO_SODR = (1<<24))
#define LCL_CAN_1_RST_Clear()             (PIOD_REGS->PIO_CODR = (1<<24))
#define LCL_CAN_1_RST_Toggle()            (PIOD_REGS->PIO_ODSR ^= (1<<24))
#define LCL_CAN_1_RST_OutputEnable()      (PIOD_REGS->PIO_OER = (1<<24))
#define LCL_CAN_1_RST_InputEnable()       (PIOD_REGS->PIO_ODR = (1<<24))
#define LCL_CAN_1_RST_Get()               ((PIOD_REGS->PIO_PDSR >> 24) & 0x1)
#define LCL_CAN_1_RST_PIN                  PIO_PIN_PD24

/*** Macros for MEM_A20 pin ***/
#define MEM_A20_Get()               ((PIOA_REGS->PIO_PDSR >> 24) & 0x1)
#define MEM_A20_PIN                  PIO_PIN_PA24

/*** Macros for LCL_PWM_CAN_1 pin ***/
#define LCL_PWM_CAN_1_Get()               ((PIOD_REGS->PIO_PDSR >> 23) & 0x1)
#define LCL_PWM_CAN_1_PIN                  PIO_PIN_PD23

/*** Macros for MEM_D5 pin ***/
#define MEM_D5_Get()               ((PIOC_REGS->PIO_PDSR >> 5) & 0x1)
#define MEM_D5_PIN                  PIO_PIN_PC5

/*** Macros for LCL_PWM_CAN_2 pin ***/
#define LCL_PWM_CAN_2_Get()               ((PIOA_REGS->PIO_PDSR >> 25) & 0x1)
#define LCL_PWM_CAN_2_PIN                  PIO_PIN_PA25

/*** Macros for LCL_CAN_2_SET pin ***/
#define LCL_CAN_2_SET_Set()               (PIOD_REGS->PIO_SODR = (1<<22))
#define LCL_CAN_2_SET_Clear()             (PIOD_REGS->PIO_CODR = (1<<22))
#define LCL_CAN_2_SET_Toggle()            (PIOD_REGS->PIO_ODSR ^= (1<<22))
#define LCL_CAN_2_SET_OutputEnable()      (PIOD_REGS->PIO_OER = (1<<22))
#define LCL_CAN_2_SET_InputEnable()       (PIOD_REGS->PIO_ODR = (1<<22))
#define LCL_CAN_2_SET_Get()               ((PIOD_REGS->PIO_PDSR >> 22) & 0x1)
#define LCL_CAN_2_SET_PIN                  PIO_PIN_PD22

/*** Macros for LCL_CAN_2_RST pin ***/
#define LCL_CAN_2_RST_Set()               (PIOA_REGS->PIO_SODR = (1<<26))
#define LCL_CAN_2_RST_Clear()             (PIOA_REGS->PIO_CODR = (1<<26))
#define LCL_CAN_2_RST_Toggle()            (PIOA_REGS->PIO_ODSR ^= (1<<26))
#define LCL_CAN_2_RST_OutputEnable()      (PIOA_REGS->PIO_OER = (1<<26))
#define LCL_CAN_2_RST_InputEnable()       (PIOA_REGS->PIO_ODR = (1<<26))
#define LCL_CAN_2_RST_Get()               ((PIOA_REGS->PIO_PDSR >> 26) & 0x1)
#define LCL_CAN_2_RST_PIN                  PIO_PIN_PA26

/*** Macros for CAN_FAULT_1 pin ***/
#define CAN_FAULT_1_Set()               (PIOD_REGS->PIO_SODR = (1<<21))
#define CAN_FAULT_1_Clear()             (PIOD_REGS->PIO_CODR = (1<<21))
#define CAN_FAULT_1_Toggle()            (PIOD_REGS->PIO_ODSR ^= (1<<21))
#define CAN_FAULT_1_OutputEnable()      (PIOD_REGS->PIO_OER = (1<<21))
#define CAN_FAULT_1_InputEnable()       (PIOD_REGS->PIO_ODR = (1<<21))
#define CAN_FAULT_1_Get()               ((PIOD_REGS->PIO_PDSR >> 21) & 0x1)
#define CAN_FAULT_1_PIN                  PIO_PIN_PD21

/*** Macros for CAN_SILENT_1 pin ***/
#define CAN_SILENT_1_Set()               (PIOA_REGS->PIO_SODR = (1<<11))
#define CAN_SILENT_1_Clear()             (PIOA_REGS->PIO_CODR = (1<<11))
#define CAN_SILENT_1_Toggle()            (PIOA_REGS->PIO_ODSR ^= (1<<11))
#define CAN_SILENT_1_OutputEnable()      (PIOA_REGS->PIO_OER = (1<<11))
#define CAN_SILENT_1_InputEnable()       (PIOA_REGS->PIO_ODR = (1<<11))
#define CAN_SILENT_1_Get()               ((PIOA_REGS->PIO_PDSR >> 11) & 0x1)
#define CAN_SILENT_1_PIN                  PIO_PIN_PA11

/*** Macros for MEM_NAND_BUSY_2 pin ***/
#define MEM_NAND_BUSY_2_Set()               (PIOD_REGS->PIO_SODR = (1<<20))
#define MEM_NAND_BUSY_2_Clear()             (PIOD_REGS->PIO_CODR = (1<<20))
#define MEM_NAND_BUSY_2_Toggle()            (PIOD_REGS->PIO_ODSR ^= (1<<20))
#define MEM_NAND_BUSY_2_OutputEnable()      (PIOD_REGS->PIO_OER = (1<<20))
#define MEM_NAND_BUSY_2_InputEnable()       (PIOD_REGS->PIO_ODR = (1<<20))
#define MEM_NAND_BUSY_2_Get()               ((PIOD_REGS->PIO_PDSR >> 20) & 0x1)
#define MEM_NAND_BUSY_2_PIN                  PIO_PIN_PD20

/*** Macros for OBC_UART_TX pin ***/
#define OBC_UART_TX_Get()               ((PIOA_REGS->PIO_PDSR >> 10) & 0x1)
#define OBC_UART_TX_PIN                  PIO_PIN_PA10

/*** Macros for MEM_NAND_ENABLE_1 pin ***/
#define MEM_NAND_ENABLE_1_Get()               ((PIOD_REGS->PIO_PDSR >> 19) & 0x1)
#define MEM_NAND_ENABLE_1_PIN                  PIO_PIN_PD19

/*** Macros for MEM_NAND_BUSY_1 pin ***/
#define MEM_NAND_BUSY_1_Set()               (PIOA_REGS->PIO_SODR = (1<<12))
#define MEM_NAND_BUSY_1_Clear()             (PIOA_REGS->PIO_CODR = (1<<12))
#define MEM_NAND_BUSY_1_Toggle()            (PIOA_REGS->PIO_ODSR ^= (1<<12))
#define MEM_NAND_BUSY_1_OutputEnable()      (PIOA_REGS->PIO_OER = (1<<12))
#define MEM_NAND_BUSY_1_InputEnable()       (PIOA_REGS->PIO_ODR = (1<<12))
#define MEM_NAND_BUSY_1_Get()               ((PIOA_REGS->PIO_PDSR >> 12) & 0x1)
#define MEM_NAND_BUSY_1_PIN                  PIO_PIN_PA12

/*** Macros for MEM_NAND_ENABLE_2 pin ***/
#define MEM_NAND_ENABLE_2_Get()               ((PIOD_REGS->PIO_PDSR >> 18) & 0x1)
#define MEM_NAND_ENABLE_2_PIN                  PIO_PIN_PD18

/*** Macros for MEM_NAND_WR_PROT pin ***/
#define MEM_NAND_WR_PROT_Set()               (PIOA_REGS->PIO_SODR = (1<<27))
#define MEM_NAND_WR_PROT_Clear()             (PIOA_REGS->PIO_CODR = (1<<27))
#define MEM_NAND_WR_PROT_Toggle()            (PIOA_REGS->PIO_ODSR ^= (1<<27))
#define MEM_NAND_WR_PROT_OutputEnable()      (PIOA_REGS->PIO_OER = (1<<27))
#define MEM_NAND_WR_PROT_InputEnable()       (PIOA_REGS->PIO_ODR = (1<<27))
#define MEM_NAND_WR_PROT_Get()               ((PIOA_REGS->PIO_PDSR >> 27) & 0x1)
#define MEM_NAND_WR_PROT_PIN                  PIO_PIN_PA27

/*** Macros for I2C_MTQ_SCK pin ***/
#define I2C_MTQ_SCK_Get()               ((PIOD_REGS->PIO_PDSR >> 28) & 0x1)
#define I2C_MTQ_SCK_PIN                  PIO_PIN_PD28

/*** Macros for CAN_FAULT_2 pin ***/
#define CAN_FAULT_2_Set()               (PIOA_REGS->PIO_SODR = (1<<5))
#define CAN_FAULT_2_Clear()             (PIOA_REGS->PIO_CODR = (1<<5))
#define CAN_FAULT_2_Toggle()            (PIOA_REGS->PIO_ODSR ^= (1<<5))
#define CAN_FAULT_2_OutputEnable()      (PIOA_REGS->PIO_OER = (1<<5))
#define CAN_FAULT_2_InputEnable()       (PIOA_REGS->PIO_ODR = (1<<5))
#define CAN_FAULT_2_Get()               ((PIOA_REGS->PIO_PDSR >> 5) & 0x1)
#define CAN_FAULT_2_PIN                  PIO_PIN_PA5

/*** Macros for CAN_SILENT_2 pin ***/
#define CAN_SILENT_2_Set()               (PIOD_REGS->PIO_SODR = (1<<17))
#define CAN_SILENT_2_Clear()             (PIOD_REGS->PIO_CODR = (1<<17))
#define CAN_SILENT_2_Toggle()            (PIOD_REGS->PIO_ODSR ^= (1<<17))
#define CAN_SILENT_2_OutputEnable()      (PIOD_REGS->PIO_OER = (1<<17))
#define CAN_SILENT_2_InputEnable()       (PIOD_REGS->PIO_ODR = (1<<17))
#define CAN_SILENT_2_Get()               ((PIOD_REGS->PIO_PDSR >> 17) & 0x1)
#define CAN_SILENT_2_PIN                  PIO_PIN_PD17

/*** Macros for OBC_UART_RX pin ***/
#define OBC_UART_RX_Get()               ((PIOA_REGS->PIO_PDSR >> 9) & 0x1)
#define OBC_UART_RX_PIN                  PIO_PIN_PA9

/*** Macros for MEM_A10 pin ***/
#define MEM_A10_Get()               ((PIOC_REGS->PIO_PDSR >> 28) & 0x1)
#define MEM_A10_PIN                  PIO_PIN_PC28

/*** Macros for I2C_SCK_PANELS pin ***/
#define I2C_SCK_PANELS_Get()               ((PIOA_REGS->PIO_PDSR >> 4) & 0x1)
#define I2C_SCK_PANELS_PIN                  PIO_PIN_PA4

/*** Macros for MCU_SWDIO pin ***/
#define MCU_SWDIO_Get()               ((PIOB_REGS->PIO_PDSR >> 6) & 0x1)
#define MCU_SWDIO_PIN                  PIO_PIN_PB6

/*** Macros for MEM_MRAM_WR_ENABLE pin ***/
#define MEM_MRAM_WR_ENABLE_Get()               ((PIOC_REGS->PIO_PDSR >> 8) & 0x1)
#define MEM_MRAM_WR_ENABLE_PIN                  PIO_PIN_PC8

/*** Macros for MEM_NAND_OUT_ENABLE pin ***/
#define MEM_NAND_OUT_ENABLE_Get()               ((PIOC_REGS->PIO_PDSR >> 9) & 0x1)
#define MEM_NAND_OUT_ENABLE_PIN                  PIO_PIN_PC9

/*** Macros for MCU_SWCLK pin ***/
#define MCU_SWCLK_Get()               ((PIOB_REGS->PIO_PDSR >> 7) & 0x1)
#define MCU_SWCLK_PIN                  PIO_PIN_PB7

/*** Macros for MEM_NAND_WR_ENABLE pin ***/
#define MEM_NAND_WR_ENABLE_Get()               ((PIOC_REGS->PIO_PDSR >> 10) & 0x1)
#define MEM_NAND_WR_ENABLE_PIN                  PIO_PIN_PC10

/*** Macros for CAN_TX_2 pin ***/
#define CAN_TX_2_Get()               ((PIOD_REGS->PIO_PDSR >> 12) & 0x1)
#define CAN_TX_2_PIN                  PIO_PIN_PD12

/*** Macros for MEM_MRAM_OUT_ENABLE pin ***/
#define MEM_MRAM_OUT_ENABLE_Get()               ((PIOC_REGS->PIO_PDSR >> 11) & 0x1)
#define MEM_MRAM_OUT_ENABLE_PIN                  PIO_PIN_PC11

/*** Macros for MEM_MRAM_ENABLE pin ***/
#define MEM_MRAM_ENABLE_Get()               ((PIOC_REGS->PIO_PDSR >> 14) & 0x1)
#define MEM_MRAM_ENABLE_PIN                  PIO_PIN_PC14

/*** Macros for MEM_A18 pin ***/
#define MEM_A18_Get()               ((PIOA_REGS->PIO_PDSR >> 1) & 0x1)
#define MEM_A18_PIN                  PIO_PIN_PA1

/*** Macros for MEM_NAND_ADDR_ENABLE pin ***/
#define MEM_NAND_ADDR_ENABLE_Get()               ((PIOC_REGS->PIO_PDSR >> 16) & 0x1)
#define MEM_NAND_ADDR_ENABLE_PIN                  PIO_PIN_PC16

/*** Macros for MEM_A17 pin ***/
#define MEM_A17_Get()               ((PIOA_REGS->PIO_PDSR >> 0) & 0x1)
#define MEM_A17_PIN                  PIO_PIN_PA0

/*** Macros for MEM_NAND_CMD_ENABLE pin ***/
#define MEM_NAND_CMD_ENABLE_Get()               ((PIOC_REGS->PIO_PDSR >> 17) & 0x1)
#define MEM_NAND_CMD_ENABLE_PIN                  PIO_PIN_PC17

/*** Macros for I2C_SDA_SENS pin ***/
#define I2C_SDA_SENS_Get()               ((PIOB_REGS->PIO_PDSR >> 4) & 0x1)
#define I2C_SDA_SENS_PIN                  PIO_PIN_PB4

/*** Macros for I2C_SCK_SENS pin ***/
#define I2C_SCK_SENS_Get()               ((PIOB_REGS->PIO_PDSR >> 5) & 0x1)
#define I2C_SCK_SENS_PIN                  PIO_PIN_PB5

/*** Macros for ADM_DEPLOY_4 pin ***/
#define ADM_DEPLOY_4_Set()               (PIOD_REGS->PIO_SODR = (1<<9))
#define ADM_DEPLOY_4_Clear()             (PIOD_REGS->PIO_CODR = (1<<9))
#define ADM_DEPLOY_4_Toggle()            (PIOD_REGS->PIO_ODSR ^= (1<<9))
#define ADM_DEPLOY_4_OutputEnable()      (PIOD_REGS->PIO_OER = (1<<9))
#define ADM_DEPLOY_4_InputEnable()       (PIOD_REGS->PIO_ODR = (1<<9))
#define ADM_DEPLOY_4_Get()               ((PIOD_REGS->PIO_PDSR >> 9) & 0x1)
#define ADM_DEPLOY_4_PIN                  PIO_PIN_PD9

/*** Macros for MEM_A0 pin ***/
#define MEM_A0_Get()               ((PIOC_REGS->PIO_PDSR >> 18) & 0x1)
#define MEM_A0_PIN                  PIO_PIN_PC18

/*** Macros for MCU_TRACECLK pin ***/
#define MCU_TRACECLK_Get()               ((PIOD_REGS->PIO_PDSR >> 8) & 0x1)
#define MCU_TRACECLK_PIN                  PIO_PIN_PD8

/*** Macros for USR_GPIO pin ***/
#define USR_GPIO_Set()               (PIOA_REGS->PIO_SODR = (1<<30))
#define USR_GPIO_Clear()             (PIOA_REGS->PIO_CODR = (1<<30))
#define USR_GPIO_Toggle()            (PIOA_REGS->PIO_ODSR ^= (1<<30))
#define USR_GPIO_OutputEnable()      (PIOA_REGS->PIO_OER = (1<<30))
#define USR_GPIO_InputEnable()       (PIOA_REGS->PIO_ODR = (1<<30))
#define USR_GPIO_Get()               ((PIOA_REGS->PIO_PDSR >> 30) & 0x1)
#define USR_GPIO_PIN                  PIO_PIN_PA30

/*** Macros for MEM_A1 pin ***/
#define MEM_A1_Get()               ((PIOC_REGS->PIO_PDSR >> 19) & 0x1)
#define MEM_A1_PIN                  PIO_PIN_PC19

/*** Macros for USR_GPIO_PWM pin ***/
#define USR_GPIO_PWM_Get()               ((PIOA_REGS->PIO_PDSR >> 31) & 0x1)
#define USR_GPIO_PWM_PIN                  PIO_PIN_PA31

/*** Macros for MCU_TRACED_3 pin ***/
#define MCU_TRACED_3_Get()               ((PIOD_REGS->PIO_PDSR >> 7) & 0x1)
#define MCU_TRACED_3_PIN                  PIO_PIN_PD7

/*** Macros for MEM_A2 pin ***/
#define MEM_A2_Get()               ((PIOC_REGS->PIO_PDSR >> 20) & 0x1)
#define MEM_A2_PIN                  PIO_PIN_PC20

/*** Macros for MCU_TRACED_2 pin ***/
#define MCU_TRACED_2_Get()               ((PIOD_REGS->PIO_PDSR >> 6) & 0x1)
#define MCU_TRACED_2_PIN                  PIO_PIN_PD6

/*** Macros for MEM_A3 pin ***/
#define MEM_A3_Get()               ((PIOC_REGS->PIO_PDSR >> 21) & 0x1)
#define MEM_A3_PIN                  PIO_PIN_PC21

/*** Macros for MEM_A4 pin ***/
#define MEM_A4_Get()               ((PIOC_REGS->PIO_PDSR >> 22) & 0x1)
#define MEM_A4_PIN                  PIO_PIN_PC22

/*** Macros for MCU_TRACED_1 pin ***/
#define MCU_TRACED_1_Get()               ((PIOD_REGS->PIO_PDSR >> 5) & 0x1)
#define MCU_TRACED_1_PIN                  PIO_PIN_PD5

/*** Macros for MCU_TRACED_0 pin ***/
#define MCU_TRACED_0_Get()               ((PIOD_REGS->PIO_PDSR >> 4) & 0x1)
#define MCU_TRACED_0_PIN                  PIO_PIN_PD4

/*** Macros for MEM_A5 pin ***/
#define MEM_A5_Get()               ((PIOC_REGS->PIO_PDSR >> 23) & 0x1)
#define MEM_A5_PIN                  PIO_PIN_PC23

/*** Macros for MEM_A6 pin ***/
#define MEM_A6_Get()               ((PIOC_REGS->PIO_PDSR >> 24) & 0x1)
#define MEM_A6_PIN                  PIO_PIN_PC24

/*** Macros for MEM_A7 pin ***/
#define MEM_A7_Get()               ((PIOC_REGS->PIO_PDSR >> 25) & 0x1)
#define MEM_A7_PIN                  PIO_PIN_PC25

/*** Macros for GND pin ***/
#define GND_Get()               ((PIOB_REGS->PIO_PDSR >> 8) & 0x1)
#define GND_PIN                  PIO_PIN_PB8

/*** Macros for MCU_CLK_IN pin ***/
#define MCU_CLK_IN_Get()               ((PIOB_REGS->PIO_PDSR >> 9) & 0x1)
#define MCU_CLK_IN_PIN                  PIO_PIN_PB9


// *****************************************************************************
/* PIO Port

  Summary:
    Identifies the available PIO Ports.

  Description:
    This enumeration identifies the available PIO Ports.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all ports are available on all devices.  Refer to the specific
    device data sheet to determine which ports are supported.
*/


#define    PIO_PORT_A       (PIOA_BASE_ADDRESS)
#define    PIO_PORT_B       (PIOB_BASE_ADDRESS)
#define     PIO_PORT_C      (PIOC_BASE_ADDRESS)
#define     PIO_PORT_D      (PIOD_BASE_ADDRESS)
#define     PIO_PORT_E      (PIOE_BASE_ADDRESS)
typedef uint32_t PIO_PORT;

// *****************************************************************************
/* PIO Port Pins

  Summary:
    Identifies the available PIO port pins.

  Description:
    This enumeration identifies the available PIO port pins.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all pins are available on all devices.  Refer to the specific
    device data sheet to determine which pins are supported.
*/

#define    PIO_PIN_PA0     (0U)
#define    PIO_PIN_PA1     (1U)
#define    PIO_PIN_PA2     (2U)
#define    PIO_PIN_PA3     (3U)
#define    PIO_PIN_PA4     (4U)
#define    PIO_PIN_PA5     (5U)
#define    PIO_PIN_PA6     (6U)
#define    PIO_PIN_PA7     (7U)
#define    PIO_PIN_PA8     (8U)
#define    PIO_PIN_PA9     (9U)
#define    PIO_PIN_PA10     (10U)
#define    PIO_PIN_PA11     (11U)
#define    PIO_PIN_PA12     (12U)
#define    PIO_PIN_PA13     (13U)
#define    PIO_PIN_PA14     (14U)
#define    PIO_PIN_PA15     (15U)
#define    PIO_PIN_PA16     (16U)
#define    PIO_PIN_PA17     (17U)
#define    PIO_PIN_PA18     (18U)
#define    PIO_PIN_PA19     (19U)
#define    PIO_PIN_PA20     (20U)
#define    PIO_PIN_PA21     (21U)
#define    PIO_PIN_PA22     (22U)
#define    PIO_PIN_PA23     (23U)
#define    PIO_PIN_PA24     (24U)
#define    PIO_PIN_PA25     (25U)
#define    PIO_PIN_PA26     (26U)
#define    PIO_PIN_PA27     (27U)
#define    PIO_PIN_PA28     (28U)
#define    PIO_PIN_PA29     (29U)
#define    PIO_PIN_PA30     (30U)
#define    PIO_PIN_PA31     (31U)
#define    PIO_PIN_PB0     (32U)
#define    PIO_PIN_PB1     (33U)
#define    PIO_PIN_PB2     (34U)
#define    PIO_PIN_PB3     (35U)
#define    PIO_PIN_PB4     (36U)
#define    PIO_PIN_PB5     (37U)
#define    PIO_PIN_PB6     (38U)
#define    PIO_PIN_PB7     (39U)
#define    PIO_PIN_PB8     (40U)
#define    PIO_PIN_PB9     (41U)
#define    PIO_PIN_PB12     (44U)
#define    PIO_PIN_PB13     (45U)
#define    PIO_PIN_PC0     (64U)
#define    PIO_PIN_PC1     (65U)
#define    PIO_PIN_PC2     (66U)
#define    PIO_PIN_PC3     (67U)
#define    PIO_PIN_PC4     (68U)
#define    PIO_PIN_PC5     (69U)
#define    PIO_PIN_PC6     (70U)
#define    PIO_PIN_PC7     (71U)
#define    PIO_PIN_PC8     (72U)
#define    PIO_PIN_PC9     (73U)
#define    PIO_PIN_PC10     (74U)
#define    PIO_PIN_PC11     (75U)
#define    PIO_PIN_PC12     (76U)
#define    PIO_PIN_PC13     (77U)
#define    PIO_PIN_PC14     (78U)
#define    PIO_PIN_PC15     (79U)
#define    PIO_PIN_PC16     (80U)
#define    PIO_PIN_PC17     (81U)
#define    PIO_PIN_PC18     (82U)
#define    PIO_PIN_PC19     (83U)
#define    PIO_PIN_PC20     (84U)
#define    PIO_PIN_PC21     (85U)
#define    PIO_PIN_PC22     (86U)
#define    PIO_PIN_PC23     (87U)
#define    PIO_PIN_PC24     (88U)
#define    PIO_PIN_PC25     (89U)
#define    PIO_PIN_PC26     (90U)
#define    PIO_PIN_PC27     (91U)
#define    PIO_PIN_PC28     (92U)
#define    PIO_PIN_PC29     (93U)
#define    PIO_PIN_PC30     (94U)
#define    PIO_PIN_PC31     (95U)
#define    PIO_PIN_PD0     (96U)
#define    PIO_PIN_PD1     (97U)
#define    PIO_PIN_PD2     (98U)
#define    PIO_PIN_PD3     (99U)
#define    PIO_PIN_PD4     (100U)
#define    PIO_PIN_PD5     (101U)
#define    PIO_PIN_PD6     (102U)
#define    PIO_PIN_PD7     (103U)
#define    PIO_PIN_PD8     (104U)
#define    PIO_PIN_PD9     (105U)
#define    PIO_PIN_PD10     (106U)
#define    PIO_PIN_PD11     (107U)
#define    PIO_PIN_PD12     (108U)
#define    PIO_PIN_PD13     (109U)
#define    PIO_PIN_PD14     (110U)
#define    PIO_PIN_PD15     (111U)
#define    PIO_PIN_PD16     (112U)
#define    PIO_PIN_PD17     (113U)
#define    PIO_PIN_PD18     (114U)
#define    PIO_PIN_PD19     (115U)
#define    PIO_PIN_PD20     (116U)
#define    PIO_PIN_PD21     (117U)
#define    PIO_PIN_PD22     (118U)
#define    PIO_PIN_PD23     (119U)
#define    PIO_PIN_PD24     (120U)
#define    PIO_PIN_PD25     (121U)
#define    PIO_PIN_PD26     (122U)
#define    PIO_PIN_PD27     (123U)
#define    PIO_PIN_PD28     (124U)
#define    PIO_PIN_PD29     (125U)
#define    PIO_PIN_PD30     (126U)
#define    PIO_PIN_PD31     (127U)
#define    PIO_PIN_PE0     (128U)
#define    PIO_PIN_PE1     (129U)
#define    PIO_PIN_PE2     (130U)
#define    PIO_PIN_PE3     (131U)
#define    PIO_PIN_PE4     (132U)
#define    PIO_PIN_PE5     (133U)

    /* This element should not be used in any of the PIO APIs.
       It will be used by other modules or application to denote that none of the PIO Pin is used */
#define    PIO_PIN_NONE         ( -1)

typedef uint32_t PIO_PIN;


void PIO_Initialize(void);

// *****************************************************************************
// *****************************************************************************
// Section: PIO Functions which operates on multiple pins of a port
// *****************************************************************************
// *****************************************************************************

uint32_t PIO_PortRead(PIO_PORT port);

void PIO_PortWrite(PIO_PORT port, uint32_t mask, uint32_t value);

uint32_t PIO_PortLatchRead ( PIO_PORT port );

void PIO_PortSet(PIO_PORT port, uint32_t mask);

void PIO_PortClear(PIO_PORT port, uint32_t mask);

void PIO_PortToggle(PIO_PORT port, uint32_t mask);

void PIO_PortInputEnable(PIO_PORT port, uint32_t mask);

void PIO_PortOutputEnable(PIO_PORT port, uint32_t mask);

// *****************************************************************************
// *****************************************************************************
// Section: PIO Functions which operates on one pin at a time
// *****************************************************************************
// *****************************************************************************

static inline void PIO_PinWrite(PIO_PIN pin, bool value)
{
    PIO_PortWrite((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U))), (uint32_t)(0x1) << (pin & 0x1fU), (uint32_t)(value) << (pin & 0x1fU));
}

static inline bool PIO_PinRead(PIO_PIN pin)
{
    return (bool)((PIO_PortRead((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U)))) >> (pin & 0x1FU)) & 0x1U);
}

static inline bool PIO_PinLatchRead(PIO_PIN pin)
{
    return (bool)((PIO_PortLatchRead((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U)))) >> (pin & 0x1FU)) & 0x1U);
}

static inline void PIO_PinToggle(PIO_PIN pin)
{
    PIO_PortToggle((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U))), 0x1UL << (pin & 0x1FU));
}

static inline void PIO_PinSet(PIO_PIN pin)
{
    PIO_PortSet((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5))), 0x1UL << (pin & 0x1FU));
}

static inline void PIO_PinClear(PIO_PIN pin)
{
    PIO_PortClear((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U))), 0x1UL << (pin & 0x1FU));
}

static inline void PIO_PinInputEnable(PIO_PIN pin)
{
    PIO_PortInputEnable((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U))), 0x1UL << (pin & 0x1FU));
}

static inline void PIO_PinOutputEnable(PIO_PIN pin)
{
    PIO_PortOutputEnable((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U))), 0x1UL << (pin & 0x1FU));
}


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END
#endif // PLIB_PIO_H
