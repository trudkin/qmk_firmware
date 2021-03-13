/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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
enum layout_names {
    _MEDIA,
    _NAV,
    _MOUSE,
    _FUNCTION,
    _RGB,

};

enum encoder_names {
  _MIDDLE, 
  _RIGHT,
  _LEFT,
};

enum td_names {
    F1_4,
    F2_5,
    F3_6,
    F10_7,
    F11_8,
    F12_9, 
    UP_PGUP,
    DN_PGDN,
    LT_HOME,
    RT_END,
    TD_MSE,
    TD_NAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |      | Knob 2: Page Dn/Up |
        | Press: Mute       | Home | Press: Play/Pause  |
        | Hold: Layer 2     | Up   | RGB Mode           |
        | Left              | Down | Right              |
     */
    [_MEDIA] = LAYOUT(
        TD(TD_NAV), LT(_FUNCTION, KC_HOME), TD(TD_MSE),
        MO(_RGB)  , KC_UP  , RGB_MOD,
        KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /*
        | RESET          | N/A  | Media Stop |
        | Held: Layer 2  | Home | RGB Mode   |
        | Media Previous | End  | Media Next |
     */
//  [_RGB] = LAYOUT(
//      RESET  , BL_STEP, KC_STOP,
//      _______, KC_HOME, RGB_MOD,
//      KC_MPRV, KC_END , KC_MNXT
//  ),
    /*
        | RESET          | N/A  | Media Stop |
        | Held: Layer 2  | Home | RGB Mode   |
        | Media Previous | End  | Media Next |
     */
    [_FUNCTION] = LAYOUT(
        RESET  , _______, KC_STOP,   
        TD(F1_4), TD(F2_5), TD(F3_6),
        TD(F10_7), TD(F11_8), TD(F12_9)
    ),

    [_MOUSE] = LAYOUT(
        _______, KC_MS_U, TG(_MOUSE),
        KC_MS_L, KC_MS_D, KC_MS_R,
        KC_BTN1, KC_BTN3, KC_BTN2),

     [_NAV] = LAYOUT(
        TG(_NAV), TD(UP_PGUP), _______,
        TD(LT_HOME), TD(DN_PGDN), TD(RT_END),
        C(KC_ESC), S(KC_ESC), A(KC_TAB)),
};



qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [F1_4] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F4),
    [F2_5] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F5),
    [F3_6] = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_F6),
    [F10_7] = ACTION_TAP_DANCE_DOUBLE(KC_F10, KC_F7),
    [F11_8] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_F8),
    [F12_9] = ACTION_TAP_DANCE_DOUBLE(KC_F12, KC_F9),
    [UP_PGUP] = ACTION_TAP_DANCE_DOUBLE(KC_UP,KC_PGUP),
    [DN_PGDN] = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_PGDN),
    [LT_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_HOME),
    [RT_END]  = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT, KC_END),
    [TD_MSE] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_MPLY,_MOUSE),
    [TD_NAV] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_MUTE,_NAV),
};

#define NXT_TAB   LALT(KC_TAB)         // Next Tab (Control-Tab)
#define PRV_TAB   LSFT(LALT(KC_TAB))   // Previous Tab (Shift-Control-Tab)

const uint16_t PROGMEM encoders[][2][2] = {
//  [_REEDER] = {{ KC_K, KC_J }, { KC_P, KC_N }},

/***                      Left                    Right          */
/*                  CCW        CW           CCW      CW          */
  [_MEDIA]     = {{ KC_VOLD, KC_VOLU }, { KC_MPRV, KC_MNXT }},
  [_NAV]       = {{ KC_WH_D, KC_WH_U }, { PRV_TAB, NXT_TAB }},
  [_FUNCTION]  = {{ NXT_TAB, PRV_TAB }, { C(KC_W), C(S(KC_T)) }},
  [_MOUSE]     = {{ KC_MS_L, KC_MS_R, }, {  KC_MS_D, KC_MS_U }},
//  [LR_REVIEW] = {{ KC_LBRC, KC_RBRC }, { G(KC_DOWN), G(KC_UP) }},
//  [LR_EDIT] = {{ KC_COMM, KC_DOT }, { KC_MINS, KC_EQL }},
};



void encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t layer = get_highest_layer(layer_state);
    uint8_t idx = index %2; 

    switch (layer) {
    case  _RGB:
        if (index == _LEFT) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
        else if (index == _RIGHT) {
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        }
        break;
    default:
        tap_code16(pgm_read_word(&encoders[layer][idx][clockwise]));
        break;
    }

}


#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _MEDIA:
            oled_write_P(PSTR("Media\n"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("FUNCTION\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case _RGB:
            oled_write_P(PSTR("RGB\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
//  led_t led_state = host_keyboard_led_state();
//  oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
//  oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
//  oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif
