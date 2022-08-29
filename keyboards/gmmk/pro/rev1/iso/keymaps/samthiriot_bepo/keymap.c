/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
   Copyright 2022 gourdo1 <gourdo1@outlook.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "rgb_matrix_map.h"

#include "gourdo1.h"

#include <math.h>

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]                          PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "        #        Enter             PgDn
//      Sh_L     /        Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backspace. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [LAYER_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        LM(LAYER_CTRL,MOD_LCTL), KC_LGUI, LM(LAYER_ALT,MOD_LALT),                            KC_SPC,                             KC_RALT, MO(LAYER_FN),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [LAYER_FN] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_BTN1, KC_MS_U, KC_BTN2,
        _______, _______, _______,                            _______,                            _______, _______, KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R
    ),

    [LAYER_ALT] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    [LAYER_CTRL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),


};
// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
    return false;
}
#endif

#ifdef RGB_MATRIX_ENABLE

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    static uint32_t cycle_led_timer = 0;
    static uint8_t  current_value   = 0;
    static uint8_t  left_side_leds[8] = {68, 71, 74, 77, 81, 84, 88, 92};
    static uint8_t  right_side_leds[8] = {69, 72, 75, 78, 82, 85, 89, 93};

    // when caps lock is activated
    if (host_keyboard_led_state().caps_lock) {

        // light the CAPS LOCK touch
        rgb_matrix_set_color(LED_CAPS, RGB_WHITE);
        
        //  blink the side LED in red
        if (timer_elapsed32(cycle_led_timer) > 500) {
            current_value = current_value == 0 ? 255 : 0;
            cycle_led_timer = timer_read32();
        }
        HSV tempHSV = {.h = 0, .s = 255, .v = current_value};
        RGB tempRGB = hsv_to_rgb(tempHSV);
        for (uint8_t i = 0; i < sizeof(left_side_leds) / sizeof(left_side_leds[0]); i++) {
            rgb_matrix_set_color(left_side_leds[i], tempRGB.r, tempRGB.g, tempRGB.b);
            rgb_matrix_set_color(right_side_leds[i], tempRGB.r, tempRGB.g, tempRGB.b);
        }
    }

    // when FN is pushed, highlight in red the mapped keys
    switch(get_highest_layer(layer_state)){  // special handling per layer
       case LAYER_BASE:  //layer one
         break;
       case LAYER_FN:
         // highlight flashing 
         rgb_matrix_set_color(LED_BSPC, RGB_YELLOW);
         // highlight directional keys
         rgb_matrix_set_color(LED_UP,    RGB_CYAN);
         rgb_matrix_set_color(LED_DOWN,  RGB_CYAN);
         rgb_matrix_set_color(LED_LEFT,  RGB_CYAN);
         rgb_matrix_set_color(LED_RIGHT, RGB_CYAN);
         // highlight mouse keys
         rgb_matrix_set_color(LED_RSFT,  RGB_OFFBLUE);
         rgb_matrix_set_color(LED_END,   RGB_OFFBLUE);
         rgb_matrix_set_color(KC_BTN3,   RGB_OFFBLUE);
         break;
       case LAYER_ALT:
         rgb_matrix_set_color(LED_TAB,   RGB_WHITE);
         rgb_matrix_set_color(LED_F4,    RGB_WHITE);
         break;
       case LAYER_CTRL:
         // highlight ctrl C, ctrl V, ctrl Z...
         rgb_matrix_set_color(LED_Z,     RGB_WHITE);
         rgb_matrix_set_color(LED_X,     RGB_WHITE);
         rgb_matrix_set_color(LED_C,     RGB_WHITE);
         rgb_matrix_set_color(LED_A,     RGB_WHITE);
         rgb_matrix_set_color(LED_S,     RGB_WHITE);
         break;
       default:
         break;
       break;
    }
}

#endif
