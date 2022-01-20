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

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_HUE_STEP  8
#    define RGBLIGHT_SAT_STEP  8
#    define RGBLIGHT_VAL_STEP  8
#    define RGBLIGHT_LIMIT_VAL 150
#endif

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

#define LEADER_TIMEOUT 350

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
#ifdef DEBOUNCE
#    undef DEBOUNCE
#endif
#define DEBOUNCE        6   // Default for kyria is 5

// Combos
#define COMBO_ONLY_FROM_LAYER 0

// Rotary encoders
#define ENCODER_DIRECTION_FLIP

// EC11K encoders have a different resolution than other EC11 encoders.
// When using the default resolution of 4, if you notice your encoder skipping
// every other tick, lower the resolution to 2.
#define ENCODER_RESOLUTION 2

// Allows to use either side as the master. Look at the documentation for info:
// https://docs.qmk.fm/#/config_options?id=setting-handedness
#define EE_HANDS    // 12

// Sync states to both sides, e.g. for oled
#ifdef OLED_ENABLE
#   define OLED_DISPLAY_128X64
#   define OLED_BRIGHTNESS 1
#   define SPLIT_LAYER_STATE_ENABLE    // 146
#   define SPLIT_LED_STATE_ENABLE      // 116
#   define SPLIT_MODS_ENABLE
#endif

// Space saving measures
// - See https://docs.qmk.fm/#/squeezing_avr?id=rgb-settings for some rgb stuff
//   to disable as well
#define NO_MUSIC_MODE       // No music on the kyria
// #define LAYER_STATE_8BIT

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// #undef ENABLE_RGB_MATRIX_ALPHAS_MODS
// #undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING                 // 338
// #undef ENABLE_RGB_MATRIX_BAND_SAT
// #undef ENABLE_RGB_MATRIX_BAND_VAL
// #undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #undef ENABLE_RGB_MATRIX_CYCLE_ALL
// #undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON    // 178
// #undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
// #undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
// #undef ENABLE_RGB_MATRIX_DUAL_BEACON
// #undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #undef ENABLE_RGB_MATRIX_RAINDROPS
// #undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #undef ENABLE_RGB_MATRIX_HUE_BREATHING
// #undef ENABLE_RGB_MATRIX_HUE_PENDULUM
// #undef ENABLE_RGB_MATRIX_HUE_WAVE
// #undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// #undef ENABLE_RGB_MATRIX_PIXEL_RAIN

// Apparently zero cost, so let's just enable them
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

// #define ENABLE_SYMBOL_LAYER_ORIGINAL
