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

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define TAPPING_TERM_PER_KEY // See bottom of keymap.c

// // Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define TAPPING_FORCE_HOLD

// This prevents accidental repeats of the tap-hold keys when typing quickly.
#define TAPPING_FORCE_HOLD_PER_KEY

// Disable PERMISSIVE_HOLD
#undef PERMISSIVE_HOLD

// Other settings //
// TODO: review this setting
// #define HOLD_ON_OTHER_KEY_PRESS
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
#define DEBOUNCE 10     // Default for kyria is 5

// Combos
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_TERM 30
#define COMBO_TERM_PER_COMBO

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

// TODO - redo for RGB_LIGHT whatever
#ifdef RGB_MATRIX_ENABLE
#   undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS   120

// #    undef     RGB_MATRIX_NONE
// #    undef     RGB_MATRIX_SOLID_COLOR     // Static single hue no speed support
#    undef     RGB_MATRIX_ALPHAS_MODS         // Static dual hue speed is hue for secondary hue
#    undef     RGB_MATRIX_GRADIENT_UP_DOWN    // Static gradient top to bottom speed controls how much gradient changes
#    undef     RGB_MATRIX_GRADIENT_LEFT_RIGHT    // Static gradient left to right speed controls how much gradient changes
#    undef     RGB_MATRIX_BREATHING           // Single hue brightness cycling animation
#    undef     RGB_MATRIX_BAND_SAT        // Single hue band fading saturation scrolling left to right
#    undef     RGB_MATRIX_BAND_VAL        // Single hue band fading brightness scrolling left to right
#    undef     RGB_MATRIX_BAND_PINWHEEL_SAT   // Single hue 3 blade spinning pinwheel fades saturation
#    undef     RGB_MATRIX_BAND_PINWHEEL_VAL   // Single hue 3 blade spinning pinwheel fades brightness
#    undef     RGB_MATRIX_BAND_SPIRAL_SAT     // Single hue spinning spiral fades saturation
#    undef     RGB_MATRIX_BAND_SPIRAL_VAL     // Single hue spinning spiral fades brightness
#    undef     RGB_MATRIX_CYCLE_ALL           // Full keyboard solid hue cycling through full gradient
#    undef     RGB_MATRIX_CYCLE_LEFT_RIGHT    // Full gradient scrolling left to right
#    undef     RGB_MATRIX_CYCLE_UP_DOWN       // Full gradient scrolling top to bottom
#    undef     RGB_MATRIX_CYCLE_OUT_IN        // Full gradient scrolling out to in
#    undef     RGB_MATRIX_CYCLE_OUT_IN_DUAL   // Full dual gradients scrolling out to in
#    undef     RGB_MATRIX_RAINBOW_MOVING_CHEVRON  // Full gradient Chevron shapped scrolling left to right
#    undef     RGB_MATRIX_CYCLE_PINWHEEL      // Full gradient spinning pinwheel around center of keyboard
#    undef     RGB_MATRIX_CYCLE_SPIRAL        // Full gradient spinning spiral around center of keyboard
#    undef     RGB_MATRIX_DUAL_BEACON         // Full gradient spinning around center of keyboard
#    undef     RGB_MATRIX_RAINBOW_BEACON      // Full tighter gradient spinning around center of keyboard
#    undef     RGB_MATRIX_RAINBOW_PINWHEELS   // Full dual gradients spinning two halves of keyboard
#    undef     RGB_MATRIX_FLOWER_BLOOMING     // Full tighter gradient of first half scrolling left to right and second half scrolling right to left
#    undef     RGB_MATRIX_RAINDROPS           // Randomly changes a single key's hue
#    undef     RGB_MATRIX_JELLYBEAN_RAINDROPS // Randomly changes a single key's hue and saturation
#    undef     RGB_MATRIX_HUE_BREATHING       // Hue shifts up a slight amount at the same time then shifts back
#    undef     RGB_MATRIX_HUE_PENDULUM        // Hue shifts up a slight amount in a wave to the right then back to the left
#    undef     RGB_MATRIX_HUE_WAVE            // Hue shifts up a slight amount and then back down in a wave to the right
#    undef     RGB_MATRIX_PIXEL_FRACTAL       // Single hue fractal filled keys pulsing horizontally out to edges
#    undef     RGB_MATRIX_PIXEL_FLOW          // Pulsing RGB flow along LED wiring with random hues
#    undef     RGB_MATRIX_PIXEL_RAIN          // Randomly light keys with random hues
#    undef     RGB_MATRIX_TYPING_HEATMAP      // How hot is your WPM!
#    undef     RGB_MATRIX_DIGITAL_RAIN        // That famous computer simulation
#    undef     RGB_MATRIX_SOLID_REACTIVE_SIMPLE   // Pulses keys hit to hue & value then fades value out
#    undef     RGB_MATRIX_SOLID_REACTIVE      // Static single hue pulses keys hit to shifted hue then fades to current hue
#    undef     RGB_MATRIX_SOLID_REACTIVE_WIDE       // Hue & value pulse near a single key hit then fades value out
#    undef     RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Hue & value pulse near multiple key hits then fades value out
#    undef     RGB_MATRIX_SOLID_REACTIVE_CROSS      // Hue & value pulse the same column and row of a single key hit then fades value out
#    undef     RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
#    undef     RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Hue & value pulse away on the same column and row of a single key hit then fades value out
#    undef     RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
#    undef     RGB_MATRIX_SPLASH              // Full gradient & value pulse away from a single key hit then fades value out
#    undef     RGB_MATRIX_MULTISPLASH         // Full gradient & value pulse away from multiple key hits then fades value out
#    undef     RGB_MATRIX_SOLID_SPLASH        // Hue & value pulse away from a single key hit then fades value out
#    undef     RGB_MATRIX_SOLID_MULTISPLASH   // Hue & value pulse away from multiple key hits then fades value out
#    undef     RGB_MATRIX_STARLIGHT           // LEDs turn on and off at random at varying brightness maintaining user set color
#    undef     RGB_MATRIX_STARLIGHT_SMOOTH    // LEDs slowly increase and decrease in brightness randomly
#    undef     RGB_MATRIX_STARLIGHT_DUAL_HUE  // LEDs turn on and off at random at varying brightness modifies user set hue by +- 30
#    undef     RGB_MATRIX_STARLIGHT_DUAL_SAT  // LEDs turn on and off at random at varying brightness modifies user set saturation by +- 30
#    undef     RGB_MATRIX_RIVERFLOW           // Modification to breathing animation, offset's animation depending on key location to simulate a river flowing
#    undef     RGB_MATRIX_EFFECT_MAX

#   define ENABLE_RGB_MATRIX_BREATHING                 // 338
// Turn off to make space for debug
// #   define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON    // 178

// #   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RAINBOW_MOVING_CHEVRON // Sets the default mode, if none has been set
#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR // Sets the default mode, if none has been set
// #   define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#   define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS - 20
#   define RGB_MATRIX_DEFAULT_HUE 84
#   define RGB_MATRIX_DEFAULT_SAT 255
#   define RGB_MATRIX_DEFAULT_SPD 127
#   undef RGB_DISABLE_WHEN_USB_SUSPENDED
#   define RGB_DISABLE_TIMEOUT 0 // number of milliseconds to wait until rgb automatically turns off
#endif
