#pragma once
#include QMK_KEYBOARD_H
#include "halcyoncorsair.h"

// // Initialize variable holding the binary
// // representation of active modifiers.
// uint8_t mod_state;
// uint8_t oneshot_mod_state;
// uint16_t last_keycode;
// uint16_t last_keycode = XXXXXXX;
// uint8_t last_modifier = 0;
void process_repeat_key(uint16_t keycode, const keyrecord_t *record);
