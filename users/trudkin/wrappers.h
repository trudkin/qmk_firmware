/* Copyright 2020 Terence Rudkin with a lot of insperation  from drashna
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
#pragma once

/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

// clang-format off
#define LAYOUT_ergodox_wrapper(...)          LAYOUT_ergodox(__VA_ARGS__)
#define LAYOUT_ergodox_pretty_wrapper(...)   LAYOUT_ergodox_pretty(__VA_ARGS__)
#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x12_wrapper(...)       LAYOUT_ortho_5x12(__VA_ARGS__)
#define LAYOUT_gergo_wrapper(...)            LAYOUT_gergo(__VA_ARGS__)

/*
Blocks for each of three major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    MY_X,    MY_C,    MY_V,    MY_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________COLEMAK_L1________________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________       KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________       KC_Z,    MY_X,    MY_C,    MY_V,    MY_B

#define _________________COLEMAK_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________       KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAK_R3________________       MY_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define ________________COLEMAKD_L1________________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ________________COLEMAKD_L2________________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ________________COLEMAKD_L3________________       KC_Z,    MY_X,    MY_C,    MY_D,    MY_V

#define ________________COLEMAKD_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ________________COLEMAKD_R2________________       KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define ________________COLEMAKD_R3________________       MY_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________DVORAK_L1_________________        KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y
#define _________________DVORAK_L2_________________        KC_A,    KC_O,    KC_E,   KC_U,     KC_I
#define _________________DVORAK_L3_________________        KC_SCLN, KC_Q,    KC_J,   KC_K,     MY_X

#define _________________DVORAK_R1_________________        KC_F,    KC_G,    MY_C,    KC_R,    KC_L
#define _________________DVORAK_R2_________________        KC_D,    KC_H,    KC_T,    KC_N,    KC_S
#define _________________DVORAK_R3_________________        MY_B,    KC_M,    KC_W,    MY_V,    KC_Z


#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _____________MY_NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    MY_9,    MY_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define ___________________BLANK___________________        _______, _______, _______, _______, _______
#define _______________CONTROL_KEYS_2______________        LCTL(KC_A),_______, _______, _______,LCTL(KC_D)
#define _______________CONTROL_KEYS_3______________        LCTL(KC_Z),RSFT(KC_DEL),RCTL(KC_INS),RSFT(KC_INS),RCTL(KC_B)




#define _________________LOWER_L1__________________        _________________FUNC_LEFT_________________
#define _________________LOWER_L2__________________        _______________CONTROL_KEYS_2______________
#define _________________LOWER_L3__________________        _______________CONTROL_KEYS_3______________

#define _________________LOWER_R1__________________        _________________FUNC_RIGHT________________
#define _________________LOWER_R2__________________        _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR
#define _________________LOWER_R3__________________        LSFT(KC_NUHS), LSFT(KC_NUBS), KC_LT, KC_GT, KC_PGUP 



#define _________________RAISE_L1__________________        ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________        _______________CONTROL_KEYS_2______________
#define _________________RAISE_L3__________________        _______________CONTROL_KEYS_3______________

#define _________________RAISE_R1__________________        ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________        _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC
#define _________________RAISE_R3__________________        _______, _______, KC_MPRV, KC_MNXT, KC_VOLU



#define _________________ADJUST_L1_________________        QWERTY, COLEMAK, DVORAK,  KC_PSCR, KC_NLCK
#define _________________ADJUST_L2_________________        RESET, DEBUG,  TERM_ON, TERM_OFF, CK_TOGG
#define _________________ADJUST_L3_________________        CMB_ON, MU_MOD, AU_ON, AU_OFF, AG_NORM     
#define _________________ADJUST_L4_________________        MUV_DE, MUV_IN, MU_ON, MU_OFF, AG_SWAP     

#define _________________ADJUST_R1_________________        RGB_SPI, RGB_SPD, RGB_MOD, RGB_RMOD, RGB_TOG
#define _________________ADJUST_R2_________________        RGB_VAI, RGB_VAD, RGB_M_R, RGB_M_P,  RGB_M_B
#define _________________ADJUST_R3_________________        RGB_HUI, RGB_HUD, RGB_M_K, RGB_M_SW, RGB_M_SN
#define _________________ADJUST_R4_________________        RGB_SAI, RGB_SAD, RGB_M_T, RGB_M_X,  RGB_M_G

#define _________________MOD_LEFT__________________         LCTL_T(KC_LBRC),  MY_LGUI, LALT_T(KC_RBRC),KC_MINS, MY_LOW
#define _________________MOD_RIGHT_________________         MY_RAI, KC_EQL, RALT_T(KC_LEFT), RGUI_T(KC_DOWN), RCTL_T(KC_RGHT)


/*                                                                  place key to this layer here \/ */
#define _________________NUMPAD_1__________________         KC_NLCK, KC_P7,   KC_P8,   KC_P9,  NUMPAD
#define _________________NUMPAD_2__________________         KC_PSLS, KC_P4,   KC_P5,   KC_P6,  KC_PAST
#define _________________NUMPAD_3__________________         KC_PMNS, KC_P1,   KC_P2,   KC_P3,  KC_PPLS
#define _______NUMPAD_4________                             KC_PENT, KC_P0, KC_PDOT
#define _________________NUMPAD_4__________________         KC_LPRN, _______NUMPAD_4________, KC_RPRN

#define _________________MOUSE_1___________________         KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, _______
#define _________________MOUSE_2___________________         KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______
#define _________________MOUSE_3___________________         KC_BTN1, KC_BTN3, KC_BTN2, _______, _______
// clang-format on










