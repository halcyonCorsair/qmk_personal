#include QMK_KEYBOARD_H
#include "process_records.h"
#include "version.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("pru: 0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
         keycode,
         record->event.key.row,
         record->event.key.col,
         get_highest_layer(layer_state),
         record->event.pressed,
         get_mods(),
         get_oneshot_mods(),
         record->tap.count
    );
#endif
#ifdef CAPS_WORD_ENABLE
    process_caps_word(keycode, record);
#endif
#ifdef REPEAT_KEY_ENABLE
    process_repeat_key(keycode, record);
#endif
#ifdef SELECT_WORD_ENABLE
    if (!process_select_word(keycode, record, SELWORD)) { return false; }
#endif
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;

#ifdef CAPS_WORD_ENABLE
        case CAPS_WORD:
#   ifdef CONSOLE_ENABLE
            uprintf("pru: Activate CAPS_WORD\n");
#   endif
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
#endif

        // symbol mod taps
        case LALT_T(KC_PIPE):
            if (record->tap.count) {
                tap_code16(KC_PIPE); // Send KC_PIPE on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LGUI_T(KC_LCBR):
            if (record->tap.count) {
                tap_code16(KC_LCBR); // Send KC_LCBR on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LSFT_T(KC_LPRN):
            if (record->tap.count) {
                tap_code16(KC_LPRN); // Send KC_LPRN on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RSFT_T(KC_DLR):
            if (record->tap.count) {
                // Update to use IS_LAYER_ON && IS_LAYER_OFF?
                if (layer_state_is(_NUM)) { // layer order is immportant here
                    tap_code16(KC_4); // Send KC_DLR on tap
                    return false;
                }
                // if layer is _SYM
                tap_code16(KC_DLR);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RGUI_T(KC_PERC):
            if (record->tap.count) {
                if (layer_state_is(_NUM)) { // layer order is immportant here
                    tap_code16(KC_5); // Send KC_PERC on tap
                    return false;
                }
                tap_code16(KC_PERC);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LALT_T(KC_CIRC):
            if (record->tap.count) {
                if (layer_state_is(_NUM)) { // layer order is immportant here
                    tap_code16(KC_6); // Send KC_CIRC on tap
                    return false;
                }
                tap_code16(KC_CIRC);
                return false;        // Return false to ignore further processing of key
            }
            break;
        }
    }
    return true;
}
