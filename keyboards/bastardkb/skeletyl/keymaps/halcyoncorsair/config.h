/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define TAPPING_TERM_PER_KEY // See bottom of keymap.c

// // Lets you roll mod-tap keys
// #define IGNORE_MOD_TAP_INTERRUPT
// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// // Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define TAPPING_FORCE_HOLD

// This prevents accidental repeats of the tap-hold keys when typing quickly.
#define TAPPING_FORCE_HOLD_PER_KEY

// Disable PERMISSIVE_HOLD
#undef PERMISSIVE_HOLD

// Other settings //
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define TAPPING_TOGGLE 2

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4     // 18

// Set tapping term
#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif  // TAPPING_TERM
#define TAPPING_TERM 200

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
// #ifdef DEBOUNCE
// #    undef DEBOUNCE
// #endif
// #define DEBOUNCE 10     // Default for kyria is 5

// Combos
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_TERM 30
#define COMBO_TERM_PER_COMBO

// Space saving measures
// - See https://docs.qmk.fm/#/squeezing_avr?id=rgb-settings for some rgb stuff
//   to disable as well
#define NO_MUSIC_MODE       // No music on the kyria
// #define LAYER_STATE_8BIT

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#ifdef RGB_MATRIX_ENABLE
#   undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS   50 // same as bkb default

// #   define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_RAINBOW_MOVING_CHEVRON // Sets the default mode, if none has been set
#   define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // same as bkb default
#   define RGB_MATRIX_STARTUP_HUE 0
#   define RGB_MATRIX_STARTUP_SAT 255
#   define RGB_MATRIX_STARTUP_SPD 127
// #   undef RGB_DISABLE_WHEN_USB_SUSPENDED
// #   define RGB_DISABLE_TIMEOUT 0 // number of milliseconds to wait until rgb automatically turns off
#endif
