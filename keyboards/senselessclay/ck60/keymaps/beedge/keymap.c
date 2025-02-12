/* Copyright 2020 Hadi Iskandarani
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Tap dance declarations
enum {
    TC_UP_QUESTION
};

// Tap dance defination
qk_tap_dance_action_t tap_dance_actions[] = {
    [TC_UP_QUESTION] = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_QUESTION),
};

enum layers {
    _0,
    _1,
    _2,
    _3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_0] = LAYOUT_60_iso(
        /*Base*/
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  TD(TC_UP_QUESTION), KC_RSFT,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_LEFT, KC_DOWN, KC_RGHT, MO(1)
    ),
    [_1] = LAYOUT_60_iso(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        RGB_HUI, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   _______,
        RGB_HUD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_INS,  KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______, _______,
        RGB_VAI, KC_VOLD, _______, _______, _______, _______, _______, _______, KC_DEL,  KC_END,  KC_PGDN, KC_SLSH,          _______,
        RGB_VAD, RGB_M_B, RGB_M_P,                            _______,                            _______, _______, _______, _______
    ),
    [_2] = LAYOUT_60_iso(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),
    [_3] = LAYOUT_60_iso(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    )
};

// Custom LED setup
void rgb_matrix_indicators_user(void)
{
    HSV hsv = { 0, 255, 255 };
    if(hsv.v > rgb_matrix_get_val())
    {
            hsv.v = rgb_matrix_get_val();
    }
    RGB rgb = hsv_to_rgb(hsv);
 	if (host_keyboard_led_state().caps_lock)
	{
		rgb_matrix_set_color(28, rgb.r, rgb.g, rgb.b);
	}
	if (IS_LAYER_ON(_0))
	{
		rgb_matrix_set_color(42, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(58, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(59, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(60, rgb.r, rgb.g, rgb.b);
	}
	if (IS_LAYER_ON(_1))
	{
		rgb_matrix_set_color(42, RGB_RED);
        rgb_matrix_set_color(53, RGB_RED);
        rgb_matrix_set_color(54, RGB_RED);
        rgb_matrix_set_color(29, RGB_YELLOW);
        rgb_matrix_set_color(52, RGB_YELLOW);
        rgb_matrix_set_color(27, RGB_PURPLE);
        rgb_matrix_set_color(28, RGB_PURPLE);
	}
}
