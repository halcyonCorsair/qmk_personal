#pragma once
#include QMK_KEYBOARD_H
#include "halcyoncorsair.h"

void matrix_scan_encoder_alt_tab(void);
bool encoder_update_user(uint8_t index, bool clockwise);
