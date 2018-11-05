#include "planck.h"

// この他にもTAPを使用するため、tab_enable = true 等の設定が必要となる。
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum {
  CT_CLN,
  X_TAP_DANCE
};

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
};

void dance_cln_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RSFT);
    register_code (KC_SCLN);
  } else {
    register_code (KC_SCLN);
  }
}

void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RSFT);
    unregister_code (KC_SCLN);
  } else {
    unregister_code (KC_SCLN);
  }
}

typedef struct {
  bool is_press_action;
  int state;
} tap;

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || state->pressed==0) return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    return DOUBLE_TAP;
  }
  else return 6;
}

static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

void x_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_ESC); break;
    case SINGLE_HOLD: layer_on(2); break;
    case DOUBLE_TAP:
        register_code(KC_LCTL);
        register_code(KC_SPC);
        break;
  }
}

void x_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_ESC); break;
    case SINGLE_HOLD: layer_off(2); break;
    case DOUBLE_TAP:
        unregister_code(KC_SPC);
        unregister_code(KC_LCTL);
        break;
  }
  xtap_state.state = 0;
}
qk_tap_dance_action_t tap_dance_actions[] = {
  [CT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset),
  [X_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,        KC_F12,
     KC_EQL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,          KC_MINS,
     KC_LALT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,    KC_J,    KC_K,    KC_L,    OSM(MOD_LCTL), KC_ENT,
     KC_GRV, KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,        KC_BSLS,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,       KC_BSPC,
     KC_SCLN, LT(_LOWER,KC_ESC),SFT_T(KC_SPC),                                      SFT_T(KC_SPC),  LT(_RAISE, KC_TAB),  KC_QUOT 
  ),

  [_LOWER] = LAYOUT(
     KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,                            KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
     _______, _______, KC_AMPR, KC_ASTR, KC_PIPE, _______,                            _______, KC_7,    KC_8,    KC_9,    _______, _______,
     _______, _______, KC_DLR,  KC_PERC, KC_CIRC, _______,                            _______, KC_4,    KC_5,    KC_6,    _______, _______,
     _______, _______, KC_EXLM, KC_AT,   KC_HASH, _______, KC_INS,          KC_DEL,   _______, KC_1,    KC_2,    KC_3,    _______, _______,
     _______, _______, KC_DEL,                                                        _______, KC_0, _______
  ),

  [_RAISE] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     _______, _______, KC_LBRC, KC_LCBR, KC_LPRN, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_HOME, KC_END,
     _______, _______, KC_RBRC, KC_RCBR, KC_RPRN, _______,_______,            _______,_______, _______, _______, _______, _______, _______,
     _______, _______, _______,                                                       _______, _______, _______
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
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
