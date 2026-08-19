// Copyright 2022 @filterpaper
// SPDX-License-Identifier: GPL-2.0+

/* Adapted from Jane Bernhardt's Combos on Steroids (http://combos.gboards.ca/)
   This file will build QMK's combo source with preprocessor substitution
   using COMBOS_DEF file macros in the following format:
   COMB(name, keycode_shortcut, combo_sequence...)
   SUBS(name, "string to send", combo_sequence...)
   ACTN(name, function_calls(), combo_sequence...)

   COMB are simple keycode shortcuts. Use two or more combo keys to activate
   a keycode, like volume up using Y+U: COMB(KC_VOLU, KC_VOLU, KC_Y, KC_U)
   Keycodes can be used as names, they are prefixed to avoid conflict.

   SUBS are string substitution combos. It can be used to send strings like
   this W+H to send a string: SUBS(which, "which ", KC_W, KC_H)

   ACTN function call triggers. Multiple functions can be separated by semi-
   colons. Code structure without commas may work.

   Usage: Save macros in 'combos.inc' and add the following to rules.mk:
   SRC += combos.c
 */

#include QMK_KEYBOARD_H
#include "halcyoncorsair.h"

// #define COMBOS_DEF "combos.inc"

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (combo->keycode) {
    case PASTE:
    case KC_LBRC:
    case KC_RBRC:
    case KC_SLSH:
        return COMBO_TERM - 10;
        break;

    case KC_QUES:
    case KC_EXLM:
        return COMBO_TERM + 10;
        break;

    default:
        return COMBO_TERM;
        break;
    }
}
