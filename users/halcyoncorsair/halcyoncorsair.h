#pragma once
#include QMK_KEYBOARD_H
#include "keycode_aliases.h"
#ifdef CAPS_WORD_ENABLE
#    include "features/caps_word.h"
#endif
#ifdef REPEAT_KEY_ENABLE
#    include "features/repeat_key.h"
#endif
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
#if defined(KEYBOARD_moonlander)
    CAPS_WORD = ML_SAFE_RANGE,
#else
    CAPS_WORD = SAFE_RANGE,
#endif
    REPEAT,
    SELWORD,
    VRSN,
};
