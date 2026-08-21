// Copyright 2026 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Define Keymaps (6 Matrix Switches: 2 rows x 3 cols)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_2x3(
        KC_MPRV, KC_MNXT, KC_MPLY,   // Row 0 (GP27): Switches 1, 2, 3
        KC_MUTE, KC_VOLU, KC_VOLD    // Row 1 (GP26): Switches 4, 5, 6
    )
};

// Initialize Standalone Encoder Button on Pin 8 (GP1)
void matrix_init_user(void) {
    gpio_set_pin_input_high(GP1);
}

// Poll Standalone Encoder Button on GP1 with software debounce
void matrix_scan_user(void) {
    static bool last_btn_state = true;
    static uint16_t btn_timer = 0;
    
    bool curr_btn_state = gpio_read_pin(GP1);

    if (last_btn_state != curr_btn_state && timer_elapsed(btn_timer) > 30) {
        btn_timer = timer_read();
        if (last_btn_state && !curr_btn_state) {
            tap_code(KC_MUTE); // Triggers Mute on encoder press
        }
        last_btn_state = curr_btn_state;
    }
}

// Rotary Encoder Turning (Pin 10 -> GP3 / Pin 9 -> GP2)
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

// OLED Display Output (Pin 5 -> GP6 / Pin 6 -> GP7)
#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_P(PSTR("Macropad Active\n"), false);
    oled_write_P(PSTR("Layer: 0\n"), false);
    return false;
}
#endif