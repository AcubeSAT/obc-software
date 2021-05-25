# Boilerplate code for ATSAMV71Q21B, with gcc, Clion and FreeRTOS integration

## Things to be considered
- Some generated log files need to be deleted
- Brutally disabled Systick_Handler in plib_systick.c should be disabled by a setting in MPLAB X
- Currently only the PA23 (LED) pin is enabled
- There is an issue regarding merging existing MPLAB settings with new ones, it cannot reproduce the macros needed
