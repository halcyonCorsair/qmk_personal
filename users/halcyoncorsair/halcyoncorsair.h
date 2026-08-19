#pragma once
#include QMK_KEYBOARD_H
#include "keycode_aliases.h"
#ifdef ENCODER_ENABLE
#   include "encoder_config.h"
#endif
#ifdef OLED_ENABLE
#   include "oled_config.h"
#endif
#include "process_records.h"

enum layers {
    _COLEMAK_DH = 0,
    _SYM,
    _NAV,
    _ADJUST,
    _LAYER_SAFE_RANGE,
};

enum qwerty_layers {
    _Q_COLEMAK_DH = 0,
    _Q_QWERTY,
    _Q_SYM,
    _Q_NAV,
    _Q_ADJUST,
    _Q_LAYER_SAFE_RANGE,
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};
