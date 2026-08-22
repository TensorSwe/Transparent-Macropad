README.md
# Macropad Firmware (QMK)

This folder contains the QMK firmware source code configured for the XIAO RP2040 macropad.

## How to Compile
1. Copy the `QMK` folder contents to your QMK installation: `qmk_firmware/keyboards/keypad/`
2. Compile the firmware using the command:
   ```bash
   qmk compile -kb keypad -km test1