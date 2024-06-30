VIA_ENABLE          = yes
VIAL_ENABLE         = yes
LTO_ENABLE          = no

RGBLIGHT_ENABLE     = no
RGB_MATRIX_ENABLE   = no # Can't have RGBLIGHT and RGB_MATRIX at the same time.
MOUSEKEY_ENABLE     = yes
OLED_ENABLE         = yes
OLED_DRIVER         = ssd1306
EXTRAKEY_ENABLE     = yes          # Audio control and System control
COMBO_ENABLE        = yes

QMK_SETTINGS        = yes

SERIAL_DRIVER = vendor

CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration

TRI_LAYER_ENABLE = yes

SRC += flow.c