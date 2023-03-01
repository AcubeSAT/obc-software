/*******************************************************************************
Interface definition of RTT PLIB.

Company:
    Microchip Technology Inc.

File Name:
    plib_rtt.c

Summary:
    Interface definition of RTT Plib.

Description:
    This file defines the interface for the RTT Plib.
    It allows user to configure and generate Periodic events using a real time
    timer.
*******************************************************************************/

// DOM-IGNORE-BEGIN
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

#include "device.h"
#include "plib_rtt.h"
#include "interrupts.h"

void RTT_Initialize(void)
{
    RTT_REGS->RTT_MR = RTT_MR_RTTRST_Msk;
    RTT_REGS->RTT_MR = RTT_MR_RTPRES(0U) | RTT_MR_RTTDIS_Msk | RTT_MR_RTC1HZ_Msk;
}

void RTT_Enable(void)
{
    RTT_REGS->RTT_MR|= RTT_MR_RTTRST_Msk;
    RTT_REGS->RTT_MR&= ~(RTT_MR_RTTDIS_Msk);
}

void RTT_Disable(void)
{
    RTT_REGS->RTT_MR|= RTT_MR_RTTDIS_Msk;
}

void RTT_PrescalarUpdate(uint16_t prescale)
{
    uint32_t rtt_mr = RTT_REGS->RTT_MR;
    uint32_t flag = rtt_mr & RTT_MR_RTTINCIEN_Msk;
    rtt_mr &= ~(RTT_MR_RTPRES_Msk | RTT_MR_RTTINCIEN_Msk);
    RTT_REGS->RTT_MR = rtt_mr | prescale | RTT_MR_RTTRST_Msk;
    if (flag != 0U)
    {
        RTT_REGS->RTT_MR|=  RTT_MR_RTTINCIEN_Msk;
    }
}


uint32_t RTT_TimerValueGet(void)
{
    uint32_t rtt_val = RTT_REGS->RTT_VR;
    while (rtt_val != RTT_REGS->RTT_VR)
    {
        rtt_val = RTT_REGS->RTT_VR;
    }
    return rtt_val;
}

uint32_t RTT_FrequencyGet(void)
{
    uint32_t flag = 0;

    flag =  (RTT_REGS->RTT_MR) & (RTT_MR_RTC1HZ_Msk);

    if (flag !=0U)
    {
        return 1;
    }
    else
    {
        flag = (RTT_REGS->RTT_MR) & (RTT_MR_RTPRES_Msk);
        if (flag == 0U)
        {
            return (0);
        }
        else
        {
            return (32768U / flag);
        }
    }
}
