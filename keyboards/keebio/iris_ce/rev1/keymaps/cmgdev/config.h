#pragma once

// activate Caps Word by double-tapping left shift
// This method works with KC_LSFT or one-shot Left Shift OSM(MOD_LSFT). 
// To count as a double tap, the maximum time in milliseconds between taps is TAPPING_TERM, or if using TAPPING_TERM_PER_KEY, the time returned by get_tapping_term() for the shift keycode being tapped
// source https://docs.qmk.fm/features/caps_word#how-do-i-enable-caps-word
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// This enables syncing of the layer state between both halves of the split keyboard. 
// The main purpose of this feature is to enable support for use of things like OLED display of the currently active layer.
// source https://docs.qmk.fm/features/split_keyboard#data-sync-options
#define SPLIT_LAYER_STATE_ENABLE