#pragma once
#include QMK_KEYBOARD_H
#include "keycode_aliases.h"
#ifdef SELECT_WORD_ENABLE
#   include "features/select_word.h"
#endif
#ifdef ENCODER_ENABLE
#   include "encoder_config.h"
#endif
#ifdef OLED_ENABLE
#   include "oled_config.h"
#endif
#include "process_records.h"

enum layers {
    _COLEMAK_DH = 0,
    _QWERTY,
    _SYM,
    _NAV,
    _NUM,
    // _WINMGMT,
    _ADJUST,
    _LAYER_SAFE_RANGE
};

enum custom_keycodes {
    SELWORD = SAFE_RANGE,
    VRSN,
};
