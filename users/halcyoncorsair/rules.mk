# Build options
CAPS_WORD_ENABLE ?= no
ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
	SRC += features/caps_word.c
    OPT_DEFS += -DCAPS_WORD_ENABLE
endif

REPEAT_KEY_ENABLE ?= no
ifeq ($(strip $(REPEAT_KEY_ENABLE)), yes)
	SRC += features/repeat_key.c
    OPT_DEFS += -DREPEAT_KEY_ENABLE
endif

SELECT_WORD_ENABLE ?= no
ifeq ($(strip $(SELECT_WORD_ENABLE)), yes)
    SRC += features/select_word.c
    OPT_DEFS += -DSELECT_WORD_ENABLE
endif
