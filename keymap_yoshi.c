#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  ADMIN,
  SMSPC1
};

enum {
  SFT_CAP = 0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,      KC_F12,
     KC_EQL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,        KC_MINS,
     KC_SCLN, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    OSM(MOD_LCTL), KC_ENT,
     KC_GRV,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_HOME,  KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,     KC_BSLS,
     KC_LALT, LT(_LOWER, KC_ESC), LSFT_T(KC_SPC),                        RSFT_T(KC_SPC),   LT(_RAISE, KC_TAB),   KC_RGUI

  ),

  [_LOWER] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
     _______, _______, S(KC_7), S(KC_8), _______, _______,                    _______, KC_7,    KC_8,    KC_9,    _______, _______,
     _______, _______, S(KC_4), S(KC_5), S(KC_6), _______,                    KC_DQT,  KC_4,    KC_5,    KC_6,    KC_QUOT, _______,
     _______, _______, S(KC_1), S(KC_2), S(KC_3), _______, _______,  _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,
     _______, _______, _______,                                               KC_BSPC, KC_0, _______
  ),

  [_RAISE] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
     _______, _______, KC_LBRC, KC_LCBR, KC_LPRN, _______,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_HOME, KC_END,
     _______, _______, KC_RBRC, KC_RCBR, KC_RPRN, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______,                                               _______, _______, _______
  ),

  [_ADJUST] = LAYOUT(
     _______, _______, _______,    _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     _______, _______, _______,    _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     _______, KC_SCLN, S(KC_SCLN), KC_QUOT, KC_DQT,  _______,                            _______, _______, _______, _______, _______, _______,
     _______, _______, _______,    _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______,                            _______, _______, _______
  )
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [SFT_CAP] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case ADMIN:
      if (record->event.pressed) {
        SEND_STRING("Administrator");
      }
      return false;
      break;
    case SMSPC1:
      if (record->event.pressed) {
        SEND_STRING("Simspace1!");
      }
      return false;
      break;
  }
  return true;
}

