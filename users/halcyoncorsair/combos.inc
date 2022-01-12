// Copyright 2022 @filterpaper
// SPDX-License-Identifier: GPL-2.0+

//  Layout key reference
//	KC_Q    KC_W    KC_F    KC_P    KC_B        KC_J    KC_L    KC_U    KC_Y    KC_SCLN
//	HM_A    HM_R    HM_S    HM_T    KC_G        KC_M    HM_N    HM_E    HM_I    HM_O
//	KC_Z    KC_X    KC_C    KC_D    KC_V        KC_K    KC_H    KC_COMM KC_DOT  KC_SLSH
//	  TODO - FIX this line:  LT(SYM,KC_TAB)  RCTL_T(KC_ENT)       RSFT_T(KC_SPC)  LT(NUM,KC_BSPC)

// Vermoot has minus on his base layer
// Symbols
COMB(UY_COLON,              KC_COLN,             KC_U, KC_Y)
// COMB(UYD_SMILE,             KC_NO,               KC_U, KCs_Y, KC_D)
COMB(PLOVER_QUESTION,       KC_QUES,             HOME_R, HOME_S, KC_U, KC_Y)
COMB(PLOVER_EXCL,           KC_EXLM,             HOME_E, HOME_I, KC_W, KC_F)
// COMB(PLOVER_RET,            KC_ENT,              HOME_N, HOME_T)     // Taken by caps word
COMB(TV_ENT ,               KC_ENT,              HOME_T, KC_V)
COMB(HE_SLSH,               KC_SLSH,             KC_H, HOME_E)
COMB(E_DOT_BSLS,            KC_BSLS,             HOME_E, KC_DOT)
COMB(NH_PIPE,               KC_PIPE,             HOME_N, KC_H)
COMB(H_DOT_COMMA_UNDS,      KC_UNDS,             KC_H, KC_DOT, KC_COMM)
COMB(LESS,                  KC_LT,               HOME_N, KC_U)
COMB(GREATER,               KC_GT,               HOME_I, KC_U)
COMB(EQULS,                 KC_EQL,              KC_H, KC_DOT)
COMB(PLUS,                  KC_PLUS,             KC_H, KC_COMM)
COMB(MINUS,                  KC_MINS,             KC_DOT, KC_COMM)
COMB(BACKTICK,              KC_GRV,              KC_C, HOME_T)
COMB(TILDE,                 KC_TILD,             KC_C, HOME_R)
SUBS(ARROW,                 "->",                KC_M, KC_L)
SUBS(FAT_ARROW,             "=>",                HOME_N, KC_SCLN)
COMB(WF_AT,                 KC_AT,               KC_W, KC_F)
COMB(FP_POUND,              KC_HASH,             KC_F, KC_P)
COMB(FT_AMP,                KC_AMPR,             KC_F, HOME_T)
COMB(LU_ASTR,               KC_ASTR,             KC_L, KC_U)
// COMB(SECTION_SIGN,          A(KC_6),             HOME_R, KC_F)
COMB(DOLLAR,                KC_DLR,              HOME_R, KC_D)
COMB(PERCENT,               KC_PERC,             HOME_I, KC_H)
COMB(CIRC,                  KC_CIRC,             HOME_S, KC_D)

COMB(OPEN_PAREN,            KC_LPRN,             KC_W, HOME_T)
COMB(CLOSE_PAREN,           KC_RPRN,             KC_Y, HOME_N)
COMB(OPEN_BRC,              KC_LBRC,             KC_W, KC_P)
COMB(CLOSE_BRC,             KC_RBRC,             KC_Y, KC_L)
COMB(OPEN_CBRC,             KC_LCBR,             KC_W, HOME_S)
COMB(CLOSE_CBRC,            KC_RCBR,             KC_Y, HOME_E)

// Numpad
COMB(NUM0,                  KC_P0,               KC_SPC, KC_M)
COMB(NUM1,                  KC_P1,               KC_SPC, KC_H)
COMB(NUM2,                  KC_P2,               KC_SPC, KC_COMM)
COMB(NUM3,                  KC_P3,               KC_SPC, KC_DOT)
COMB(NUM4,                  KC_P4,               KC_SPC, HOME_N)
COMB(NUM5,                  KC_P5,               KC_SPC, HOME_E)
COMB(NUM6,                  KC_P6,               KC_SPC, HOME_I)
COMB(NUM7,                  KC_P7,               KC_SPC, KC_L)
COMB(NUM8,                  KC_P8,               KC_SPC, KC_U)
COMB(NUM9,                  KC_P9,               KC_SPC, KC_Y)

// Functions
COMB(TN_CAPS_WORD,          CAPS_WORD,           HOME_T, HOME_N)
COMB(GM_CAPS_LOCK,          KC_CAPS,             KC_G, KC_M)
COMB(ZX_UNDO,               UNDO,                KC_Z, KC_X)
COMB(XD_CUT,                CUT,                 KC_X, KC_D)
COMB(XC_COPY,               COPY,                KC_X, KC_C)
COMB(CD_PASTE,              PASTE,               KC_C, KC_D)


// //  Layout key reference
// //	KC_Q    KC_W    KC_E    KC_R    KC_T        KC_Y    KC_U    KC_I    KC_O    KC_P
// //	HM_A    HM_S    HM_D    HM_F    KC_G        KC_H    HM_J    HM_K    HM_L    HM_QUOT
// //	KC_Z    KC_X    KC_C    KC_V    KC_B        KC_N    M_TH    COMM_TH DOT_TH  SLSH_TH
// //	       LT(SYM,KC_TAB)  RCTL_T(KC_ENT)       RSFT_T(KC_SPC)  LT(NUM,KC_BSPC)

// #ifdef SWAP_HANDS_ENABLE
// 	COMB(swap_l,  SH_TG,  KC_X, KC_V)
// 	COMB(swap_r,  SH_TG,  M_TH, DOT_TH)
// #endif

// COMB(KC_VOLU,  KC_VOLU,  KC_P, HM_QUOT)
// COMB(KC_VOLD,  KC_VOLD,  HM_QUOT, SLSH_TH)
// // Layer toggles
// COMB(func,     TG(FNC),  LT(SYM,KC_TAB), KC_B)
// COMB(numb,     TG(NUM),  LT(NUM,KC_BSPC), KC_N)
// // Vimac shortcuts
// COMB(vimacf,   HYPR(KC_F),  HM_D, HM_F)
// COMB(vimacj,   HYPR(KC_J),  HM_J, HM_K)
// // Macros
// SUBS(dir_up,   "../",   DOT_TH, SLSH_TH)
// SUBS(vi_quit,  ":q!",   KC_Q, KC_W)
// SUBS(vi_save,  ":wq!",  KC_Z, KC_X)
