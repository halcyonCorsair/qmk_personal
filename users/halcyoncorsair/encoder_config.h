#pragma once
#include QMK_KEYBOARD_H
#include "halcyoncorsair.h"

void matrix_scan_user(void);
bool encoder_update_user(uint8_t index, bool clockwise);
