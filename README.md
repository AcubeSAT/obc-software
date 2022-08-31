# OBC Software Repository

In this repository is where all of the OBC Software is housed. This is the final version that will be used on the satellite.
The software runs on the Microchip ATSAMV71Q21B Microcontroller Unit, which is a 32-bit ARM Cortex-M7 core.
We use FreeRTOS to handle the tasking of the MCU.
More information regarding OBC can be found [here](https://gitlab.com/groups/acubesat/obc/-/wikis/home).

There is the `env-tests` branch that contains the test code, to be used in the Environmental Tests campaign.
## Implemented Software

Prototypes of ECSS Services

- ST[01]
- ST[03]
- ST[17] (Not a task, since there isn't a need of periodic update. However, the MCU responds to TC[17,1] and TC[17,3]
- ST[20]

Peripherals:
- Internal MCU Temperature Sensor
- External (MCP9808) Temperature Sensor
- UART with DMA
- Parameter updating of ST[20]

## Installation

To install run the command:

    git clone https://gitlab.com/acubesat/obc/obc-software.git --recursive

After cloning, the project must be imported to MPLAB. Make sure you have version **6.00**. During the MPLAB installation, uncheck 8 and 16 bit MCUs.