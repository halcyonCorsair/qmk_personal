#pragma once

#include QMK_KEYBOARD_H
// #include "moonlander.h"

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
uint8_t oneshot_mod_state;
uint16_t last_keycode;

bool caps_word_on;
void caps_word_enable(void);
void caps_word_disable(void);

enum layers {
    _COLEMAK_DH = 0,
    _QWERTY,
    _SYM,
    _NAV,
    _NUM,
    _WINMGMT,
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

// Symbols
#define HOME_BSLS LCTL_T(KC_BSLS)
#define HOME_PIPE LALT_T(KC_PIPE)
#define HOME_LCBR LGUI_T(KC_LCBR)
#define HOME_LPRN LSFT_T(KC_LPRN)

// Num
#define HOME_F5 LCTL_T(KC_F5)
#define HOME_F6 LALT_T(KC_F6)
#define HOME_F7 LGUI_T(KC_F7)
#define HOME_F8 LSFT_T(KC_F8)


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

// Symbols
#define HOME_DLR RSFT_T(KC_DLR)
#define HOME_PERC RGUI_T(KC_PERC)
#define HOME_CIRC LALT_T(KC_CIRC)
#define HOME_MINS RCTL_T(KC_MINS)

// Num
#define HOME_4 RSFT_T(KC_4)
#define HOME_5 RGUI_T(KC_5)
#define HOME_6 LALT_T(KC_6)
// #define HOME_ RCTL_T(KC_) - MINS

// One Shot Shifts
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

enum custom_keycodes {
    REPEAT,
    CAPS_WORD,
    VRSN = ML_SAFE_RANGE,
};
