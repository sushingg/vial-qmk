// OLED
// #include <stdbool.h>
// #include <cstdint>
// #define OLED_ENABLE
#include <glich.c>

#ifdef OLED_ENABLE

// static const char PROGMEM font_logo[16] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};

static const char PROGMEM crkbd_logo[128] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf0, 0x30,
    0x00, 0x80, 0xe0, 0xf8, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xf0, 0xf8, 0xfc, 0xfe, 0xc0, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,
    0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x07, 0x1f, 0x3f, 0x7f, 0x7f, 0x7e, 0x7f, 0x3f, 0x3f, 0x7f, 0x7f, 0xff, 0xff,
    0xff, 0x7f, 0x7f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf0, 0xf0, 0x70, 0x38, 0x1e, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P((modifiers & MOD_MASK_SHIFT) ? PSTR("Shift\n") : PSTR("     \n"), false);
    oled_write_P((modifiers & MOD_MASK_CTRL) ? PSTR("Ctrl\n") : PSTR("    \n"), false);
    oled_write_P((modifiers & MOD_MASK_ALT) ? PSTR("Alt \n") : PSTR("    \n"), false);
    oled_write_P((modifiers & MOD_MASK_GUI) ? PSTR("Super\n") : PSTR("     \n"), false);
}

void render_lock_status(led_t led_state) {
    oled_write_P(led_state.caps_lock ? PSTR("CAPS\n") : PSTR("    \n"), false);
}

void render_layer_status(void) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _CMK:
            oled_write(" CMK ", false);
            break;
        case _NAV:
            oled_write(" NAV ", false);
            break;
        case _MOU:
            oled_write("MOUSE", false);
            break;
        case _MED:
            oled_write("MEDIA", false);
            break;
        case _NUM:
            oled_write(" NUM ", false);
            break;
        case _SYM:
            oled_write(" SYM ", false);
            break;
        case _FUN:
            oled_write(" FUN ", false);
            break;
        case _GAM:
            oled_write("GAME ", false);
            break;
        case _GFN:
            oled_write("G_FUN", false);
            break;
        default:
            oled_write("OTHER", false);
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_lock_status(host_keyboard_led_state());
        render_mod_status(get_mods() | get_oneshot_mods());

        oled_set_cursor(0, 8);
        oled_write_raw_P(crkbd_logo, 128);

        oled_set_cursor(0, 15);
        render_layer_status();
    } else {
        // oled_write_P(font_logo, false);
        // oled_write("corne", false);
        // oled_set_cursor(0, 13);
        // oled_write("crkbd", false);
        // oled_set_cursor(0, 15);
        // oled_write("SHIN", false);

        // oled_set_brightness(0)
        if (is_oled_on()) {
            if (last_input_activity_elapsed() > OLED_TIMEOUT) {
                oled_off();
                return false;
            }
            arasaka_draw();
        }
    }
    return false;
}

#endif