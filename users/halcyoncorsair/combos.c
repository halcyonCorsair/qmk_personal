#include QMK_KEYBOARD_H
#include "halcyoncorsair.h"
// #include "action_tapping.h" // necessary for action_tapping_process
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

enum combo_events {
    HOME_CAPS_WORD,
    INNER_CAPS_LOCK,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM caps_word_combo[]   = {HOME_T,  HOME_N, COMBO_END};
const uint16_t PROGMEM caps_lock_combo[]   = {KC_G,    KC_M,   COMBO_END};

combo_t key_combos[] = {
    [HOME_CAPS_WORD]  = COMBO(caps_word_combo, CAPS_WORD),
    [INNER_CAPS_LOCK] = COMBO(caps_lock_combo, KC_CAPS),
};
