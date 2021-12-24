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

#include "keymap.h"

enum layers {
    _COLEMAK_DH = 0,
    _QWERTY,
    _SYM,
    _NAV,
    _NUM,
    _ADJUST,
};

// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define NUM      MO(_NUM)
#define DIVVY    MO(_WINMGMT)
#define ADJUST   MO(_ADJUST)

// enum custom_keycodes {
//     VRSN = ML_SAFE_RANGE,
// };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT_moonlander(
        KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    ADJUST,           QWERTY,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_NO,            KC_NO,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,          KC_MEH,   KC_M,    KC_N,    KC_E,    KC_I,    KC_OC,   KC_QUOT,
        OSM(MOD_LSFT), KC_Z, KC_X, KC_C,    KC_D,    KC_V,                                KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_RSFT),
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   NAV,       LGUI(KC_SPC),            RGUI(LALT(KC_BSLS), SYM,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                            KC_SPC,  KC_BSPC, DIVVY,            ADJUST,   KC_TAB,  KC_ENT
    ),

    [_QWERTY] = LAYOUT_moonlander(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,         KC_RGHT,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  KC_E,     KC_R,     KC_T,     _______,         _______,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     _______,
        _______,  _______,  KC_S,     KC_D,     KC_F,     _______,  _______,         _______,  KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  _______,
        _______,  _______,  _______,  _______,  KC_V,     KC_B,                                KC_N,     KC_M,     _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,         _______,            _______,  _______,  _______,  _______,  _______,
                                                _______,  _______,  _______,         _______,  _______,  _______,
    ),

    [_SYM] = LAYOUT_moonlander(
        VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,           _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
        _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,           _______, KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                             KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
        EEP_RST, _______, _______, _______, _______,          RGB_VAI,           RGB_TOG,          _______, KC_DOT,  KC_0,    KC_EQL,  _______,
                                            RGB_HUD, RGB_VAD, RGB_HUI,           TOGGLE_LAYER_COLOR,_______, _______
    ),

    [_WINMGMT] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______,                  _______,                _______,                _______,                _______,                _______,
        _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,           _______, _______,                  LALT(RCTL(RSFT(KC_U))), LALT(RCTL(RSFT(KC_I))), LALT(RCTL(RSFT(KC_O))), _______,                _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, LALT(RCTL(RSFT(KC_H))),   LALT(RCTL(RSFT(KC_J))), LALT(RCTL(RSFT(KC_J))), LALT(RCTL(RSFT(KC_K))), LALT(RCTL(RSFT(KC_L))), _______,
        _______, _______, _______, _______, _______, _______,                             _______,                  LALT(RCTL(RSFT(KC_M))), LALT(RCTL(RSFT(KC_,))), LALT(RCTL(RSFT(KC_.))), _______,                _______,
        _______, _______, _______, _______, _______,          _______,           _______,                           _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    // TODO: Redefine the divvy shortcuts above
    [_ADJUST] = LAYOUT_moonlander(
        WEBUSB_PAIR,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, _______,   QWERTY,  _______, _______, _______,           _______, _______, RGB_VAI, RGB_VAD, _______, _______, _______,
        _______, _______, _______,   COLEMAK, _______, _______, _______,           _______, _______, KC_BRIU, KC_BRID, _______, _______, _______,
        _______, _______, _______,   _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______,   _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                              _______, _______, _______,           _______, _______, _______
    ),

    // Original layout from default keymap
    // [BASE] = LAYOUT_moonlander(
    //     KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,           KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    //     KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TG(SYMB),         TG(SYMB), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    //     KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), LGUI_T(KC_QUOT),
    //     KC_LSFT, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
    // LT(SYMB,KC_GRV),WEBUSB_PAIR,A(KC_LSFT),KC_LEFT, KC_RGHT,  LALT_T(KC_APP),    RCTL_T(KC_ESC),   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(SYMB),
    //                                         KC_SPC,  KC_BSPC, KC_LGUI,           KC_LALT,  KC_TAB,  KC_ENT
    // ),

    // [SYMB] = LAYOUT_moonlander(
    //     VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    //     _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,           _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
    //     _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,           _______, KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
    //     _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                             KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
    //     EEP_RST, _______, _______, _______, _______,          RGB_VAI,           RGB_TOG,          _______, KC_DOT,  KC_0,    KC_EQL,  _______,
    //                                         RGB_HUD, RGB_VAD, RGB_HUI, TOGGLE_LAYER_COLOR,_______, _______
    // ),

    // [MDIA] = LAYOUT_moonlander(
    //     LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, RESET,
    //     _______, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
    //     _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
    //     _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
    //                                         _______, _______, _______,           _______, _______, _______
    // ),
};


// CAPS_WORD: A "smart" Caps Lock key that only capitalizes the next identifier you type
// and then toggles off Caps Lock automatically when you're done.
void caps_word_enable(void) {
    caps_word_on = true;
    if (!(host_keyboard_led_state().caps_lock)) {
        tap_code(KC_CAPS);
    }
}

void caps_word_disable(void) {
    caps_word_on = false;
    unregister_mods(MOD_MASK_SHIFT);
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF

void process_caps_word(uint16_t keycode, const keyrecord_t *record) {
    // Update caps word state
    if (caps_word_on) {
        switch (keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                // Earlier return if this has not been considered tapped yet
                if (record->tap.count == 0) { return; }
                // Get the base tapping keycode of a mod- or layer-tap key
                keycode = GET_TAP_KC(keycode);
                break;
            default:
                break;
        }

        switch (keycode) {
            // Keycodes to shift
            case KC_A ... KC_Z:
                if (record->event.pressed) {
                    if (get_oneshot_mods() & MOD_MASK_SHIFT) {
                        caps_word_disable();
                        add_oneshot_mods(MOD_MASK_SHIFT);
                    } else {
                        caps_word_enable();
                    }
                }
            // Keycodes that enable caps word but shouldn't get shifted
            case KC_MINS:
            case KC_BSPC:
            case KC_UNDS:
            case KC_PIPE:
            case REPEAT:
            case CAPS_WORD:
            case OS_LSFT:
            case OS_RSFT:
            case KC_LPRN:
            case KC_RPRN:
                // If chording mods, disable caps word
                if (record->event.pressed && (get_mods() != MOD_LSFT) && (get_mods() != 0)) {
                    caps_word_disable();
                }
                break;
            default:
                // Any other keycode should automatically disable caps
                if (record->event.pressed && !(get_oneshot_mods() & MOD_MASK_SHIFT)) {
                    caps_word_disable();
                }
                break;
        }
    }
}

uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;
void process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
    if (keycode != REPEAT) {
        // Early return when holding down a pure layer key
        // to retain modifiers
        switch (keycode) {
            case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
            case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
            case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
            case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
            case QK_TO ... QK_TO_MAX:
            case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
                return;
        }
        last_modifier = oneshot_mod_state > mod_state ? oneshot_mod_state : mod_state;
        switch (keycode) {
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                if (record->event.pressed) {
                    last_keycode = GET_TAP_KC(keycode);
                }
                break;
            default:
                if (record->event.pressed) {
                    last_keycode = keycode;
                }
                break;
        }
    } else { // keycode == REPEAT
        if (record->event.pressed) {
            register_mods(last_modifier);
            register_code16(last_keycode);
        } else {
            unregister_code16(last_keycode);
            unregister_mods(last_modifier);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;

        case CAPS_WORD:
            // Toggle `caps_word_on`
            if (record->event.pressed) {
                if (caps_word_on) {
                    caps_word_disable();
                    return false;
                } else {
                    caps_word_enable();
                    return false;
                }
            }
            break;
        }
    }
    return true;
}

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
        case QHOME_A:
            return TAPPING_TERM + 30;
        // case SYM_ENT:
        //     // Very low tapping term to make sure I don't hit Enter accidentally.
        //     return TAPPING_TERM - 85;
        default:
            return TAPPING_TERM;
    }
};
