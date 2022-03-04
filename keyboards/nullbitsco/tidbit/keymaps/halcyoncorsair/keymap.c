#include QMK_KEYBOARD_H
#include "action_layer.h"

enum layer_names {
  _BASE,
  _MACROS,
  _FUNC
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
    KC_KP_7,      KC_KP_8,  KC_KP_9,    KC_KP_PLUS,
    KC_KP_4,      KC_KP_5,  KC_KP_6,    KC_KP_MINUS,
    KC_KP_1,      KC_KP_2,  KC_KP_3,    KC_PENT,
    OSL(_MACROS), KC_KP_0,  KC_KP_DOT,  KC_PENT
  ),
  [_MACROS] = LAYOUT(
                KC_NO,      KC_NO,      KC_BSPC,
    KC_MPRV,    KC_MNXT,    KC_NO,      KC_ESC,
    GITPUSH,    GITPULL,    GITSTATUS,  KC_TAB,
    GITADD,     GITCOMMIT,  GITDIFF,    KC_PENT,
    _______,    XXXXXXX,    GITDC,      TG(_FUNC)
  ),
  // Function layer (numpad)
  [_FUNC] = LAYOUT(
              KC_NO,    RGB_TOG,  KC_BSPC,
    KC_NO,    RGB_RMOD, RGB_MOD,  KC_ESC,
    KC_NO,    RGB_HUD,  RGB_HUI,  KC_TAB,
    KC_NO,    RGB_SAD,  RGB_SAI,  KC_PENT,
    _______,  RGB_VAD,  RGB_VAI,  TG(_FUNC)
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
        case _MACROS:
            oled_write_P(PSTR("Macros"), false);
            break;
        case _FUNC:
            oled_write_P(PSTR("Function"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined"), false);
    }

    oled_write_P(PSTR("\n\n"), false);
    oled_write_P(PSTR("TIDBIT"), false);

    return true;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_record_remote_kb(keycode, record);

    switch (keycode) {
        case GITPUSH:
            if (record->event.pressed) {
                SEND_STRING("git push");
            }
            break;

        case GITPULL:
            if (record->event.pressed) {
                SEND_STRING("git pull");
            }
            break;

        case GITADD:
            if (record->event.pressed) {
                SEND_STRING("git add --all");
            }
            break;

        case GITCOMMIT:
            if (record->event.pressed) {
                SEND_STRING("git commit -m ");
            }
            break;

        case GITDIFF:
            if (record->event.pressed) {
                SEND_STRING("git diff");
            }
            break;

        case GITDC:
            if (record->event.pressed) {
                SEND_STRING("git diff --cached");
            }
            break;

        case GITSTATUS:
            if (record->event.pressed) {
                SEND_STRING("git status");
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
