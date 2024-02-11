
#include QMK_KEYBOARD_H

enum planck_layers {
    _COLEMAK,
    _NAV,
    _NUM,
    _SYM,
    _ADJUST,
    _GAME,
    _GAMEZ
};

enum planck_keycodes {
    COLEMAK = SAFE_RANGE,
    GAME,
    GAMEZ,
    NAV,
    SYM,
    NUM,
    ADJUST
};

// Clear layering
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum {
    TD_PC,
    TD_CAPLOCK
};

#ifdef AUDIO_ENABLE
    float start_Song[][2] = SONG(Castle_Vein_ultrakill);
    float game_Song[][2] = SONG(E1M1_DOOM);
    #define STARTUP_SONG SONG(start_Song)
#endif

//LAYERS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{

    [_COLEMAK] = LAYOUT_planck_grid(
        KC_ESC, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, TD(TD_PC), KC_MINS,
        KC_TAB, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_BSPC,
        TD(TD_CAPLOCK), KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_MEH, TT(_NUM), KC_SPC, TT(_NAV), MO(_SYM), KC_RALT, TO(_GAME), KC_HYPR, KC_ENT
    ),

    [_NUM] = LAYOUT_planck_grid(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, TT(_NUM), _______, TT(_NAV), MO(_SYM), _______, _______, _______, _______
    ),
    
    [_NAV] = LAYOUT_planck_grid(
        _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______,
        _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_PSCR, KC_INS, KC_HOME, KC_END, KC_PGUP, KC_PGDN, KC_DEL,
        KC_LSFT, KC_P4, KC_P2, KC_P8, KC_P6, KC_P7, KC_P9, KC_P5, KC_P1, KC_P3, KC_P0, _______,
        KC_LCTL, KC_LGUI, KC_LALT, _______, TT(_NUM), _______, TT(_NAV), MO(_SYM), KC_MPLY, KC_MUTE, KC_MPRV, KC_MNXT
    ),
    
    [_SYM] = LAYOUT_planck_grid(
        _______, KC_EXLM, KC_QUES, KC_GRV, KC_TILD, _______, _______, KC_DQUO, KC_HASH, KC_UNDS, KC_AMPR, _______,
        _______, KC_ASTR, KC_MINS, KC_PLUS, KC_EQL, KC_LT, KC_GT, KC_QUOT, KC_LPRN, KC_LCBR, KC_LBRC, _______,
        _______, KC_AT, KC_PERC, KC_CIRC, KC_SLSH, KC_DLR, KC_PIPE, KC_BSLS, KC_RPRN, KC_RCBR, KC_RBRC, _______,
        _______, _______, _______, _______, TT(_NUM), _______, TT(_NAV), MO(_SYM), _______, _______, _______, _______
    ),

    [_GAME] = LAYOUT_planck_grid(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ENT,
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_N, KC_LGUI,
        KC_LCTL, KC_Z, KC_LALT, KC_X, KC_C, KC_SPC, KC_V, MO(_GAMEZ), KC_B, TO(_COLEMAK), KC_M, KC_MUTE
    ),

    [_GAMEZ] = LAYOUT_planck_grid(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_PSCR,
        _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, _______, _______, KC_F11, KC_F12, _______,
        _______, KC_P4, KC_P2, KC_P8, KC_P6, KC_P7, KC_P9, KC_P5, KC_P1, KC_P3, KC_P0, _______,
        _______, _______, _______, _______, _______, _______, _______, MO(_GAMEZ), _______, _______, KC_MUTE, KC_MPLY
    ),

    [_ADJUST] = LAYOUT_planck_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        XXXXXXX, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, RGB_TOG, AU_TOGG, KC_MPLY, KC_MUTE, KC_MPRV, KC_MNXT, XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_PC] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_SCLN)),
    [TD_CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};

// Double touch to third layer
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NUM, _SYM, _ADJUST);
}

bool rgb_matrix_indicators_user(void) {
    uint8_t current_layer = get_highest_layer(layer_state);
    switch (current_layer) {
        case _NAV:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_set_color_all(57,255,214); //cyan
        break;

        case _SYM:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_set_color_all(144,75,232); //purple
        break;

        case _NUM:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_set_color_all(144,75,232); //purple
        break;

        case _GAME:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_set_color_all(255, 214, 57); //avato yellow
        break;

        case _GAMEZ:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_set_color_all(207,57,255); //purple
        break;

        case _ADJUST:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
        rgb_matrix_set_color_all(255,0,0); //red
        break;

        default:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_OUT_IN);
            rgb_matrix_set_color_all(179, 27, 27); //avato red
            break;
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TO(_GAME):
      if (record->event.pressed) {
        if (layer_state_is(_GAME)) {
            #ifdef AUDIO_ENABLE
            PLAY_SONG(game_Song);
            #endif
        }
      }
      return false;
    default:
      return true;
  }
}