OLED_ENABLE 		= yes
OLED_DRIVER 		= SSD1306   	# Enables the use of OLED displays
ENCODER_ENABLE  	= yes   # 1018 (with my config)	# Enables the use of one or more encoders

RGBLIGHT_ENABLE 	= no    # 2108  # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE 	= yes	# 2520

COMBO_ENABLE 	  	= yes
LEADER_ENABLE		= yes	# 162
NKRO_ENABLE 	  	= yes	# 316
# SWAP_HANDS_ENABLE   = no    # 570

# Userspace features
CAPS_WORD_ENABLE	= yes
REPEAT_KEY_ENABLE	= yes	# 276
SELECT_WORD_ENABLE	= yes

# Need to reduce firmware size
LTO_ENABLE 			= yes
CONSOLE_ENABLE 		= no
COMMAND_ENABLE 		= no
MOUSEKEY_ENABLE 	= no
# EXTRAKEY_ENABLE = no // this includes media keys and system volue control
SPACE_CADET_ENABLE 	= no
GRAVE_ESC_ENABLE 	= no	# 82
MAGIC_ENABLE 		= no
MUSIC_ENABLE 		= no
