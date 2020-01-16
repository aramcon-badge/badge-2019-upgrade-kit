# AramCon Badge 2019 Upgrade Kit

This upgrade kits add extra input buttons and a [Shitty Add-On V1.69bis](https://hackaday.com/2019/03/20/introducing-the-shitty-add-on-v1-69bis-standard/) connector to AramCon Badge 2019.

## Compiling and Flashing the Firmware

Install the following software:

1. [STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html)
2. [Arduino IDE](https://www.arduino.cc/en/main/software)
3. [Arduino STM32 Core](https://github.com/stm32duino/Arduino_Core_STM32)

Note: if you only want to flash the firmware from a HEX file, you only need the STM32CubeProgrammer software.

Open the [upgrade-kit-firmware](upgrade-kit-firmware/) in the Arduino IDE, and then go to "Tools" → "Board" and 
choose `Generic STM32F0 series`. Then under "Board part number" choose `STM32F030F4 Demo board (internal RC oscillator)`.
Finally, click on "Upload" (Ctrl+U) to compile and flash the firmware to the board through STM32CubeProgrammer.
