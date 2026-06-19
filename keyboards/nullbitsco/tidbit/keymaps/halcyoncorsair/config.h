/* Copyright 2026 Elliot Pahl <elliot.pahl@gmail.com>
 */
#pragma once

#define TAPPING_TOGGLE 2

// Set tapping term
#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif  // TAPPING_TERM
#define TAPPING_TERM 200

// already defined in the tidbit keyboard.json
// #define ENCODERS_PAD_A { B3 }
// #define ENCODERS_PAD_B { B2 }
