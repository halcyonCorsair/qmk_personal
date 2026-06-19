OLED_ENABLE			= yes	# Enables the use of OLED displays

ENCODER_ENABLE		= yes	# 1018 (with my config)	# Enables the use of one or more encoders

# keep RGBLIGHT, or go back to RGB_MATRIX?
RGBLIGHT_ENABLE		= no	# 2108  # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE	= yes	# 2520

COMBO_ENABLE		= yes
LEADER_ENABLE		= no	# 162
NKRO_ENABLE			= no	# 316
SWAP_HANDS_ENABLE	= no    # 570

# Userspace features
CAPS_WORD_ENABLE	= yes
# TODO - repeat is also messed up
REPEAT_KEY_ENABLE	= no # 276
# TODO - fix select word
SELECT_WORD_ENABLE	= no

# Need to reduce firmware size
LTO_ENABLE			= yes
##
CONSOLE_ENABLE		= yes
##
COMMAND_ENABLE		= no
MOUSEKEY_ENABLE		= no
# EXTRAKEY_ENABLE = no // this includes media keys and system volume control
SPACE_CADET_ENABLE	= no
GRAVE_ESC_ENABLE	= no	# 82
MAGIC_ENABLE		= no
MUSIC_ENABLE		= no
