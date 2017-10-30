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
  {KC_EQL,  KC_Q,   KC_W,   KC_E,         KC_R,         KC_T,         KC_Y,   KC_U,         KC_I,         KC_O,   KC_P,         KC_MINS},
  {KC_SCLN, KC_A,   KC_S,   KC_D,         KC_F,         KC_G,         KC_H,   KC_J,         KC_K,         KC_L,   OSM(MOD_LCTL),KC_ENT,},
  {KC_TILD, KC_Z,   KC_X,   KC_C,         KC_V,         KC_B,         KC_N,   KC_M,         KC_COMM,      KC_DOT, KC_SLSH,      KC_BSLS},
  {KC_DEL,  KC_LCTL,KC_LALT,OSM(MOD_LALT),LT(1, KC_ESC),SFT_T(KC_SPC),_______,LT(2, KC_TAB),OSM(MOD_LGUI),KC_DOWN,KC_UP,        KC_RGHT}
},
[1] = {
  {_______,_______,KC_AMPR, KC_ASTR, KC_PIPE, _______, S(KC_QUOT), KC_7, KC_8,    KC_9,    _______, _______},
  {_______,_______,KC_DLR,  KC_PERC, KC_CIRC, _______, KC_QUOT,    KC_4, KC_5,    KC_6,    KC_APP,  _______},
  {_______,_______,KC_EXLM, KC_AT,   KC_HASH, _______, KC_GRV,     KC_1, KC_2,    KC_3,    _______, _______},
  {_______,_______,_______, _______, _______, _______, _______,    KC_0, _______, _______, _______, _______}
},
[2] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F12,  KC_F12},
  {_______, _______, KC_LBRC, KC_LCBR, KC_LPRN, KC_SCLN, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_HOME, KC_END},
  {_______,_______,  KC_RBRC, KC_RCBR, KC_RPRN, _______, _______, _______, _______, _______,  KC_PGUP, KC_PGDN},
  {RESET,  _______,  _______, _______, KC_BSPC, _______, _______, _______, _______, _______,  _______, _______}
}
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 1:
      if (record->event.pressed) {
        layer_on(1);
      } else {
        layer_off(1);
      }
      break;
    case 2:
      if (record->event.pressed) {
        layer_on(2);
      } else {
        layer_off(2);
      }
      break;
  }
  return MACRO_NONE;
};
