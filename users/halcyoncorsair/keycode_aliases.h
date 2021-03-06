#pragma once
#include QMK_KEYBOARD_H

// Layer switch aliases
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)
#define SYM      TT(_SYM)
#define NAV      TT(_NAV)
#define ADJUST   MO(_ADJUST)
#define NUM_SPC  LT(_NUM, KC_SPC)

// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF

// Colemak-dh
// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LGUI_T(KC_S)
#define HOME_T LSFT_T(KC_T)

// Qwerty
#define QHOME_A LCTL_T(KC_A)
#define QHOME_S LALT_T(KC_S)
#define QHOME_D LGUI_T(KC_D)
#define QHOME_F LSFT_T(KC_F)

// Symbols
#define HOME_DLR  LCTL_T(KC_DLR)
#define HOME_PLUS LALT_T(KC_PLUS)
#define HOME_LPRN LGUI_T(KC_LPRN)
#define HOME_RPRN LSFT_T(KC_RPRN)

// Num
#define HOME_F5 LCTL_T(KC_F5)
#define HOME_F6 LALT_T(KC_F6)
#define HOME_F7 LGUI_T(KC_F7)
#define HOME_F8 LSFT_T(KC_F8)


// Right-hand home row mods
#define HOME_N RSFT_T(KC_N)
#define HOME_E RGUI_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RCTL_T(KC_O)

// Qwerty
#define QHOME_J    RSFT_T(KC_J)
#define QHOME_K    RGUI_T(KC_K)
#define QHOME_L    LALT_T(KC_L)
#define QHOME_SCLN RCTL_T(KC_SCLN)

// Symbols
#define HOME_MINS RSFT_T(KC_MINS)
#define HOME_EQL  RGUI_T(KC_EQL)
#define HOME_UNDS LALT_T(KC_UNDS)
#define HOME_ASTR RCTL_T(KC_ASTR)

// Num
#define HOME_4 RSFT_T(KC_4)
#define HOME_5 RGUI_T(KC_5)
#define HOME_6 LALT_T(KC_6)
// #define HOME_ RCTL_T(KC_) - MINS


// One Shot Shifts
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

// Movement
#define MHOME RGUI(KC_LEFT)
#define MEND RGUI(KC_RIGHT)

// OS shotcuts
#define DESKTL LCTL(KC_LEFT)
#define DESKTR LCTL(KC_RIGHT)
#define NXTAPP LGUI(KC_TAB)
#define PRVAPP LSG(KC_TAB)

#define UNDO LGUI(KC_Z)
#define REDO LSG(KC_Z)

#define CUT   LGUI(KC_X)
#define COPY  LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define PTXT  LSG(KC_V)

// App shortcuts
#define SPOTLIGHT   LGUI(KC_SPC)
#define ONEPASS     LAG(KC_BSLS)

#define DIVVY_PANEL MEH(KC_D)
#define DIVVY_U     MEH(KC_U)
#define DIVVY_I     MEH(KC_I)
#define DIVVY_O     MEH(KC_O)
#define DIVVY_H     MEH(KC_H)
#define DIVVY_J     MEH(KC_J)
#define DIVVY_K     MEH(KC_K)
#define DIVVY_L     MEH(KC_L)
#define DIVVY_SCLN  MEH(KC_SCLN)
#define DIVVY_M     MEH(KC_M)
#define DIVVY_COMMA MEH(KC_COMMA)
#define DIVVY_DOT   MEH(KC_DOT)
