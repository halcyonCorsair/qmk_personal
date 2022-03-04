/* Copyright 2021 Jay Greco
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
// #include "action_layer.h"

enum layer_names {
  _BASE,
  _FUNC,
  _MACROS
};


enum custom_keycodes {
    GITPUSH = SAFE_RANGE,
    GITPULL,
    GITSTATUS,
    GITDIFF,
    GITDC,
    GITADD,
    GITCOMMIT,
};

enum td_keycodes {
    TD_ENTER_LAYER
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for KP_ENTER, twice for _FUNC layer
    [TD_ENTER_LAYER] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_KP_ENTER, 1),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Base layer (numpad)
  [_BASE] = LAYOUT(
                KC_MPLY,  KC_PSLS,    KC_KP_ASTERISK,
    KC_KP_7,    KC_KP_8,  KC_KP_9,    KC_KP_PLUS,
    KC_KP_4,    KC_KP_5,  KC_KP_6,    KC_KP_MINUS,
    KC_KP_1,    KC_KP_2,  KC_KP_3,    KC_PENT,
    TT(_FUNC),  KC_KP_0,  KC_KP_DOT,  KC_BSPC
  ),
  // Function layer (numpad)
  [_FUNC] = LAYOUT(
              KC_NO,  RGB_TOG,  KC_BSPC,
    KC_NO,    KC_NO,  RGB_MOD,  KC_ESC,
    KC_NO,    KC_NO,  RGB_HUI,  KC_TAB,
    KC_NO,    KC_NO,  RGB_SAI,  KC_PENT,
    _______,  KC_NO,  RGB_VAI,  TT(_MACROS)
  ),
  [_MACROS] = LAYOUT(
              KC_NO,  KC_NO,    KC_NO,
    KC_NO,    KC_NO,  KC_NO,    KC_NO,
    KC_NO,    KC_NO,  KC_NO,    KC_NO,
    KC_NO,    KC_NO,  KC_NO,    KC_NO,
    _______,  KC_NO,  KC_NO,    KC_NO
  ),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    oled_set_cursor(0, 0);                            // sets cursor to (row, column) using charactar spacing (5 rows on 128x32 screen, anything more will overflow back to the top)
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base"), false);
            break;
        case _FUNC:
            oled_write_P(PSTR("Function"), false);
            break;
        case _MACROS:
            oled_write_P(PSTR("Macrps"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined"), false);
    }

    oled_write_P(PSTR("\n\n"), false);
    oled_write_P(PSTR("TIDBIT"), false);

    return true;
}
#endif

void matrix_init_user(void) { matrix_init_remote_kb(); }

void matrix_scan_user(void) { matrix_scan_remote_kb(); }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_record_remote_kb(keycode, record);

    switch (keycode) {
        case GITPUSH:
            if (record->event.pressed) {
                SEND_STRING("git push\n");
            }
            break;

        case GITPULL:
            if (record->event.pressed) {
                SEND_STRING("git pull\n");
            }
            break;

        case GITADD:
            if (record->event.pressed) {
                SEND_STRING("git add --all\n");
            }
            break;

        case GITCOMMIT:
            if (record->event.pressed) {
                SEND_STRING("git commit -m ");
            }
            break;

        case GITDIFF:
            if (record->event.pressed) {
                SEND_STRING("git diff\n");
            }
            break;

        case GITDC:
            if (record->event.pressed) {
                SEND_STRING("git diff --cached\n");
            }
            break;

        case GITSTATUS:
            if (record->event.pressed) {
                SEND_STRING("git status\n");
            }
            break;

        default:
            break;
    }
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}

void led_set_kb(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_NUM_LOCK))
        set_bitc_LED(LED_DIM);
    else
        set_bitc_LED(LED_OFF);
}
