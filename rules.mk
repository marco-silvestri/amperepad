# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#

BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes      # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = yes           # Audio output
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes
POINTING_DEVICE_ENABLE = no
DIP_SWITCH_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
OLED_TRANSPORT = i2c
OS_DETECTION_ENABLE = yes
EXTRAFLAGS += -flto
