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
- Make sure you followed the steps under the `Build` section

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

## Using Minicom to monitor the U(S)ART of ATSAM

#### Downloading Minicom

`minicom` is found in almost all package managers for Linux and macOS. For Linux you can use:

For Pop/Ubuntu/Debian derivatives
```shell
sudo apt install minicom
```

For Fedora
```shell
sudo dnf install minicom
```

For Arch
```shell
sudo pacman -S minicom
```

#### Running minicom

`minicom` is a program that displays the serial input of a port on your computer. To run it, you must specify such a port.

On Linux systems, the serial ports for connected embedded devices are `/dev/ttyACMX`, where X is a number. The first device you connect will start at 0, and each new device increases the number by 1. Note that removing a device "frees" the port, so if you have two devices connnected and you remove the first, `/dev/ttyACM0` will be disconnected while `/dev/ttyACM1` will be connected to the remaining target device. When using `UART-to-USB` devices such as an `FTDI`, the naming scheme changes and the devices will be at `/dev/ttyUSBX`, however the above scheme remains the same.

You can use the command `ls /dev/ttyACM*` to view all connected devices on the `/dev/ttyACMX` spectrum.
If a device is connected to port `/dev/ttyACM0`, you can use:
```shell
minicom -D /dev/ttyACM0
```
to get its ouput.

#### Using minicom

All actions inside the program require pressing the `Meta` key first. If you want to exit the program, you need to press `Meta`, then `x`. On Linux the `Meta` key is `CTRL+A`, while on macOS it is `Escape`. You can use `Meta`, then `z` to view a list of shortcuts.

#### Line Feeds

Our embedded devices send only a `\n` delimiter on the end of each log message. Thus, when you open the `minicom` instance, you will see that each line starts at the end of the previous line. After a couple of log messages, the new lines will start at the right edge of the screen and the messages will be invisible. To control this, you can press `Meta`, then `u` to toggle interpreting `\n` as `\r\n`. Each new message will now start at the beginning of the next line.

#### Saving output to file

In case you need to save the output of a session to a file, use the option `-C filename.txt` when opening the program. For example:
```shell
minicom -D /dev/ttyACM0 -C output.txt
```
will save the logs to the file `output.txt` in your current directory.

## Watchdog

The internal watchdog has been disabled for debugging reasons.

To re-enable remove the line

```cpp
WDT_REGS->WDT_MR = WDT_MR_WDDIS_Msk;
```

in `initialization.c`. It's on line 148 at the time of writing. You should also uncomment `WDT_Initialize()` below that.