#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
    float game_Song[][2] = SONG(E1M1_DOOM);
#endif

#ifdef RGBLIGHT_ENABLE
    uint32_t base_mode = RGBLIGHT_MODE_STATIC_LIGHT;
    uint32_t lock_mode = RGBLIGHT_MODE_BREATHING + 3;
#endif


enum planck_layers {
    _COLEMAK,
    _QWERTY,
    _COLEMAKWND,
    _FUNCZ,
    _NAV,
    _NUM,
    _SYM,
    _ADJUST,
    _GAME,
    _GAMEZ
};

enum planck_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
    COLEMAKWND,
    GAME,
    GAMEZ,
    NAV,
    SYM,
    NUM,
    FUNCZ,
    ADJUST,
    KCC_InvQ,
    KCC_InvE,
    KCC_Dash
};

// Clear layering
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// rgb usb control
#ifdef RGBLIGHT_ENABLE
// suspend rgb
void suspend_power_down_user(void) {
    // Apaga las luces RGB
    rgblight_disable_noeeprom();
    #ifdef AUDIO_ENABLE
        stop_all_notes();
    #endif
}

//wakeup rgb
void suspend_wakeup_init_user(void) {
    rgblight_enable_noeeprom();
}
#endif

//LAYERS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    [_COLEMAK] = LAYOUT_planck_grid(
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_MINUS,
        KC_BSPC, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_ESC,
        KC_LCTL, KC_LGUI, KC_MEH, KC_LALT, TT(_NUM), KC_SPC, TT(_NAV),  TT(_SYM), KC_RALT, KC_MEH, KC_CAPS, TG(_GAME)
    ),

    [_QWERTY] = LAYOUT_planck_grid(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS,
        KC_BSPC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC,
        KC_LCTL, KC_LGUI, KC_MEH, KC_LALT, TT(_NUM), KC_SPC, TT(_NAV),  TT(_SYM), KC_RALT, KC_MEH, KC_CAPS, TG(_GAME)
    ),

    [_COLEMAKWND] = LAYOUT_planck_grid(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_B, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS,
        KC_BSPC, KC_A, KC_S, KC_D, KC_F, KC_T, KC_M, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_G, KC_V, KC_N, KC_H, KC_COMMA, KC_DOT, KC_SLASH, KC_ESC,
        KC_LCTL, KC_LGUI, KC_MEH, KC_LALT, TT(_NUM), KC_SPC, TT(_NAV),  TT(_SYM), KC_RALT, KC_MEH, KC_CAPS, TG(_GAME)
    ),

    [_NUM] = LAYOUT_planck_grid(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,
        KC_BSPC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DELETE,
        _______, KC_F11, KC_APP, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_FIND, KC_F12, _______,
        _______, _______, _______, _______, TT(_NUM), _______, TT(_NAV), TT(_SYM), _______, _______, _______, _______
    ),

    [_NAV] = LAYOUT_planck_grid(
        _______, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, _______,
        KC_BSPC, KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_PSCR, KC_INS,KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_DEL,
        KC_LSFT, KC_P4, KC_P2, KC_P8, KC_P6, KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE, KC_MPRV, KC_MNXT, _______,
        KC_LCTL, KC_LGUI, KC_LALT, _______, TT(_NUM), _______, TT(_NAV), TT(_SYM), _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT_planck_grid(
        _______, KC_DLR, KC_AMPR, KC_PERC, KC_AT, KC_PIPE, KC_SLSH, KC_QUOT, KC_DQUO, KC_EXLM, KCC_Dash, _______,
        _______, KC_ASTR, KC_MINS, KC_PLUS, KC_EQL, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_EXLM, KC_QUES, KC_DEL,
        _______, KC_TILD, KC_CIRC, KC_BSLS, KC_HASH, KC_LT, KC_GT, KC_LCBR, KC_RCBR, KCC_InvE, KCC_InvQ, _______,
        _______, _______, _______, _______, TT(_NUM), _______, TT(_NAV), TT(_SYM), _______, _______, _______, _______
    ),

    [_GAME] = LAYOUT_planck_grid(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MUTE,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_B, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ENTER,
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_T, KC_M, KC_J, KC_K, KC_L, KC_SCLN, TG(_GAMEZ),
        KC_LCTL, KC_Z, KC_X, KC_C, KC_G, KC_SPC, KC_V, MO(_GAMEZ), KC_N, KC_H, KC_COMMA, TG(_GAME)
    ),

    [_GAMEZ] = LAYOUT_planck_grid(
        KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        _______, _______, _______, KC_UP, _______, _______, _______, KC_COMMA, KC_DOT, KC_SLASH, _______, _______,
        _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, _______, TG(_GAMEZ),
        _______, _______, _______, _______, _______, _______, _______, MO(_GAMEZ), KC_MUTE, KC_MPLY, KC_PSCR, KC_LALT
    ),

    [_FUNCZ] = LAYOUT_planck_grid(
        _______, _______, _______, COLEMAKWND, COLEMAK, _______, _______, COLEMAK, QWERTY, _______, _______, _______,
        _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_L, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_DELETE,
        _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, _______, _______, KC_MS_BTN5, KC_MS_BTN6, KC_MS_BTN7, KC_MS_BTN8, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT_planck_grid(
        KC_PWR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        XXXXXXX, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, RGB_TOG, AU_TOGG, KC_MPLY, KC_MUTE, KC_MPRV, KC_MNXT, XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, COLEMAKWND, COLEMAK, QWERTY, FUNCZ, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

static layer_state_t previous_state = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KCC_InvQ: // ¿ inverted question
            if (record->event.pressed) {
                register_code(KC_RALT);
                tap_code(KC_SLSH);
                unregister_code(KC_RALT);
            }
            return false;

        case KCC_InvE: // ¡ inverted exclamation
            if (record->event.pressed) {
                register_code(KC_RALT);
                tap_code(KC_1);
                unregister_code(KC_RALT);
            }
            return false;

        case KCC_Dash: // — dash
            if (record->event.pressed) {
                register_code(KC_RALT);
                register_code(KC_LSFT);
                tap_code(KC_MINS);
                unregister_code(KC_LSFT);
                unregister_code(KC_RALT);
            }
            return false;

        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;

        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;

        case COLEMAKWND:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAKWND);
            }
            return false;

        case FUNCZ:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_FUNCZ);
            }
            return false;

        default:
            return true;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NUM, _SYM, _ADJUST);

    switch (get_highest_layer(state)) {
        case _NAV:
        rgblight_mode_noeeprom(base_mode);
        rgblight_sethsv_noeeprom(HSV_CYAN); //cyan
        break;

        case _SYM:
        rgblight_mode_noeeprom(base_mode);
        rgblight_sethsv_noeeprom(HSV_PURPLE); //purple
        break;

        case _NUM:
        rgblight_mode_noeeprom(base_mode);
        rgblight_sethsv_noeeprom(HSV_GOLD); //gold
        break;

        case _GAME:
        rgblight_mode_noeeprom(base_mode);
        rgblight_setrgb(255, 215, 57); //avato yellow
        #ifdef AUDIO_ENABLE
        if (previous_state != _GAMEZ) {
            PLAY_SONG(game_Song);
        }
        else {
        stop_all_notes();
        }
        #endif
        break;

        case _GAMEZ:
        rgblight_mode_noeeprom(base_mode);
        rgblight_sethsv_noeeprom(HSV_PURPLE); //purple
        break;

        case _ADJUST:
        rgblight_mode_noeeprom(lock_mode);
        rgblight_sethsv_noeeprom(HSV_RED);
        break;

        default:
        rgblight_mode_noeeprom(base_mode);
        if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv_noeeprom(HSV_RED);
            }
        break;
}
    previous_state = get_highest_layer(state);
    return state;
}

void matrix_scan_user(void) {

    static bool caps_lock_state = false;
    bool new_caps_lock_state = host_keyboard_led_state().caps_lock;

    if (caps_lock_state != new_caps_lock_state) {
        caps_lock_state = new_caps_lock_state;

        if (caps_lock_state) {
            rgblight_mode_noeeprom(base_mode);
            rgblight_sethsv_noeeprom(HSV_BLUE);
        } else {
            rgblight_mode_noeeprom(base_mode);
            rgblight_sethsv_noeeprom(HSV_RED);
        }
    }
}


void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(HSV_RED);
  rgblight_mode_noeeprom(base_mode);
}
