# Build options

VPATH += keyboards/gboards

SRC += halcyoncorsair.c \
		process_records.c

ENCODER_ENABLE ?= no
ifeq ($(strip $(ENCODER_ENABLE)), yes)
	SRC += encoder_config.c
    OPT_DEFS += -DENCODER_ENABLE
endif

OLED_ENABLE ?= no
ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += oled_config.c
    OPT_DEFS += -DOLED_ENABLE
endif

COMBO_ENABLE ?= no
ifeq ($(strip $(COMBO_ENABLE)), yes)
	SRC += combos.c
endif
