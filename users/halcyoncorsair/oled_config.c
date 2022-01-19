#include "oled_config.h"

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("\nLayer: "), false);
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _COLEMAK_DH:
            oled_write_P(PSTR("Colemak-DH\n"), false);
            break;
        case _QWERTY:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Sym\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Write host Keyboard LED Status to OLEDs
    uint8_t modifiers = get_mods();
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(PSTR("\nCTRL "), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("ALT "), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("GUI "), (modifiers & MOD_MASK_GUI));
    oled_write_P(PSTR("SHIFT\n\n"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("CAPLCK"), led_usb_state.caps_lock);

    return false;
}
#endif
