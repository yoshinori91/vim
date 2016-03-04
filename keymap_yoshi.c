#include "keymap_common.h"
#include "backlight.h"
#include "debug.h"

#define QWERTY_LAYER 0
#define LOWER_LAYER 1
#define UPPER_LAYER 2
#define SPACEFN_LAYER 3
#define F_LAYER 4
#define FN1_LAYER 5
#define CTL_LAYER 6
#define FN2_LAYER 7

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY_LAYER] = { /* Qwerty */
  {KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y, KC_U,          KC_I,     KC_O,    KC_P,           KC_BSPC},
  {KC_N,    FUNC(5), KC_S,    KC_D,    KC_F,    KC_G,    KC_H, KC_J,          KC_K,     KC_L,    CTL_T(KC_SCLN), FUNC(7)},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N, KC_M,          KC_COMMA, KC_DOT,  KC_SLSH,        FUNC(4)},
  {KC_LCTL, KC_ESC,  KC_LGUI, KC_LALT, FUNC(1), SFT_T(KC_SPC), SFT_T(KC_SPC), FUNC(2),  KC_LEFT, KC_DOWN,        KC_UP}
},
[LOWER_LAYER] = { /* LOWER */
  {RESET,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_7,  KC_8,     KC_9,     KC_TRNS,    KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_4,  KC_5,     KC_6,     LCTL(KC_L), KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_1,  KC_2,     KC_3,     KC_TRNS,    KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_0,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS}
},
[UPPER_LAYER] = { /* RAISE */
  {KC_TRNS,   KC_TRNS, KC_UNDS, KC_PLUS,  KC_SCLN,  KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS},
  {KC_TRNS,   KC_MINS, KC_EQL,  KC_LPRN,  KC_RPRN,  KC_TRNS, KC_LEFT, KC_DOWN,   KC_UP,     KC_RIGHT, KC_HOME, KC_END},
  {KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS},
  {KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TAB,   KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS}
},
[SPACEFN_LAYER] = { /* SpaceFN */
  {KC_TRNS,  KC_TRNS,  S(KC_W),  S(KC_E),  S(KC_R),  S(KC_T),  S(KC_Y),     S(KC_U),  S(KC_I),  S(KC_O),  KC_TRNS,    KC_DELETE},
  {S(KC_N),  S(KC_A),  S(KC_S),  S(KC_D),  S(KC_F),  S(KC_G),  S(KC_H),     S(KC_J),  S(KC_K),  S(KC_L),  S(KC_QUOT), KC_TRNS},
  {KC_TRNS,  S(KC_Z),  S(KC_X),  S(KC_C),  S(KC_V),  S(KC_GRV),S(KC_SLSH),  S(KC_M),  S(KC_P),  S(KC_B),  S(KC_Q),    KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS}
},
[F_LAYER] = { 
  {KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS},
  {KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,  KC_F12,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS},
  {KC_CALC,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS}
},
[FN1_LAYER] = { 
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  S(KC_7),  S(KC_8),  KC_TRNS,  KC_TRNS,  KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_SCLN,  S(KC_4),  S(KC_5),  S(KC_6),  KC_TRNS,  KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  S(KC_1),  S(KC_2),  S(KC_3),  KC_TRNS,  KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS}
},
[CTL_LAYER] = { 
  {KC_TRNS,     KC_TRNS,     LCTL(KC_W),  LCTL(KC_E),  LCTL(KC_R),  LCTL(KC_T),  LCTL(KC_Y),  LCTL(KC_U),  LCTL(KC_I),  LCTL(KC_O),  KC_TRNS,    KC_TRNS},
  {LCTL(KC_N),  LCTL(KC_A),  LCTL(KC_S),  LCTL(KC_D),  LCTL(KC_F),  LCTL(KC_G),  LCTL(KC_H),  LCTL(KC_J),  LCTL(KC_K),  LCTL(KC_L),  KC_TRNS,    KC_TRNS},
  {KC_TRNS,     LCTL(KC_Z),  LCTL(KC_X),  LCTL(KC_C),  LCTL(KC_V),  LCTL(KC_B),  LCTL(KC_N),  LCTL(KC_M),  LCTL(KC_P),  LCTL(KC_B),  LCTL(KC_Q), KC_TRNS},
  {KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS}
},
[FN2_LAYER] = { 
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  S(KC_LBRC), S(KC_RBRC), S(KC_COMM),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS},
  {KC_TRNS,  KC_COMM,  KC_DOT,   KC_LBRC,    KC_RBRC,    S(KC_DOT),   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS}
}
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_KEY(LOWER_LAYER, KC_ESC),

    [2] = ACTION_LAYER_TAP_KEY(UPPER_LAYER, KC_BSPC),

    [4] = ACTION_LAYER_MOMENTARY(F_LAYER),
 
    [5] = ACTION_LAYER_TAP_KEY(FN1_LAYER, KC_A),  

    [6] = ACTION_LAYER_TAP_KEY(SPACEFN_LAYER, KC_SPC), 

    [7] = ACTION_LAYER_TAP_KEY(CTL_LAYER, KC_ENT),

    [8] = ACTION_LAYER_TAP_KEY(FN2_LAYER, KC_QUOT),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) 
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:   
        if (record->event.pressed) {
          register_code(KC_RSFT);
          backlight_step();
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      } 
    return MACRO_NONE;
};

