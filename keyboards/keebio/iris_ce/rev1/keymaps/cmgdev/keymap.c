// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "action_layer.h"
#include "caps_word.h"
#include "color.h"
#include "rgb_matrix.h"
#include QMK_KEYBOARD_H

enum custom_layers {
     _QWERTY,
     _LOWER,
     _RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME,          KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, TL_LOWR, KC_ENT,                    KC_SPC,  TL_UPPR, KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PGUP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  _______, KC_UP,   _______, QK_BOOT, _______,                            _______, KC_7,    KC_8,     KC_9,    KC_0,   KC_PGDN,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_LBRC,                            KC_RBRC, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RM_NEXT, EE_CLR,  _______, _______, _______, KC_LCBR, KC_LPRN,          KC_RPRN, KC_RCBR, KC_1,    KC_2,    KC_3,    KC_MINS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                    KC_DEL,  _______, KC_0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RM_TOGG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RM_NEXT, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RM_HUEU, RM_SATU, RM_VALU, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RM_HUED, RM_SATD, RM_VALD, EE_CLR,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

void keyboard_post_init_user(void) {
   // Customise these values to desired behaviour
   debug_enable=true;
   debug_matrix=true;
   //debug_keyboard=true;
   //debug_mouse=true;


   rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
   rgb_matrix_sethsv_noeeprom(HSV_CYAN);
}

layer_state_t last_state = _QWERTY;

bool rgb_matrix_indicators_user(void) {
    layer_state_t l_state = get_highest_layer(layer_state | default_layer_state);
    if (last_state != l_state) {
        switch (l_state) {
            case _QWERTY:
                rgb_matrix_sethsv_noeeprom(HSV_CYAN);
                break;
            case _LOWER:
                rgb_matrix_sethsv_noeeprom(HSV_YELLOW);
                break;
            case _RAISE:
                rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
                break;
            default:
                break;
        }
        last_state = l_state;
    }
    return false;
}

void set_leds(const int *leds, int size, int red, int green, int blue) {
    for (int i = 0; i < size; i++) {
        rgb_matrix_set_color(leds[i], red, green, blue);
    }
}

const int left_shift_key = 26;
const int lower_layer_boot_key = 10;
const int raise_layer_boot_key = 48;
const int wasd_leds[] = {12, 16, 17, 18};
const int wasd_leds_size = sizeof(wasd_leds) / sizeof(wasd_leds[0]);  // wasd_leds_size is the number of bytes in wasd_leds, not the number of elements.
const int num_pad_leds[] = {44, 45, 46, 47, 53, 52, 51, 56, 57, 58};
const int num_pad_leds_size = sizeof(num_pad_leds) / sizeof(num_pad_leds[0]);

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (is_caps_word_on()) {
        rgb_matrix_set_color(left_shift_key, RGB_GREEN);
    }

    switch (get_highest_layer(layer_state | default_layer_state)) {
      case _LOWER:

         // set the wasd arrow keys to magenta
         set_leds(wasd_leds, wasd_leds_size, RGB_MAGENTA);

         // set the boot key to red
         rgb_matrix_set_color(lower_layer_boot_key, RGB_RED);

         // set the num pad to azure
         set_leds(num_pad_leds, num_pad_leds_size, RGB_AZURE);

         break;
      case _RAISE:
         
         // set the boot key to red
         rgb_matrix_set_color(raise_layer_boot_key, RGB_RED);
         
         break;
      default:
         break;
    }
                
    return true;
}