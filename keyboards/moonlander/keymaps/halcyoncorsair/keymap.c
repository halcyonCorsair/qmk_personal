/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include QMK_KEYBOARD_H
#include "version.h"
#include "halcyoncorsair.h"
#ifdef CONSOLE_ENABLED
    #include "print.h"
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT_moonlander(
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    ADJUST,       QWERTY,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    XXXXXXX,      XXXXXXX,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        KC_ESC,  HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,    KC_HYPR,      KC_MEH,   KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,  KC_QUOT,
        OS_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                            KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NAV,              SPOTLIGHT,    ONEPASS,           SYM,     REPEAT,  XXXXXXX, XXXXXXX, XXXXXXX,
                                            KC_SPC,  KC_BSPC, KC_MEH,       ADJUST,   KC_TAB,  KC_ENT
    ),

    [_QWERTY] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_E,    KC_R,    KC_T,    _______,      _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, _______, QHOME_S, QHOME_D, QHOME_F, _______, _______,      _______, KC_H,    QHOME_J, QHOME_K, QHOME_L, QHOME_SCLN,_______,
        _______, _______, _______, _______, KC_V,    KC_B,                           KC_N,    KC_M,    _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,      _______, _______, _______
    ),

    [_SYM] = LAYOUT_moonlander(
        VRSN,    _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
        KC_GRV,  KC_4,    KC_3,    KC_2,    KC_1,    KC_5,    _______,      _______, KC_9,    KC_0,    KC_6,    KC_7,    KC_8,    _______,
        KC_DEL,  HOME_DLR,HOME_PLUS,HOME_LPRN,HOME_RPRN,KC_AT,_______,      _______, KC_PIPE, HOME_MINS,HOME_EQL,HOME_UNDS,HOME_ASTR,_______,
        _______, KC_EXLM, KC_HASH, KC_LCBR, KC_RCBR, KC_TILD,                        KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC, _______,
        _______, _______, _______, _______, SH_OS,            _______,      _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,      _______, _______, _______
    ),

    [_NAV] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,  _______, _______,
        KC_F13,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,      _______, KC_PGUP, MHOME,   KC_UP,   MEND,     KC_VOLU, KC_DEL,
        KC_F14,  HOME_F5, HOME_F6, HOME_F7, HOME_F8, _______, _______,      _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_VOLD, KC_CAPS,
        KC_F15,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   PTXT,                           XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT,  KC_MUTE, KC_INS,
        _______, _______, _______, _______, _______,          _______,      _______,          _______, SELWORD, _______,  _______, _______,
                                            _______, _______, _______,      _______, KC_BSPC, _______
    ),

    // TODO: Redefine the divvy shortcuts above
    [_ADJUST] = LAYOUT_moonlander(
        WEBUSB_PAIR,_______,_______,_______,_______, _______, _______,      _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, DEBUG,
        _______, _______, _______, COLEMAK, QWERTY,  _______, _______,      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, _______,
        _______, _______, _______, _______, _______, _______,                        _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______,
        _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,      _______, KC_BRID, KC_BRIU
    ),
};

#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
#endif

/*
 * Per key tapping term settings
 */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
            return TAPPING_TERM + 40;
        case HOME_R:
        case HOME_O:
        case QHOME_S:
            return TAPPING_TERM + 30;
        default:
            return TAPPING_TERM;
    }
};
