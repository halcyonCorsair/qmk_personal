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
#include "keymap.h"
#ifdef CONSOLE_ENABLED
    #include "print.h"
#endif

enum combo_events {
    HOME_CAPS_WORD,
    INNER_CAPS_WORD,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM home_caps_word_combo[]   = {HOME_T,  HOME_N, COMBO_END};
const uint16_t PROGMEM inner_caps_word_combo[]  = {KC_G,    KC_M,   COMBO_END};

combo_t key_combos[] = {
    [HOME_CAPS_WORD]  = COMBO(home_caps_word_combo,  CAPS_WORD),
    [INNER_CAPS_WORD] = COMBO(inner_caps_word_combo, CAPS_WORD), // make this capslock instead?
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT_moonlander(
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    ADJUST,       QWERTY,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    XXXXXXX,      XXXXXXX,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_ESC,  HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,    KC_HYPR,      KC_MEH,   KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,  KC_QUOT,
        OS_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                            KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, OS_RSFT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NAV,              SPOTLIGHT,    ONEPASS,           SYM,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            KC_SPC,  KC_BSPC, DIVVY,        ADJUST,   KC_TAB,  KC_ENT
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
        _______, KC_EXLM, KC_AT,   KC_SCLN, KC_COLN, KC_UNDS, _______,      _______, KC_EQL,  KC_AMPR, KC_GRAVE,KC_TILD, KC_PLUS, _______,
        _______, HOME_BSLS,HOME_PIPE,HOME_LCBR,HOME_LPRN,KC_LBRC,_______,   _______, KC_ASTR, HOME_DLR,HOME_PERC,HOME_CIRC,HOME_MINS,_______,
        _______, KC_TILD, KC_GRAVE,KC_RCBR, KC_RPRN, KC_RBRC,                        KC_AMPR, KC_EXLM, KC_AT,   KC_HASH, _______, _______,
        _______,   _______, _______, _______, NUM,           _______,       _______,          _______, _______, _______, _______, _______,
                                            _______, KC_DEL, SH_OS,         _______, _______, _______
    ),

    [_NAV] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______,      _______, KC_PGUP, MHOME,   KC_UP,   MEND,     KC_VOLU, KC_DEL,
        _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______, _______,      _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_VOLD, KC_CAPS,
        _______, _______, CUT,     COPY,    PASTE,   PTXT,                           XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT,  KC_MUTE, KC_INS,
        _______, _______, _______, _______, _______,          _______,      _______,          NUM,     SELWORD, _______,  _______, _______,
                                            _______, _______, _______,      _______, _______, _______
    ),

    [_NUM] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,      _______, KC_EQL,  KC_7,    KC_8,    KC_9,    KC_PLUS, KC_BSPC,
        _______, HOME_F5, HOME_F6, HOME_F7, HOME_F8, _______, _______,      _______, KC_0,    HOME_4,  HOME_5,  HOME_6,  HOME_MINS,_______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,                        KC_ASTR, KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
        _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, KC_DOT,  _______, _______,
                                            _______, _______, _______,      _______, _______, _______
    ),

    [_WINMGMT] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,      _______, _______, DIVVY_U, DIVVY_I, DIVVY_O, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,      _______, DIVVY_H, DIVVY_J, DIVVY_K, DIVVY_L, DIVVY_SCLN,DIVVY_PANEL,
        _______, _______, _______, _______, _______, _______,                        _______, DIVVY_M, DIVVY_COMMA,DIVVY_DOT,_______,_______,
        _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,      _______, _______, _______
    ),

    // TODO: Redefine the divvy shortcuts above
    [_ADJUST] = LAYOUT_moonlander(
        WEBUSB_PAIR,_______,_______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, _______,   QWERTY,  _______, _______, _______,    _______, _______, _______, _______, RGB_TOG, _______, DEBUG,
        _______, _______, _______,   COLEMAK, _______, _______, _______,    _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, _______,
        _______, _______, _______,   _______, _______, _______,                      _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______,
        _______, _______, _______,   _______, _______,          _______,    _______,          _______, _______, _______, _______, _______,
                                              _______, _______, _______,    _______, KC_BRID, KC_BRIU
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
