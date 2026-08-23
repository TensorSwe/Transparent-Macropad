README.md
# 6-Key Custom Macropad

A custom 2x3 macropad built around the Seeed Studio XIAO RP2040 microcontroller featuring a rotary encoder, an SSD1306 OLED display, and RGB backlighting.

## Hardware Features
* **MCU:** Seeed Studio XIAO RP2040
* **Keys:** 6 mechanical switches configured in a 2x3 matrix
* **Encoder:** Rotary encoder with integrated push-button
* **Display:** 0.91" SSD1306 I2C OLED (128x32)
* **Lighting:** WS2812B addressable RGB LEDs

## Repository Layout
* `/cad`: 3D STEP assembly files for enclosure design
* `/firmware`: QMK firmware source code and keymap configuration
* `/pcb`: KiCad schematic, layout, and project files
* `/production`: Manufacturing outputs (Gerbers, STL 3D models, compiled `.uf2` firmware)