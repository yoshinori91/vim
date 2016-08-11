#include "planck.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define HENK 10
#define ESC 99

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = {
  {KC_EQL,  KC_Q,    KC_W,    KC_E,         KC_R,         KC_T,          KC_Y,    KC_U,          KC_I,          KC_O,    KC_P,    KC_MINS},
  {M(HENK), KC_A,    KC_S,    KC_D,         KC_F,         KC_G,          KC_H,    KC_J,          KC_K,          KC_L,    M(ESC),  CTL_T(KC_ENT)},
  {KC_TILD, KC_Z,    KC_X,    KC_C,         KC_V,         KC_B,          KC_N,    KC_M,          KC_COMM,       KC_DOT,  KC_SLSH, KC_BSLS},
  {KC_DEL,  KC_LCTL, KC_LALT, OSM(MOD_LALT),LT(1,KC_BSPC),SFT_T(KC_SPC), _______, LT(2, KC_TAB), OSM(MOD_LGUI), KC_LGUI, _______, KC_GRV}
},
[1] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,   KC_ASTR,    KC_LBRC, KC_RBRC, KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_LPRN,   KC_RPRN,    KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS),S(KC_NUBS), _______, _______, _______},
  {RESET,   _______, _______, _______, _______, KC_BSPC, _______, _______,   _______,    _______, _______, M(199)}
},
[2] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_DEL,  KC_SCLN, KC_COLN, KC_QUOT, KC_DQUO, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_NUHS, KC_NUBS, _______, _______, _______},
  {RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______}
}
};

const uint16_t PROGMEM fn_actions[] =
{
};

static int jp_flg = 0;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
//  }
  switch(id) {
    case 10:
      if (record->event.pressed) {
          if (jp_flg == 0) {
            jp_flg = 1;
            register_code(KC_HENK);
          } else {
            jp_flg = 0;
            register_code(KC_HENK);
          }
      } else {
            unregister_code(KC_HENK);
      }
      break;

    case 99:
      if (record->event.pressed) {
          if (jp_flg == 0) {
            register_code(KC_ESC);
            unregister_code(KC_ESC);
          } else {
            jp_flg = 0;
            register_code(KC_HENK);
            unregister_code(KC_HENK);
            register_code(KC_ESC);
            unregister_code(KC_ESC);
          }
      }
      break;
    case 199:
      if (record->event.pressed) {
            jp_flg = 0;
      }
      break;
   }
   return MACRO_NONE;
};
