#include QMK_KEYBOARD_H
#include "halcyoncorsair.h"

LEADER_EXTERNS();

// Runs on every matrix scan. Be careful what goes here - you can really impact the
// responsiveness of your keyboard if you add too much in this function.
void matrix_scan_user(void) {
// #ifdef USER_SUPER_ALT_TAB_ENABLE
    matrix_scan_encoder_alt_tab();
// #endif

    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_C) { // Inline Code
            SEND_STRING("`` " SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        }
        SEQ_TWO_KEYS(KC_G, KC_S) {
            SEND_STRING("git s");
        }
        SEQ_TWO_KEYS(KC_G, KC_D) {
            SEND_STRING("git d");
        }
        SEQ_THREE_KEYS(KC_G, KC_C, KC_O) {
            SEND_STRING("git co");
        }
        SEQ_THREE_KEYS(KC_G, KC_C, KC_M) {
            SEND_STRING("git c");
        }
        SEQ_THREE_KEYS(KC_G, KC_A, KC_P) {
            SEND_STRING("git ap");
        }
    }
}
