#include "keymap_common.h"
#include "backlight.h"
#include "debug.h"

#define QWERTY_LAYER 0
#define LOWER_LAYER 1
#define UPPER_LAYER 2
#define MIDDLE_LAYER 3
#define F_LAYER 4
#define FN1_LAYER 5
#define CTL_LAYER 6
#define FN2_LAYER 7

static int kanaFlag = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY_LAYER] = { /* Qwerty */
  {KC_GRV,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,   KC_U,    KC_I,     KC_O,   KC_SCLN,  KC_BSLS},
  {FUNC(5), KC_A,   KC_S,    KC_D,    KC_F,    KC_G,          KC_H,   KC_J,    KC_K,     KC_L,   KC_P,     CTL_T(KC_ENT)},
  {FUNC(1), KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,          KC_N,   KC_M,    KC_COMMA, KC_DOT, KC_SLSH,  FUNC(4)},
  {KC_LCTL, KC_ESC, KC_LGUI, KC_LALT, FUNC(1), SFT_T(KC_SPC), KC_TRNS ,FUNC(2), FUNC(1),  KC_DOWN, KC_BTN2, KC_BTN1}
},
[LOWER_LAYER] = { /* LOWER */
  {LALT(KC_TAB), RESET,    M(0),    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_7, KC_8,    KC_9,    KC_TRNS, KC_TRNS},
  {KC_TRNS,      KC_LBRC,  KC_RBRC, S(KC_LBRC), S(KC_RBRC), KC_TRNS, KC_BSPC, KC_4, KC_5,    KC_6,    KC_QUOT, S(KC_QUOT)},
  {KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_1, KC_2,    KC_3,    KC_TRNS, KC_TRNS},
  {KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
[MIDDLE_LAYER] = { /* MIDDLE */
  {KC_TRNS, KC_TRNS, S(KC_7),  S(KC_8),  S(KC_9), KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_TRNS, KC_TRNS},
  {KC_BSPC, KC_TRNS, S(KC_4),  S(KC_5),  S(KC_6), S(KC_0), KC_0,    KC_4,    KC_5,    KC_6,    KC_TRNS, KC_ENT},
  {KC_TRNS, KC_TRNS, S(KC_1),  S(KC_2),  S(KC_3), KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,    KC_TRNS, KC_TRNS},
  {RESET,   KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
[UPPER_LAYER] = { /* RAISE */
  {KC_TRNS,   KC_TRNS, KC_PLUS, KC_LBRC, KC_RBRC,    KC_TRNS, KC_RPRN, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS},
  {LCTL(KC_L),KC_MINS, KC_UNDS, KC_LCBR, KC_RCBR,    KC_EQL,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_HOME, KC_END},
  {KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_L), KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS}
},
[F_LAYER] = {
  {KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS},
  {KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,  KC_F12,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS},
  {KC_BTN2,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS}
},
[FN1_LAYER] = {
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  S(KC_7),  S(KC_8),  S(KC_9),  KC_TRNS, KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  S(KC_4),  S(KC_5),  S(KC_6),  S(KC_SCLN), KC_SCLN},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  S(KC_1),  S(KC_2),  S(KC_3),  KC_TRNS, KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  S(KC_0),  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS}
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
    [2] = ACTION_LAYER_TAP_KEY(UPPER_LAYER, KC_TAB),
    [3] = ACTION_LAYER_TAP_KEY(MIDDLE_LAYER, KC_SPC),
    [4] = ACTION_LAYER_TAP_KEY(F_LAYER, KC_BSPC),
    [5] = ACTION_LAYER_TAP_KEY(FN1_LAYER, LCTL(KC_L)),
    [8] = ACTION_LAYER_TAP_KEY(FN2_LAYER, KC_QUOT),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) 
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
            if(kanaFlag == 0){
                kanaFlag = 1;
                return MACRODOWN(TYPE(KC_A), END);
            } else {
                kanaFlag = 0;
                return MACRODOWN(TYPE(KC_B), END);
            }
        }
    return MACRO_NONE;
};

