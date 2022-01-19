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
        case LCTL_T(KC_DLR):
            if (record->tap.count) {
                tap_code16(KC_DLR);
                return false;
            }
            break;
        case LALT_T(KC_PLUS):
            if (record->tap.count) {
                tap_code16(KC_PLUS);
                return false;
            }
            break;
        case LGUI_T(KC_LPRN):
            if (record->tap.count) {
                tap_code16(KC_LPRN);
                return false;
            }
            break;
        case LSFT_T(KC_RPRN):
            if (record->tap.count) {
                tap_code16(KC_RPRN);
                return false;
            }
            break;

        // case RSFT_T(KC_MINS):
        //     if (record->tap.count) {
        //         tap_code16(KC_MINS);
        //         return false;
        //     }
        //     break;
        // case RGUI_T(KC_EQL):
        //     if (record->tap.count) {
        //         tap_code16(KC_EQL);
        //         return false;
        //     }
        //     break;
        case LALT_T(KC_UNDS):
            if (record->tap.count) {
                tap_code16(KC_UNDS);
                return false;
            }
            break;
        case RCTL_T(KC_ASTR):
            if (record->tap.count) {
                tap_code16(KC_ASTR);
                return false;
            }
            break;
        }
    }
    return true;
}
