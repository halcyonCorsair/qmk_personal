OLED_ENABLE			= yes	# Enables the use of OLED displays
ENCODER_ENABLE		= yes	# 1018 (with my config)	# Enables the use of one or more encoders
COMBO_ENABLE		= yes
CAPS_WORD_ENABLE	= yes
# DEBUG: rbg matrix interacts badly with repeat_key_enable?
REPEAT_KEY_ENABLE	= yes

# Need to reduce firmware size
LTO_ENABLE			= yes

# Explodes repeat?
RGB_MATRIX_ENABLE	= no
# Doesn't explode repeat?
RGBLIGHT_ENABLE		= yes

# Debugging
CONSOLE_ENABLE		= no

# Maybe features
LEADER_ENABLE		= no
NKRO_ENABLE			= no	# Does this cause funky behaviour on the kyria?
SWAP_HANDS_ENABLE	= no

# Unused features (off for space)
# EXTRAKEY_ENABLE = no // this includes media keys and system volume control
COMMAND_ENABLE		= no
MOUSEKEY_ENABLE		= no
SPACE_CADET_ENABLE	= no
GRAVE_ESC_ENABLE	= no
MAGIC_ENABLE		= no
MUSIC_ENABLE		= no
MIDI_ENABLE			= no
AUDIO_ENABLE		= no