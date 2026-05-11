# Starter code for CC3501 labs

This is intended as a starting point for CC3501 students to build their own code for labs. The repository contains:

1. Preconfigured `CMakeLists.txt` that supports building embedded code for the target as well as native Windows code for a test harness.
2. Very minimal example for how to interact with WS2812 addressable LEDs (plus minimal example of native mock for testing purposes).

# Code organisation 

| Path                       | Description                                             |
| -------------------------- | ------------------------------------------------------- |
| `src`                      | Main program source code                                |
| `src/main.cpp`             | Main program entry point                                |
| `src/drivers`              | Hardware drivers                                        |
| `src/drivers/WS2812/`      | Low level driver for WS2812 using PIO                   |
| `src/drivers/logging/`     | Example basic log driver                                |
| `tests`                    | Code to support the native build for testing            |
| `tests/mocks/`             | Mock implementations of Pico SDK to enable native build |


# Setup instructions

## Forking the Repository
You should work from your own fork of this repository. A fork is your own Github copy of the project. You can push your changes to your fork without needing write access to the original class repository.

1. Open the [class repository](https://github.com/bronsonp/CC3501-RP2040-labs) on GitHub.
2. Click **Fork**.
3. Choose your own GitHub account.
4. Create the fork.
5. Open your fork and copy the HTTPS clone URL using the green **Code** button.

'''text
https://github.com/YOUR-USERNAME/CC3501-RP2040-labs.git
'''

6. Clone your fork to your computer:
'''cmd
git clone https://github.com/YOUR-USERNAME/CC3501-RP2040-labs.git
cd CC3501-RP2040-labs
code .
'''

## Visual Studio Code extensions
Download and install Visual Studio Code, then install the recommended extensions when prompted after opening the repository.

The required/recommended extensions are:

1. **Raspberry Pi Pico**
2. **C/C++**
3. **CMake Tools**
4. **Cortex-Debug**
5. **Serial Monitor**
6. **PIOASM support**, if prompted/recommended

If VS Code asks to install recommended extensions, choose **Install**.

## Raspberry Pi Pico Extension Setup
The Raspberry Pi Pico extension manages the Pico SDK, ARM toolchain, CMake, Ninja, OpenOCD, and related tools.

If the bottom bar shows **Finish Setup**, click it and allow the Pico extension to finish installing the required tools.

This repository is already configured as a Pico project. If VS Code asks whether to import or convert this folder as a Raspberry Pi Pico project, do **not** import it again. Choose **No**, **Cancel**, **Not now**, or close the prompt.

# Building for the embedded hardware

Use this mode when you want to build and debug on the RP2040 development board.

## Select the Pico kit

Select the RP2040 firmware kit:

1. Press 'Ctrl + Shift + P'.
2. Search for **CMake: Select a Kit**.
3. Choose:
'''text
CC3501 Pico SDK Kit
'''
Do not choose Visual Studio, MinGW, GCC , or 'Unspecified' when building for the development board.

## Build the Pico firmware

After selecting **CC3501 Pico SDK Kit**, build the project using one of the following:
1. Click the bottom-bar **Build** button, or
2. Press 'Ctrl + Shift + B', or
3. Use **Terminal → Run Build Task → Build Pico Project**.

A successful embedded build should produce a build folder containing:
'''text
build/labs.elf
build/labs.uf2
'''

The '.elf' file is used for debugging. The '.uf2' file can be copied to the board in BOOTSEL mode if needed.

## Debugging on the development board

Connect the debug probe and development board.

Minimum SWD connections:

'''text
Debug probe GND → Dev board GND
Debug probe SWDIO → Dev board SWDIO
Debug probe SWCLK → Dev board SWCLK
'''
Or through the 1/2 pitch 10-pin header with ribbon cable. 

The board does not need to be in BOOTSEL mode for SWD debugging - however the Debug probe must be flashed with the debug probe '.uf2' file (see LearnJCU Reference Materials).

To debug:
1. Build the project first.
2. Open the **Run and Debug** panel.
3. Select:

'''text
Pico Debug (CMSIS-DAP)
'''

4. Press the green debug/play button.

# Building a native Windows app

Use this mode when you want to run the local/mock test harness on your computer without the RP2040 development board connected.

The native build uses mock implementations in 'tests/mocks/' so that some hardware-like code can be tested locally. This can be useful for testing algorithms, state machines, GPIO-style logic and sensor/LED behaviour using mock inputs/outputs.

## Select the local compiler kit

To switch to local testing:
1. Press 'Ctrl + Shift + P'.
2. Search for **CMake: Select a Kit**. **Note: When switching kits or debug profiles - you may need to select these twice to get them to actually change, based on past user experience.**
3. Select a local compiler kit, such as:

'''text 
Visual Studio Build Tools 2022 x86
'''

Do not use **CC3501 Pico SDK Kit** for local testing.

## Configure and build locally

When using the local compiler kit, build using the CMake Tools workflow:

1. Press 'Ctrl + Shift + P'.
2. Run **CMake: Configure**.
3. Run **CMake: Build**, or click the bottom-bar **Build** button.

do not use **Build Pico Project** for local testing. That task is for RP2040 firmware builds.

A successful local build should produce a Windows executable, such as:

'''text
build/labs.exe
'''

## Debug the local test harness

Open **Run and Debug** and select:

'''text 
(Windows) Launch Local Test Harness
'''

4. Then press the green debug/play button.

If VS Code reports that it cannot find 'labs.exe', run:

'''cmd
dir build\*.exe /s
'''

and make sure the executable exists. You may need to run **CMake: Configure** and **CMake: Build** again after switching kits.

# Switching between embedded and local builds

The project supports two build modes:

| Mode | CMake kit | Build method | Output |
| --- | --- | --- | --- |
| RP2040 development board | `CC3501 Pico SDK Kit` | Bottom-bar Build, `Ctrl + Shift + B`, or **Build Pico Project** | `build/labs.elf`, `build/labs.uf2` |
| Local/mock testing | Visual Studio Build Tools or approved local compiler | **CMake: Configure**, then **CMake: Build** | `build/labs.exe` |

When switching between the Pico kit and the local compiler kit, CMake may need to reconfigure the project. If the build behaves strangely after switching modes, delete the build folder and build again:

```cmd
rmdir /s /q build
```

Then select the correct kit and rebuild.

# Git workflow

After making changes, check the status:

```cmd
git status
```

Stage your changes:

```cmd
git add .
```

Commit your changes:

```cmd
git commit -m "Describe the change you made"
```

Push to your fork:

```cmd
git push
```

You should push to your own fork, not the original class repository.

# Common pitfalls

## Do not import the project again

This repository is already configured. Do not run **Raspberry Pi Pico: Import Project** on this folder.

## Wrong kit selected

If you are building for the RP2040 board, use:

```text
CC3501 Pico SDK Kit
```

If you are running local tests, use a local compiler kit such as:

```text
Visual Studio Build Tools 2022
```

## Pico build cannot find `labs.elf`

Build the Pico firmware first. Then check:

```cmd
dir build\*.elf
```

You should see:

```text
build\labs.elf
```

## Debug probe detected but target will not connect

If OpenOCD reports that CMSIS-DAP is ready but cannot connect to the RP2040, check:

1. The development board is powered.
2. GND is connected.
3. SWDIO and SWCLK are not swapped.
4. The debug connector is not reversed.
5. The board is not in BOOTSEL mode.

## Local build cannot find `labs.exe`

Make sure you selected a local compiler kit, then run:

```text
CMake: Configure
CMake: Build
```

Then check:

```cmd
dir build\*.exe /s
```

## Do not commit generated files

Do not commit:

```text
build/
.vscode/settings.json
.vscode/.cortex-debug*.json
```

These files are generated locally and are not part of your submitted source code.

# Credits

* The `src/drivers/WS2812/WS2812.pio` file is an example for the RP2040 provided by the Raspberry Pi foundation, used under the terms of the BSD license.
