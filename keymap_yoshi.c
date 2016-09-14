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
{KC_EQL,  KC_Q,        KC_W,    KC_E,         KC_R,   KC_T,          KC_Y,    KC_U,   KC_I,          KC_O,    KC_P,          KC_MINS},
{OSL(3),  ALT_T(KC_A), KC_S,    KC_D,         KC_F,   KC_G,          KC_H,    KC_J,   KC_K,          KC_L,    CTL_T(KC_ESC), KC_TAB},
{KC_TILD, KC_Z,        KC_X,    KC_C,         KC_V,   KC_B,          KC_N,    KC_M,   KC_COMM,       KC_DOT,  KC_SLSH,       KC_ENT},
{KC_DEL,  KC_LCTL,     KC_LALT, OSM(MOD_LALT),OSL(1), SFT_T(KC_SPC), _______, OSL(2), OSM(MOD_LGUI), KC_LGUI, _______,       KC_GRV}
},
[1] = {
{_______, _______, KC_CIRC, KC_AMPR, KC_PIPE, _______, _______, KC_7, KC_8,    KC_9,   KC_GRV, _______},
{_______, _______, KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_4, KC_5,    KC_6,    KC_TILD, _______},
{_______, _______, KC_EXLM, KC_AT,   KC_HASH, _______, _______, KC_1, KC_2,    KC_3,    KC_BSLS, _______},
{RESET,   _______, _______, _______, _______, KC_BSPC, _______, KC_0, _______, _______, _______, _______}
},
[2] = {
{_______, _______, _______, KC_DQUO, KC_QUOT, KC_SCLN, _______, _______, _______, _______, _______, _______},
{_______, _______, KC_LBRC, KC_LCBR, KC_LPRN, KC_COLN, KC_LEFT, KC_DOWN, KC_UP,   KC_LEFT, KC_HOME, KC_END},
{_______, _______, KC_RBRC, KC_RCBR, KC_RPRN, _______, _______, _______, _______, _______, _______, _______},
{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},
[3] = {
{KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}, 
{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
}
};
const uint16_t PROGMEM fn_actions[] =
{
};

~                                                                                                                                                                                                           
~                                                                                                                                                                                                           
~                                                                                                                                                                                                           
~                                                                                                                                                                                                           
~                                     
