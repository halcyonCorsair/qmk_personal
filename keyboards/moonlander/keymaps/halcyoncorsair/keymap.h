#pragma once

#include QMK_KEYBOARD_H
// #include "moonlander.h"

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
uint8_t oneshot_mod_state;
uint16_t last_keycode;

// bool caps_word_on;
// void caps_word_enable(void);
// void caps_word_disable(void);

enum layers {
    // BASE,  // default layer
    // SYMB,  // symbols
    // MDIA,  // media keys
    _COLEMAK_DH = 0,
    _QWERTY,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
};

// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)

// Colemak-dh
// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LGUI_T(KC_S)
#define HOME_T LSFT_T(KC_T)

// Qwerty
#define QHOME_A LCTL_T(KC_A)
#define QHOME_S LALT_T(KC_S)
#define QHOME_D LGUI_T(KC_D)
#define QHOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_N RSFT_T(KC_N)
#define HOME_E RGUI_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RCTL_T(KC_O)

// Qwerty
#define QHOME_J RSFT_T(KC_J)
#define QHOME_K RGUI_T(KC_K)
#define QHOME_L LALT_T(KC_L)
#define QHOME_SCLN RCTL_T(KC_SCLN)

// One Shot Shifts
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

enum custom_keycodes {
    REPEAT,
    CAPS_WORD,
    VRSN = ML_SAFE_RANGE,
};
