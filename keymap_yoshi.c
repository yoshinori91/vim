#include "planck.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

//Tap Dance Declarations
enum {
  TD_ESC_CAPS = 0
};

//Tap Dance Definitions
const qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_ESC)),
  [1]            = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_LPRN), KC_RPRN)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = {
  {KC_BSLS, KC_Q,       KC_W,       KC_E,          KC_R,         KC_T,          KC_Y,    KC_U,          KC_I,          KC_O,    KC_P,          KC_MINS},
  {KC_EQL,  LT(5,KC_A), LT(4,KC_S), KC_D,          KC_F,         KC_G,          KC_H,    KC_J,          KC_K,          KC_L,    CTL_T(KC_ESC), LT(3,KC_ENT)},
  {KC_TILD, KC_Z,       KC_X,       KC_C,          KC_V,         KC_B,          KC_N,    KC_M,          KC_COMM,       KC_DOT,  KC_SLSH,       _______},
  {KC_DEL,  _______,    _______,    OSM(MOD_LALT), LT(1,KC_TAB), SFT_T(KC_SPC), _______, LT(2,KC_SCLN), OSM(MOD_LGUI), _______, _______,       RESET}
},
[1] = {
  {_______, _______, _______, _______, _______, _______, _______, KC_7, KC_8,    KC_9,    _______, _______}, 
  {_______, _______, _______, _______, _______, _______, _______, KC_4, KC_5,    KC_6,    _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_1, KC_2,    KC_3,    _______, _______},
  {_______, _______, _______, _______, _______, KC_BSPC, _______, KC_BSPC, KC_0, _______, _______, RESET}
},

[2] = {
  {_______, _______, KC_AMPR, KC_ASTR, _______, _______, _______, KC_HOME, _______, _______, _______, _______},
  {_______, _______, KC_DLR,  KC_PERC, KC_CIRC, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______},
  {_______, _______, KC_EXLM, KC_AT,   KC_HASH, _______, _______, KC_END,  _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, KC_BSPC, _______, _______, _______, _______, _______, _______}
},

[3] = {
  {_______, KC_F9,   KC_F10,   KC_F11, KC_F12,  _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_F5,   KC_F6,    KC_F7,  KC_F8,   _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_F1,   KC_F2,    KC_F3,  KC_F4,   _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET}
},
[4] = {
  {_______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______,  _______, _______, _______, KC_QUOT, KC_DQUO, _______, _______},
  {_______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______}
},
[5] = {
  {_______, _______, _______, _______, _______,  _______, _______, KC_LCBR, KC_RCBR, _______, _______, _______},
  {_______, _______, _______, _______, _______,  _______, _______, KC_LPRN, KC_RPRN, _______, _______, _______},
  {_______, _______, _______, _______, _______,  _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______},
  {_______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______}
}

};

const uint16_t PROGMEM fn_actions[] = {

};
