/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

// TODO: See drashna's stuff to see if there are oled goodies I can steal

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  |  \  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Esc/` |A/Ctrl| R/Alt| S/GUI| T/SFT|   G  |                              |   M  | N/SFT| E/GUI| I/Alt|O/Ctrl|  '  "  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  |Spotlt|CapsLk|  | 1pass|Adjust|   K  |   H  | ,  < | . >  | /  ? |  -  _  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| Meh  | Nav  | Space| Bksp |  | Tab  | Enter| Sym  |Repeat| Play |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK_DH] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                            KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_PIPE,
        KC_ESC,  HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,                                            KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,  KC_QUOT,
        OS_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    SPOTLIGHT,NUM,        ONEPASS, ADJUST,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                                   ADJUST,  KC_MEH,  NAV,     KC_SPC,  KC_BSPC,     KC_TAB,  KC_ENT,  SYM,     REPEAT,  KC_MPLY
    ),

/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |A/Ctrl| S/Alt| D/GUI| F/SFT|   G  |                              |   H  | J/SFT| K/GUI| L/Alt|;:/Ctrl|       |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | ,  < | . >  | /  ? |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, _______, QHOME_S, QHOME_D, QHOME_F, _______,                                         KC_H,    QHOME_J, QHOME_K, QHOME_L, QHOME_SCLN,_______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______,     _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),
#ifdef ENABLE_SYMBOL_LAYER_ORIGINAL
/*
 * Layer template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   !  |   @  |   ;  |   :  |   _  |                              |   =  |   &  |   `  |   ~  |   +  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   \  |   |  |   }  |   (  |   [  |                              |   *  |   $  |   %  |   ^  |   -  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   ~  |   `  |   {  |   )  |   ]  |      |      |  |      |      |   &  |   !  |   @  |   #  |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | Swap | Num  |      | Del  |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
        _______, KC_EXLM, KC_AT,   KC_SCLN, KC_COLN, KC_UNDS,                                         KC_EQL,  KC_AMPR, KC_GRAVE,KC_TILD, KC_PLUS, _______,
        _______, HOME_BSLS,HOME_PIPE,HOME_LCBR,HOME_LPRN,KC_LBRC,                                     KC_ASTR, HOME_DLR,HOME_PERC,HOME_CIRC,HOME_MINS,_______,
        _______, KC_TILD, KC_GRAVE,KC_RCBR, KC_RPRN, KC_RBRC, _______, _______,     _______, _______, KC_AMPR, KC_EXLM, KC_AT,   KC_HASH, _______, _______,
                                   _______, SH_OS,   NUM,     _______,  KC_DEL,     _______, _______, _______, _______, _______
    ),
    // NOTE: swap hands is currently not enabled due to memory requirements
#elif defined(ENABLE_SYMBOL_LAYER_TBAART)
/*
 * Raise Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                              |      |  _   |  €   |      |      |  \     |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |                              |   +  |  -   |  /   |  *   |  %   |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |      |  |      |      |   &  |  =   |  ,   |  .   |  / ? | - _    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                     _______, KC_UNDS, _______,_______,_______,KC_BSLS,
      _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                                      KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, KC_QUOT,
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______, _______, _______, KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
#else
// #ifdef ENABLE_SYMBOL_LAYER_WINTERNEBS
/*
 * winter nebs: NUM/symb, swapped numbers
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |   1  |   2  |   3  |   4  |   5  |                              |   9  |   0  |   6  |   7  |   8  |  |  \  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   DEL  |   $  |   +  |   (  |   )  |   @  |                              |   |  |   -  |   =  |   _  |   *  |  '  "  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   !  |   #  |   {  |   }  |   ~  |      |      |  |      |      |   &  |   [  |   ]  |   %  |   ^  |  -  _  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
	[_SYM] = LAYOUT(
	KC_GRV,  KC_4,    KC_3,    KC_2,    KC_1,    KC_5,                                            KC_9,    KC_0,    KC_6,    KC_7,    KC_8,    _______,
	KC_DEL,  KC_DLR,  KC_PLUS, KC_LPRN, KC_RPRN, KC_AT,                                           KC_PIPE, KC_MINS, KC_EQL,  KC_UNDS, KC_ASTR, _______,
	_______, KC_EXLM, KC_HASH, KC_LCBR, KC_RCBR, KC_TILD, _______, _______,     _______, _______, KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC, _______,
							   _______, _______, _______, _______, _______,     _______, KC_BSPC, _______, _______, _______
	),
#endif
/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Swap  |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Ctrl |  Alt | GUI  | Shift|      |                              | PgDn |  ←   |   ↓  |   →  | VolDn|Capslock|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |  Cut | Copy | Paste|P-Text|      |Scroll|  |      |Selwrd|  XXX |M Prev|M Play|M Next| Mute | Insert |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |  Num |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                         KC_PGUP, MHOME,   KC_UP,   MEND,    KC_VOLU, KC_DEL,
        _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,                                         KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_CAPS,  // KC_PSCR
        _______, UNDO,    CUT,     COPY,    PASTE,   PTXT,    _______, KC_SLCK,     _______, SELWORD, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_INS,
                                   _______, _______, _______, _______, _______,     _______, _______, NUM,     _______, _______
    ),
#ifdef ENABLE_SYMBOL_LAYER_ORIGINAL
    [_NUM] = LAYOUT(
        KC_F13,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,                                         KC_EQL,  KC_7,    KC_8,    KC_9,    KC_PLUS, KC_BSPC,
        KC_F14,  HOME_F5, HOME_F6, HOME_F7, HOME_F8, KC_DOT,                                          KC_ASTR, HOME_4,  HOME_5,  HOME_6,  HOME_MINS,_______,
        KC_F15,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______,     _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_SLSH, KC_DOT,
                                   _______, _______, _______, _______, KC_BSPC,     _______, _______, _______, KC_DOT, _______
    ),
#endif
#ifdef ENABLE_WINMGMT_LAYER
    [_WINMGMT] = LAYOUT(
        _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______,                                         _______, DIVVY_U, DIVVY_I, DIVVY_O, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                                         DIVVY_H, DIVVY_J, DIVVY_K, DIVVY_L, DIVVY_SCLN,DIVVY_PANEL,
        _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, DIVVY_M, DIVVY_COMMA,DIVVY_DOT,_______, _______,
                                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),
#endif

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      | RESET  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  | DEBUG  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |Bright|Bright|      |      |      |
 *                        |      |      |      |      |      |  |  Up  | Down |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
        _______, _______, _______, QWERTY,  _______, _______,                                         _______, _______, _______, _______, _______, RESET,
        _______, _______, _______, COLEMAK, _______, _______,                                         RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, DEBUG,
        _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______,
                                   _______, _______, _______, _______, _______,     KC_BRID, KC_BRIU, _______, _______, _______
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
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
        case HOME_R:
        case HOME_O:
        case QHOME_S:
            return TAPPING_TERM + 30;
        // case SYM_ENT:
        //     // Very low tapping term to make sure I don't hit Enter accidentally.
        //     return TAPPING_TERM - 85;
        default:
            return TAPPING_TERM;
    }
};
