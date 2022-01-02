#pragma once
#include QMK_KEYBOARD_H

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
uint8_t oneshot_mod_state;
uint16_t last_keycode;

bool caps_word_on;
void caps_word_enable(void);
void caps_word_disable(void);
