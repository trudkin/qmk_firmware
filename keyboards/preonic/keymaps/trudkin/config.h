/* Copyright 2020 Terence Rudkin 
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


#define TAP_CODE_DELAY 5

#define COMBO_COUNT 8
#define COMBO_TERM 600

#define USE_CUA
#define CUA_MOD MOD_BIT(KC_LCTRL)

#define RGBLIGHT_LIMIT_VAL 255


#define COMBO_ALLOW_ACTION_KEYS

#define PERMISSIVE_HOLD

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define RGBLIGHT_LAYER_BLINK
#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  
#define TAPPING_TERM 200 
//#define TAPPING_TERM_PER_KEY

/*#define RETRO_TAPPING*/ 

#define TAPPING_TOGGLE 2 
#define RGBLIGHT_LAYERS 

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 450

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(GOOD_EATS)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(COLEMAK_SOUND), \
                                  SONG(QWERTY_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif
#define AUDIO_CLICKY
#define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

#define LAYER_STATE_8BIT 
