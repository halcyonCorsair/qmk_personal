/* Copyright 2021 Elliot Pahl <elliot.pahl@gmail.com>
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

// TODO: Shift, KC_GRV, KC_DEL, KC_ESC, KC_INS, KC_CAPS?, ADJUST

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  \  |  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Esc/` |A/Ctrl| R/Alt| S/GUI| T/SFT|   G  |                              |   M  | N/SFT| E/GUI| I/Alt|O/Ctrl|  '  "  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  |Spotlt|CapsLk|  | 1pass|Adjust|   K  |   H  | ,  < | . >  | /  ? |  -  _  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| Meh  | Nav  | Space| Bksp |  | Tab  | Enter| Sym  |Repeat| Play |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK_DH] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                          KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,                          KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                          KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                   NAV,     KC_SPC,  KC_BSPC,     KC_TAB,  KC_ENT,  SYM
    ),


    [_QWERTY] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                          KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,                          KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                          KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                   NAV,     KC_SPC,  KC_BSPC,     KC_TAB,  KC_ENT,  SYM
    ),
/*
 * winter nebs: NUM/symb, swapped numbers
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |   4  |   3  |   2  |   1  |   5  |                              |   9  |   0  |   6  |   7  |   8  |  |  \  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   DEL  |   $  |   +  |   (  |   )  |   @  |                              |   |  |   -  |   =  |   _  |   *  |  '  "  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   !  |   #  |   {  |   }  |   ~  |      |      |  |      |      |   &  |   [  |   ]  |   %  |   ^  |  -  _  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT_split_3x5_3(
        KC_4,    KC_3,    KC_2,    KC_1,    KC_5,                          KC_9,    KC_0,    KC_6,    KC_7,    KC_8,
        HOME_DLR,HOME_PLUS,HOME_LPRN,HOME_RPRN,KC_AT,                      KC_PIPE, HOME_MINS,HOME_EQL,HOME_UNDS,HOME_ASTR,
        KC_EXLM, KC_SCLN, KC_LCBR, KC_RCBR, KC_TILD,                       KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC,
                                   _______, _______, _______,     _______, _______, _______
    ),
/*
 * Nav Layer: Media, navigation
 *
 * ,------------------------------------------.                              ,-------------------------------------------.
 * |  F13  |  F9  |  F10 |  F11 |  F12 |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |-------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  F14  |F5/CTL|F6/ALT|F7/GUI|F8/SFT|      |                              | PgDn |  ←   |   ↓  |   →  | VolDn|Capslock|
 * |-------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  F15  |  F1  |  F2  |  F3  |  F4  |P-Text|      |      |  |      |Selwrd|  XXX |M Prev|M Play|M Next| Mute | Insert |
 * `---------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                       |      |      |      |      |      |  |      |      |  Num |      |      |
 *                       |      |      |      |      |      |  |      |      |      |      |      |
 *                       `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT_split_3x5_3(
        KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,                       KC_PGUP, MHOME,   KC_UP,   MEND,    KC_VOLU,
        HOME_F5, HOME_F6, HOME_F7, HOME_F8, _______,                       KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   PTXT,                          KC_ESC,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,
                                   _______, _______, _______,     _______, KC_BSPC, ADJUST
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      | RESET  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Colmak|QWERTY|      |                              | TOG  | SAI  | HUI  | VAI  | MOD  | DEBUG  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |Bright|Bright|      |      |      |
 *                        |      |      |      |      |      |  |  Up  | Down |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT_split_3x5_3(
        QK_BOOT, _______, _______, _______, _______,                       _______, _______, EEP_RST, DEBUG,   QK_BOOT,
        DEBUG,   _______, COLEMAK, _______, _______,                       RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,
        EEP_RST, _______, _______, _______, _______,                       _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,
                                   _______, _______, _______,     KC_BRID, KC_BRIU, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
//                                  _______, _______, _______,    _______, _______, _______
//     ),
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
        case HOME_I:
        case HOME_R:
        case HOME_O:
        case QHOME_S:
            return TAPPING_TERM + 30;
        case HOME_T:
        case HOME_N:
            return TAPPING_TERM - 20;
        // case SYM_ENT:
        //     // Very low tapping term to make sure I don't hit Enter accidentally.
        //     return TAPPING_TERM - 85;
        default:
            return TAPPING_TERM;
    }
};
