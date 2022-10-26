# OBC Software Repository

In this repository is where all of the OBC Software is housed. This is the final version that will be used on the satellite.
The software runs on the Microchip ATSAMV71Q21B Microcontroller Unit, which is a 32-bit ARM Cortex-M7 core.
We use FreeRTOS to handle the tasking of the MCU.
More information regarding OBC can be found [here](https://gitlab.com/groups/acubesat/obc/-/wikis/home).

There is the `env-tests` branch that contains the test code, to be used in the Environmental Tests campaign.

## conan

To build, you first have to cd `cmake-build-debug` (or to the respective CMake build dir) and run `conan install .. 
--build=missing`. If you're using CLion and don't see `cmake-build-debug`, you have to `Reload CMake project` to have it generated. 
After you've run `conan install ..` you can `Reload CMake project` and build as per usual.

<details>
<summary>Getting conan</summary>

You can install [conan](https://conan.io/) following the instructions from
[here](https://docs.conan.io/en/latest/installation.html). Just to be safe, you can follow the standard procedure from 
[here](https://docs.conan.io/en/latest/getting_started.html):

- `conan profile new default --detect`: Generates default profile detecting GCC and sets old ABI. This step and the 
  one below is needed to [manage the GCC >=5 ABI](https://docs.conan.io/en/latest/howtos/manage_gcc_abi.html#manage-gcc-abi)
- `conan profile update settings.compiler.libcxx=libstdc++11 default`: Sets `libcxx` to C++11 ABI

</details>

## Implemented Software

Prototypes of ECSS Services

- ST[01]
- ST[03]
- ST[17] (Not a task, since there isn't a need of periodic update. However, the MCU responds to TC[17,1] and TC[17,3])
- ST[20]

Peripherals:

- Internal MCU Temperature Sensor
- External (MCP9808) Temperature Sensor
- UART with DMA
- Parameter updating of ST[20]

## Note

The internal watchdog has been disabled for debugging reasons.

To re-enable remove the line

```cpp
WDT_REGS->WDT_MR = WDT_MR_WDDIS_Msk;
```

in `initialization.c`. It's on line 148 at the time of writing. You should also uncomment `WDT_Initialize()` below that.
