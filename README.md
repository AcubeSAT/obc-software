# OBC Software Repository

In this repository is where all of the OBC Software is housed. This is the final version that will be used on the satellite.
The software runs on the Microchip ATSAMV71Q21B Microcontroller Unit, which is a 32-bit ARM Cortex-M7 core.
We use FreeRTOS to handle the tasking of the MCU.
More information regarding OBC can be found [here](https://gitlab.com/groups/acubesat/obc/-/wikis/home).

## Build

After cloning the repo, run the command `git submodule update --init --recursive` to clone the submodules.
If cloning `COBS` throws a permission/access error, setup an SSH key in GitHub to fix it.

If you're using CLion, you need to add in CMake options (File -> Settings -> Build, Execution, Deployment -> CMake ->
CMake Options) this `-DCMAKE_TOOLCHAIN_FILE=cmake-build-debug/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release`.

If you just cmake from cli, just add the same flags in your command.


### Conan

To build, you need to follow these steps:
- First run `conan profile detect --force`: Generates default profile detecting GCC. However, for this project, you need to set up
    the correct architecture. Find where `conan` sets up profiles (probably `~/.conan2/profiles`), run `cp default arm` 
    in that folder, and edit the `arm` file. You need to change the `arch` entry to `arch=armv7`.
- Then run `conan install . --output-folder=cmake-build-debug --build=missing -pr arm`. If you're using CLion and don't see `cmake-build-debug`, you have to `Reload CMake project` to have it generated. 
After you've run `conan install...` you can `Reload CMake project` and build as per usual.

<details>
<summary>Getting conan</summary>

You can install [conan](https://conan.io/) following the instructions from
[here](https://docs.conan.io/2/installation.html).:
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
