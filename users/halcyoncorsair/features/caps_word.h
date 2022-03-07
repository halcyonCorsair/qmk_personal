#pragma once
#include QMK_KEYBOARD_H
#include "halcyoncorsair.h"

bool is_caps_word_enabled(void);
void caps_word_enable(void);
void caps_word_disable(void);
// void toggle_caps_word(void);

void process_caps_word(uint16_t keycode, const keyrecord_t *record);
