# OBC Software Repository

In this repository is where all of the OBC Software is housed. This is the final version that will be used on the satellite.
The software runs on the Microchip ATSAMV71Q21B Microcontroller Unit, which is a 32-bit ARM Cortex-M7 core.
We use FreeRTOS to handle the tasking of the MCU.
More information regarding OBC can be found [here](https://gitlab.com/groups/acubesat/obc/-/wikis/home).

## Build
The `obc-software` repository can be built without any access to specialised hardware. We provide build
instructions for Linux (or WSL) command-line, and the CLion IDE.

The dependencies of this repository are managed through the [conan](https://conan.io/) package manager, with repositories
from [ConanCenter](https://conan.io/center/) and [SpaceDot's packages](https://artifactory.spacedot.gr).

For more detailed installation instructions, including how to integrate with a microcontroller, visit the
[corresponding documentation page](https://acubesat.gitlab.io/obc/ecss-services/docs/md_docs_installation.html).

### From the Command Line (CLI)

1. Install a modern C++ compiler, CMake, and Conan.  
   CMake >= 3.23 and Conan >= 2.0 are recommended.
   <details>
   <summary>Getting conan</summary>

   You can install [conan](https://conan.io/) following the instructions [from here](https://docs.conan.io/2/installation.html).
   </details>
2. Clone the repository and enter the directory:
   ```shell
   git clone git@gitlab.com:acubesat/obc/obc-software.git
   cd obc-software
   ```
3. (If you haven't already) create a conan profile for your system:
   ```shell
   conan profile detect
   ```
4. (If you haven't already) add the SpaceDot repository to conan:
   ```shell
   conan remote add spacedot https://artifactory.spacedot.gr/artifactory/api/conan/conan
   ```
5. Download all dependencies and build the project through conan:
   ```shell
   conan install . --output-folder=cmake-build-debug --build="*" -u -pr conan-arm-profile
   ```
6. Download all submodules:
   ```shell
   conan source .
   ```
7. Build the project:
   ```shell
   cmake --build cmake-build-debug
   ```

### From CLion

CLion will automatically try to set up a CMake project for you. However, without the conan packages installed, this
will quickly fail. Follow these steps to set up the conan project:

1. Follow steps 1-6 from the CLI instructions above.
2. Add the following to the CMake Options (File -> Settings -> Build, Execution, Deployment -> CMake -> CMake Options):
   ```
   -DCMAKE_TOOLCHAIN_FILE=cmake-build-debug/build/Debug/generators/conan_toolchain.cmake -DCMAKE_CXX_COMPILER="/usr/bin/arm-none-eabi-g++" -DCMAKE_C_COMPILER="/usr/bin/arm-none-eabi-gcc" and conan install 
   ```
3. If your CMake project doesn't reload automatically, reload it manually (Tools -> CMake -> Reload CMake Project).

We do not recommend using a Conan plugin for your IDE, as it may tamper with the default configuration for this repository.


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
