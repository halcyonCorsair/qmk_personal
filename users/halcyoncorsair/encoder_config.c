#include "encoder_config.h"

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {           // Left - Industrial encoder
        if (layer_state_is(_SYM)) {
            // Next/Previous workspace
            if (clockwise) {
                tap_code16(DESKTR);
            } else {
                tap_code16(DESKTL);
            }
        } else {
            // Page up/Page down
            if (clockwise) {
                tap_code(KC_PGUP);
            } else {
                tap_code(KC_PGDN);
            }
        }
    } else if (index == 1) {    // Right - Linear encoder
        if (layer_state_is(_NAV)) {
            if (clockwise) {
                tap_code16(LALT(KC_RIGHT));
            } else {
                tap_code16(LALT(KC_LEFT));
            }
        } else {
            // Volume control
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }
    return false;
}
#endif
