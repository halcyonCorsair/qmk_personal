#include QMK_KEYBOARD_H

#define _BASE     0
#define _FUNC     1

enum custom_keycodes {
    GITPUSH = SAFE_RANGE,
    GITPULL,
    GITSTATUS,
    GITDIFF,
    GITDC,
    GITADD,
    GITCOMMIT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        BASE LAYER
    /---------------------------------------`
    |Play/Pause|        |         |         |
    |---------|---------|---------|---------|
    |    7    |    8    |    9    |  Bkspc  |
    |---------|---------|---------|---------|
    |    4    |    5    |    6    |   Esc   |
    |---------|---------|---------|---------|
    |    1    |    2    |    3    |   Tab   |
    |---------|---------|---------|---------|
    |  TT(1)  |    0    |    .    |  Enter  |
    \---------------------------------------'
    */
    [_BASE] = LAYOUT_oled_top(
        KC_MPLY,
        KC_P7,      KC_P8,      KC_P9,      KC_BSPC,
        KC_P4,      KC_P5,      KC_P6,      KC_ESC,
        KC_P1,      KC_P2,      KC_P3,      KC_TAB,
        TT(_FUNC),  KC_P0,      KC_PDOT,    KC_KP_ENTER
    ),

    /*
        FUNCTION LAYER
    /---------------------------------------`
    |Play/Pause|        |         |         |
    |---------|---------|---------|---------|
    |  Prev   |  Next   |    /    |    *    |
    |---------|---------|---------|---------|
    | g:push  | g:pull  |g:status |    +    |
    |---------|---------|---------|---------|
    | g:add   |g:commit | g:diff  |    -    |
    |---------|---------|---------|---------|
    |         |         |g:diffc  |    =    |
    \---------------------------------------'
    */
    [_FUNC] = LAYOUT_oled_top(
        _______,
        KC_MPRV,    KC_MNXT,    KC_KP_SLASH,KC_KP_ASTERISK,
        GITPUSH,    GITPULL,    GITSTATUS,  KC_KP_PLUS,
        GITADD,     GITCOMMIT,  GITDIFF,    KC_KP_MINUS,
        _______,    XXXXXXX,    GITDC,      KC_PEQL
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (layer_state_is(_FUNC)) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
        return false;
    }

    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return false;
}

//MACRO ------------------------------------------------------- https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
    }

    return true;
};

#ifdef OLED_ENABLE
// Used to draw on to the oled screen
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
        default:
            oled_write_P(PSTR("Undefined"), false);
    }

    oled_write_P(PSTR("\n\n"), false);
    oled_write_P(PSTR("Every day is a\n"), false);
    oled_write_P(PSTR("fresh opportunity"), false);

    return true;
}
#endif
