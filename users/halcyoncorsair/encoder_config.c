#include "encoder_config.h"

#ifdef ENCODER_ENABLE
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 700) {
            #ifdef MAC_HOTKEYS
                register_code(KC_LGUI);
            #else
                register_code(KC_LALT);
            #endif
            unregister_code(KC_LGUI);
            is_alt_tab_active = false;
        }
    }
}

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
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        }
    } else if (index == 1) {    // Right - Linear encoder
        if (layer_state_is(_NAV)) {
            if (clockwise) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    #ifdef MAC_HOTKEYS
                        register_code(KC_LGUI);
                    #else
                        register_code(KC_LALT);
                    #endif
                }
                alt_tab_timer = timer_read();
                tap_code16(KC_TAB);
            } else {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LGUI);
                    #ifdef MAC_HOTKEYS
                        register_code(KC_LGUI);
                    #else
                        register_code(KC_LALT);
                    #endif
                }
                alt_tab_timer = timer_read();
                tap_code16(S(KC_TAB));
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
