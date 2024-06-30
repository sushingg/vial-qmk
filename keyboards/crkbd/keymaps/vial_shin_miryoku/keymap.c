/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "flow.h"
#include "layers.h"
#include "oled.c"

// Shortcut to make keymap more readable

#define L_NAV   LT(1,KC_SPC)
#define L_MOU   LT(2,KC_TAB)
#define L_MED   LT(3,KC_ESC)
#define L_NUM   LT(4,KC_BSPC)
#define L_SYM   LT(5,KC_ENT)
#define L_FUN   LT(6,KC_DEL)

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
    LAYER5,
    LAYER6,
    OS_TMUX
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_CMK] = LAYOUT_split_3x6_3(
    KC_NO,    KC_Q,    KC_W,       KC_F,       KC_P,       KC_B,    /***/   KC_J,     KC_L,    KC_U,        KC_Y,       KC_QUOT,    KC_NO,
    KC_NO,    KC_A,    KC_R,       KC_S,       KC_T,       KC_G,    /***/   KC_M,     KC_N,    KC_E,        KC_I,       KC_O,       KC_NO,
    KC_NO,    KC_Z,    KC_X,       KC_C,       KC_D,       KC_V,    /***/   KC_K,     KC_H,    KC_COMM,     KC_DOT,     KC_SLSH,    KC_NO,
                        LT(3,KC_ESC), LT(1,KC_SPC), LT(2,KC_TAB),    /***/   LT(5,KC_ENT), LT(4,KC_BSPC), LT(6,KC_DEL)),

 [_NAV] = LAYOUT_split_3x6_3(
    KC_NO, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO,    /***/    KC_AGIN, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, KC_NO,
    KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,    /***/   KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,
    KC_NO, KC_NO, KC_RALT, KC_NO, KC_NO, KC_NO,    /***/   KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO,
                        KC_NO, KC_NO, KC_NO,    /***/   KC_ENT, KC_BSPC, KC_DEL),

 [_MOU] = LAYOUT_split_3x6_3(
    KC_NO, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO,    /***/    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,    /***/   KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,
    KC_NO, KC_NO, KC_RALT, KC_NO, KC_NO, KC_NO,    /***/   KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,
                        KC_NO, KC_NO, KC_NO,    /***/   KC_BTN2, KC_BTN1, KC_BTN3),

 [_MED] = LAYOUT_split_3x6_3(
    KC_NO, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO,    /***/    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO,
    KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,    /***/   KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,
    KC_NO, KC_NO, KC_RALT, KC_NO, KC_NO, KC_NO,    /***/   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                        KC_NO, KC_NO, KC_NO,    /***/   KC_MSTP, KC_MPLY, KC_MUTE),

 [_NUM] = LAYOUT_split_3x6_3(
    KC_NO, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,    /***/    KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, KC_NO,
    KC_NO, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,    /***/   KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
    KC_NO, KC_GRV, KC_1, KC_2, KC_3, KC_BSLS,    /***/   KC_NO, KC_NO, KC_NO, KC_RALT, KC_NO, KC_NO,
                        KC_DOT, KC_0, KC_MINS,    /***/   KC_NO, KC_NO, KC_NO),

 [_SYM] = LAYOUT_split_3x6_3(
    KC_NO, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,    /***/    KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, KC_NO,
    KC_NO, KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,    /***/   KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
    KC_NO, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE,    /***/   KC_NO, KC_NO, KC_NO, KC_RALT, KC_NO, KC_NO,
                        KC_LPRN, KC_RPRN, KC_UNDS,    /***/   KC_NO, KC_NO, KC_NO),

 [_FUN] = LAYOUT_split_3x6_3(
    KC_NO, KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,    /***/    KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, KC_NO,
    KC_NO, KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,    /***/   KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
    KC_NO, KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,    /***/   KC_NO, KC_NO, KC_NO, KC_RALT, KC_NO, KC_NO,
                        KC_APP, KC_SPC, KC_TAB,    /***/   KC_NO, KC_NO, KC_NO)

};

// flow_config should correspond to following format:
// * layer keycode
// * modifier keycode
const uint16_t flow_config[FLOW_COUNT][2] = {
    {L_NAV, KC_LALT},
    {L_NAV, KC_LGUI},
    {L_NAV, KC_LCTL},
    {L_NAV, KC_LSFT},
    {L_NAV, KC_RALT},

    {L_MOU, KC_LALT},
    {L_MOU, KC_LGUI},
    {L_MOU, KC_LCTL},
    {L_MOU, KC_LSFT},
    {L_MOU, KC_RALT},

    {L_MED, KC_LALT},
    {L_MED, KC_LGUI},
    {L_MED, KC_LCTL},
    {L_MED, KC_LSFT},
    {L_MED, KC_RALT},

    {L_NUM, KC_LALT},
    {L_NUM, KC_LGUI},
    {L_NUM, KC_LCTL},
    {L_NUM, KC_LSFT},
    {L_NUM, KC_RALT},

    {L_SYM, KC_LALT},
    {L_SYM, KC_LGUI},
    {L_SYM, KC_LCTL},
    {L_SYM, KC_LSFT},
    {L_SYM, KC_RALT},

    {L_FUN, KC_LALT},
    {L_FUN, KC_LGUI},
    {L_FUN, KC_LCTL},
    {L_FUN, KC_LSFT},
    {L_FUN, KC_RALT},
};
const uint16_t flow_layers_config[FLOW_LAYERS_COUNT][2] = {
    {OS_TMUX, _OTR},
};
// Add following to handle flow

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!update_flow(keycode, record->event.pressed, record->event.key)) return false;
    return true;
}

void matrix_scan_user(void) {
    flow_matrix_scan();
}