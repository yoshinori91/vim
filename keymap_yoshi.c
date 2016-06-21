#include "planck.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   TAB   |  Q  |  W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -  |
 * |---------+-----+-----+------+------+-------------+------+------+------+------+-----|
 * | OSM_Ctl |  A  |  S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '  | 
 * |---------+-----+-----+------+------+------+------+------+------+------+------+-----|
 * | OSM_Alt |  Z  |  X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | ENT |
 * |---------+-----+-----+------+------+------+------+------+------+------+------+-----|
 * | GUI     | Ctl | Alt | BSPC | Lower|  OSM(LSFT)  |Raise | Left | Down |  Up  |Right|
 * `-----------------------------------------------------------------------------------'
 */
[0] = {
  {KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,          KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_MINS},
  {OSM(MOD_LCTL), KC_A,    KC_S,    KC_D,    KC_F,   KC_G,          KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {OSM(MOD_LALT), KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,          KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LGUI,       KC_LCTL, KC_LALT, KC_BSPC, OSL(1), OSM(MOD_LSFT), _______, OSL(2), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
 * ,-------------------------------------------------------------------------.
 * |   `  |  ~  |  &  |  *  |  (  |  )  |     |  7  |  8  |  9  |   [  |  ]  |
 * |------+-----+-----+-----+-----+-----------+-----+-----+-----+-----+------|
 * |   =  |  +  |  $  |  %  |  ^  |     |     |  4  |  5  |  6  |   { |   }  |
 * |------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+------|
 * |      |     |  !  |  @  |  #  |     |     |  1  |  2  |  3  |     |      |
 * |------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+------|
 * |Reset |     |     |     |     |           |  0  |     |     |     |      |
 * `-------------------------------------------------------------------------'
 */
[1] = {
  {KC_GRV,  KC_TILD, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, KC_7, KC_8,    KC_9,    KC_LBRC, KC_RBRC},
  {_______, _______, KC_DLR,  KC_PERC, KC_CIRC, KC_EQL,  KC_PLUS, KC_4, KC_5,    KC_6,    KC_LCBR, KC_RCBR},
  {_______, _______, KC_EXLM, KC_AT,   KC_HASH, _______, KC_F12,  KC_1, KC_2,    KC_3,    _______, _______},
  {RESET,   _______, _______, _______, _______, KC_SPC,  _______, KC_0, _______, _______, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Del  |  F9  |  F10 |  F11 |  F12 |      |      | Home |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |  F5  |  F6  |  F7  |  F8  |      | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      |      | End  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[2] = {
  {KC_DEL,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  _______, KC_HOME, _______, _______, _______, _______},
  {KC_ESC,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,  _______, KC_END,  _______, _______, _______, _______},
  {RESET,   _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______}
},


};

const uint16_t PROGMEM fn_actions[] = {

}; const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
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
