#include "planck.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = {
{KC_EQL,  KC_Q,    KC_W,    KC_E,         KC_R,         KC_T,          KC_Y,    KC_U,         KC_I,          KC_O,    KC_P,    KC_MINS},
{OSL(3),  KC_A,    KC_S,    KC_D,         KC_F,         KC_G,          KC_H,    KC_J,         KC_K,          KC_L,    KC_LCTL, KC_ENT},
{KC_RCTL, KC_Z,    KC_X,    KC_C,         KC_V,         KC_B,          KC_N,    KC_M,         KC_COMM,       KC_DOT,  KC_SLSH, KC_TILD},
{KC_DEL,  KC_LCTL, KC_LALT, OSM(MOD_LALT),LT(1,KC_ESC), SFT_T(KC_SPC), _______, LT(2,KC_TAB), OSM(MOD_LGUI), KC_LGUI, _______, KC_GRV}
},
[1] = {
{_______, _______, KC_AMPR, KC_ASTR, KC_PIPE, _______, KC_QUOT, KC_7, KC_8,    KC_9,    _______, _______},
{_______, _______, KC_DLR,  KC_PERC, KC_CIRC, _______, KC_DQUO, KC_4, KC_5,    KC_6,    KC_COLN, KC_SCLN},
{_______, _______, KC_EXLM, KC_AT,   KC_HASH, _______, KC_GRV,  KC_1, KC_2,    KC_3,    KC_BSLS, _______},
{RESET,   _______, _______, _______, _______, KC_BSPC, _______, KC_0, _______, _______, _______, _______}
},
[2] = {
{KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12},
{_______, _______, KC_LBRC, KC_LCBR, KC_LPRN, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_HOME, KC_END},
{_______, _______, KC_RBRC, KC_RCBR, KC_RPRN, _______, _______, _______, _______, _______,  _______, _______},
{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______}
},
[3] = {
{_______, _______, _______, _______, _______, _______, _______, _______,            _______, _______,  _______, _______},
{_______, _______, _______, _______, _______, _______, _______, _______,            _______, _______,  _______, _______},
{_______, _______, _______, _______, _______, _______, _______, _______,            _______, _______,  _______, _______},
{_______, _______, _______, _______, _______, _______, _______, LCTL(LALT(KC_GRV)), _______, _______,  _______, _______}
}
};


const uint16_t PROGMEM fn_actions[] =
{
};

