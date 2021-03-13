SPACE_CADET_ENABLE = no

# Use LTO except for ChibiOS
ifneq ($(PLATFORM),CHIBIOS)
    LTO_ENABLE            = yes
endif

ifeq ($(strip $(IS_MACROPAD)), yes)
    OPT_DEFS += -DIS_MACROPAD
endif


ifeq ($(strip $(FLASH_BOOTLOADER)), yes)
    OPT_DEFS += -DFLASH_BOOTLOADER
endif

ifneq ($(FORCE_LAYOUT),)
    OPT_DEFS += -DFORCE_LAYOUT=\"$(FORCE_LAYOUT)\"
endif
ifeq ($(strip $(NO_SECRETS)), yes)
    OPT_DEFS += -DNO_SECRETS
endif

ifeq ($(strip $(USE_1X2_LAYOUT)), yes)
    OPT_DEFS += -DUSE_1X2_LAYOUT
endif

