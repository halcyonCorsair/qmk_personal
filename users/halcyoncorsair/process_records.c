#include QMK_KEYBOARD_H
#include "process_records.h"
#include "version.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("pru => k: 0x%04X, row: %u, col: %u, layer: %u, event: %b, mods: 0x%02X, osm: 0x%02X, tc: %u\n",
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
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;

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
