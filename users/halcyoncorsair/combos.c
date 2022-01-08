#include QMK_KEYBOARD_H
#include "halcyoncorsair.h"
// #include "action_tapping.h" // necessary for action_tapping_process
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

enum combo_events {
    HOME_CAPS_WORD,
    INNER_CAPS_LOCK,
    CMB_UNDO,
    CMB_CUT,
    CMB_COPY,
    CMB_PASTE,
    CMB_SELECT_LINE,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM caps_word_combo[]    = {HOME_T,  HOME_N,     COMBO_END};
const uint16_t PROGMEM caps_lock_combo[]    = {KC_G,    KC_M,       COMBO_END};
const uint16_t PROGMEM undo_combo[]         = {KC_Z,    KC_X,       COMBO_END};
const uint16_t PROGMEM cut_combo[]          = {KC_X,    KC_D,       COMBO_END};
const uint16_t PROGMEM copy_combo[]         = {KC_X,    KC_C,       COMBO_END};
const uint16_t PROGMEM paste_combo[]        = {KC_C,    KC_D,       COMBO_END};
const uint16_t PROGMEM select_line_combo[]  = {KC_X,    KC_C,       KC_D,    COMBO_END};

combo_t key_combos[] = {
    [HOME_CAPS_WORD]    = COMBO(caps_word_combo,    CAPS_WORD),
    [INNER_CAPS_LOCK]   = COMBO(caps_lock_combo,    KC_CAPS),
    [CMB_UNDO]          = COMBO(undo_combo,         UNDO),
    [CMB_CUT]           = COMBO(cut_combo,          CUT),
    [CMB_COPY]          = COMBO(copy_combo,         COPY),
    [CMB_PASTE]         = COMBO(paste_combo,        PASTE),
    [CMB_SELECT_LINE]   = COMBO(select_line_combo,  LSFT(SELWORD)),
};
