#include "planck.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define LEADER_TIMEOUT 300

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = {
  {KC_EQL,  KC_Q,   KC_W,    KC_E,         KC_R,         KC_T,         KC_Y,   KC_U, KC_I,    KC_O,         KC_P,         KC_MINS},
  {KC_SCLN, KC_A,   KC_S,    KC_D,         KC_F,         KC_G,         KC_H,   KC_J, KC_K,    KC_L,         OSM(MOD_LCTL),KC_ENT},
  {KC_BSLS, KC_Z,   KC_X,    KC_C,         KC_V,         KC_B,         KC_N,   KC_M, KC_COMM, KC_DOT,       KC_SLSH,      KC_LEAD},
  {KC_DEL,  _______,KC_LALT, OSM(MOD_LALT),LT(1, KC_ESC),SFT_T(KC_SPC),_______,LT(2, KC_TAB), OSM(MOD_LGUI),KC_DOWN,      KC_UP,KC_RGHT}
},
[1] = {
  {_______,_______,KC_AMPR, KC_ASTR, KC_PIPE, _______, KC_GRV, KC_7, KC_8,    KC_9,    _______,   _______},
  {_______,_______,KC_DLR,  KC_PERC, KC_CIRC, _______, KC_QUOT, KC_4, KC_5,    KC_6,    S(KC_QUOT),_______},
  {_______,_______,KC_EXLM, KC_AT,   KC_HASH, _______, _______, KC_1, KC_2,    KC_3,    _______,   _______},
  {_______,_______,_______, _______, _______, KC_BSPC, _______, KC_0, _______, _______, _______,   _______}
},
[2] = {
  {KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
  {KC_COLN,_______, KC_LBRC, KC_LCBR, KC_LPRN, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_HOME, KC_END},
  {_______,  _______, KC_RBRC, KC_RCBR, KC_RPRN, _______,      _______, _______, _______, _______, KC_PGUP, KC_PGDN},
  {RESET,    _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______}
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

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_Q) {
      SEND_STRING("QMK is awesome.");
    }
    SEQ_ONE_KEY(KC_SCLN) {
      register_code(KC_DELETE);
      unregister_code(KC_DELETE);
    }
    SEQ_ONE_KEY(KC_A) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_A);
      unregister_code(KC_A);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_B) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_B);
      unregister_code(KC_B);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_C) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_C);
      unregister_code(KC_C);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_D) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_D);
      unregister_code(KC_D);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_E) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_E);
      unregister_code(KC_E);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_F) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_F);
      unregister_code(KC_F);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_G) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_G);
      unregister_code(KC_G);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_H) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_H);
      unregister_code(KC_H);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_I) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_I);
      unregister_code(KC_I);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_J) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_J);
      unregister_code(KC_J);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_K) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_K);
      unregister_code(KC_K);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_L) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_L);
      unregister_code(KC_L);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_M) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_M);
      unregister_code(KC_M);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_N) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_N);
      unregister_code(KC_N);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_O) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_O);
      unregister_code(KC_O);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_P) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_P);
      unregister_code(KC_P);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_Q) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_Q);
      unregister_code(KC_Q);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_R) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_R);
      unregister_code(KC_R);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_S) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_T) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_T);
      unregister_code(KC_T);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_U) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_U);
      unregister_code(KC_U);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_V) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_V);
      unregister_code(KC_V);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_W) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_W);
      unregister_code(KC_W);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_X) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_X);
      unregister_code(KC_X);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_Y) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_Y);
      unregister_code(KC_Y);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_Z) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_Z);
      unregister_code(KC_Z);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
  }
}
