/*******************************************************************************
  PWM Peripheral Library Interface Header File

  Company
    Microchip Technology Inc.

  File Name
    plib_pwm1.h

  Summary
    PWM1 peripheral library interface.

  Description
    This file defines the interface to the PWM peripheral library.  This
    library provides access to and control of the associated peripheral
    instance.

******************************************************************************/

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
// DOM-IGNORE-END

#ifndef PLIB_PWM1_H    // Guards against multiple inclusion
#define PLIB_PWM1_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

/*  This section lists the other files that are included in this file.
*/

#include "plib_pwm_common.h"
#include "device.h"

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
/*  The following data type definitions are used by the functions in this
    interface and should be considered part it.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
/* The following functions make up the methods (set of possible operations) of
   this interface.
*/

__STATIC_INLINE void PWM1_ChannelDutySet(PWM_CHANNEL_NUM channel, uint16_t duty)
{
  PWM1_REGS->PWM_CH_NUM[channel].PWM_CDTYUPD= duty;
}

void PWM1_Initialize (void);

void PWM1_ChannelsStart (PWM_CHANNEL_MASK channelMask);

void PWM1_ChannelsStop (PWM_CHANNEL_MASK channelMask);

void PWM1_ChannelPeriodSet (PWM_CHANNEL_NUM channel, uint16_t period);

uint16_t PWM1_ChannelPeriodGet (PWM_CHANNEL_NUM channel);

void PWM1_ChannelDeadTimeSet (PWM_CHANNEL_NUM channel, uint16_t deadtime_high, uint16_t deadtime_low);

void PWM1_CompareValueSet (PWM_COMPARE cmp_unit, uint16_t cmp_value);

void PWM1_ChannelCounterEventEnable (PWM_CHANNEL_MASK channelMask);

void PWM1_ChannelCounterEventDisable (PWM_CHANNEL_MASK  channelMask);

void PWM1_SyncUpdateEnable (void);

void PWM1_FaultStatusClear(PWM_FAULT_ID fault_id);

void PWM1_ChannelOverrideEnable(PWM_CHANNEL_NUM channel);

void PWM1_ChannelOverrideDisable(PWM_CHANNEL_NUM channel);

bool PWM1_ChannelCounterEventStatusGet (PWM_CHANNEL_NUM channel);

#ifdef __cplusplus // Provide C++ Compatibility
}
#endif

#endif //PLIB_PWM1_H

/* End of File */