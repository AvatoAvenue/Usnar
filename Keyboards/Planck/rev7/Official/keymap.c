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
    _COLEMAKDH,
    _NAV,
    _NUM,
    _SYM,
    _GAME,
    _ADJUST
};

enum planck_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
    COLEMAKDH,
    GAME,
    NAV,
    SYM,
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

enum combos {
    COMBO_LESC,
    COMBO_RENTER,
    COMBO_RBSPC,
    COMBO_DELETE,
    COMBO_LQ,
    COMBO_RP,
    NUM_COMBOS
};

const uint16_t PROGMEM combo_df[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_jk[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_sd[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_kl[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_as[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM combo_lscn[] = {KC_L, KC_SCLN, COMBO_END};

const uint16_t tabctrl = LCTL_T(KC_TAB);
const uint16_t xalt = LALT_T(KC_X);
const uint16_t zralt = LCA_T(KC_Z);
const uint16_t dotalt = LALT_T(KC_DOT);
const uint16_t slshralt = LCA_T(KC_SLSH);

combo_t key_combos[NUM_COMBOS] = {
    [COMBO_LESC] = COMBO(combo_df, KC_ESC),
    [COMBO_RENTER] = COMBO(combo_jk, KC_ENTER),
    [COMBO_RBSPC] = COMBO(combo_sd, KC_BSPC),
    [COMBO_DELETE] = COMBO(combo_kl, KC_DELETE),
    [COMBO_LQ] = COMBO(combo_as, KC_Q),
    [COMBO_RP] = COMBO(combo_lscn, KC_P)
};

//LAYERS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    [_COLEMAK] = LAYOUT_planck_grid(
        KC_Q, KC_W, KC_E, KC_R, KC_B, XXXXXXX, XXXXXXX, KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_T, XXXXXXX, XXXXXXX, KC_M, KC_J, KC_K, KC_L, KC_SCLN,
        zralt, xalt, KC_C, KC_G, KC_V, XXXXXXX, XXXXXXX, KC_N, KC_H, KC_COMMA, dotalt, slshralt,
        XXXXXXX, XXXXXXX, MO(_NUM), tabctrl, KC_SPACE, XXXXXXX, XXXXXXX, KC_LSFT, MO(_NAV), MO(_SYM), XXXXXXX, XXXXXXX
    ),

    [_QWERTY] = LAYOUT_planck_grid(
        KC_Q, KC_W, KC_E, KC_R, KC_T, XXXXXXX, XXXXXXX, KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G, XXXXXXX, XXXXXXX, KC_H, KC_J, KC_K, KC_L, KC_SCLN,
        zralt, xalt, KC_C, KC_V, KC_B, XXXXXXX, XXXXXXX, KC_N, KC_M, KC_COMMA, dotalt, slshralt,
        XXXXXXX, XXXXXXX, MO(_NUM), tabctrl, KC_SPACE, XXXXXXX, XXXXXXX, KC_LSFT, MO(_NAV), MO(_SYM), XXXXXXX, XXXXXXX
    ),

    [_COLEMAKDH] = LAYOUT_planck_grid(
        KC_Q, KC_W, KC_F, KC_P, KC_B, XXXXXXX, XXXXXXX, KC_J, KC_L, KC_U, KC_Y, KC_SCLN,
        KC_A, KC_R, KC_S, KC_T, KC_G, XXXXXXX, XXXXXXX, KC_M, KC_N, KC_E, KC_I, KC_O,
        zralt, xalt, KC_C, KC_D, KC_V, XXXXXXX, XXXXXXX, KC_K, KC_H, KC_COMMA, dotalt, slshralt,
        XXXXXXX, XXXXXXX, MO(_NUM), tabctrl, KC_SPACE, XXXXXXX, XXXXXXX, KC_LSFT, MO(_NAV), MO(_SYM), XXXXXXX, XXXXXXX
    ),

    [_NUM] = LAYOUT_planck_grid(
        KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, XXXXXXX, XXXXXXX, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0,
        KC_0, KC_1, KC_2, KC_3, KC_4, XXXXXXX, XXXXXXX, KC_5, KC_6, KC_7, KC_8, KC_9,
        KC_MPRV, KC_MNXT, KC_MUTE, KC_MPLY, KC_VOLD, XXXXXXX, XXXXXXX, KC_VOLU, KC_NUM, KC_TAB, KC_ESC, KC_ENT,
        XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX
    ),

    [_NAV] = LAYOUT_planck_grid(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, XXXXXXX, XXXXXXX, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
        KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_F11, XXXXXXX, XXXXXXX, KC_F12, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_RALT, KC_MEH, XXXXXXX, XXXXXXX, KC_MEH, KC_RALT, KC_LALT, KC_LGUI, KC_LCTL,
        XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX
    ),

    [_SYM] = LAYOUT_planck_grid(
        KC_DLR, KC_AMPR, KC_PERC, KC_AT, KC_PIPE, XXXXXXX, XXXXXXX, KC_SLSH, KC_QUOT, KC_DQUO, KC_GRV, KCC_Dash,
        KC_ASTR, KC_MINS, KC_PLUS, KC_EQL, KC_LBRC, XXXXXXX, XXXXXXX, KC_RBRC, KC_LPRN, KC_RPRN, KC_EXLM, KC_QUES,
        KC_TILD, KC_CIRC, KC_BSLS, KC_HASH, KC_LT, XXXXXXX, XXXXXXX, KC_GT, KC_LCBR, KC_RCBR, KCC_InvE, KCC_InvQ,
        XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX
    ),

    [_GAME] = LAYOUT_planck_grid(
        KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MUTE,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_SPACE, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, TG(_GAME)
    ),

    [_ADJUST] = LAYOUT_planck_grid(
        _______, _______, _______, _______, KC_PWR, XXXXXXX, XXXXXXX, QK_BOOT, KC_DELETE, _______, _______, _______,
        KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, COLEMAKDH, XXXXXXX, XXXXXXX, COLEMAK, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_L,
        KC_BTN4, KC_BTN3, KC_BTN2, KC_BTN1, TG(_ADJUST), XXXXXXX, XXXXXXX, QWERTY, KC_MS_BTN5, KC_MS_BTN6, KC_MS_BTN7, KC_MS_BTN8,
        XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
        }
        return false;

        case COLEMAKDH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAKDH);
        }
        return false;

        case QWERTY:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
        }
        return false;

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

        default:
            return true;
    }
}

void set_rgb_color(layer_state_t state) {
    uint8_t active_layer = get_highest_layer(state);

    switch (active_layer) {
        case _NAV:
            rgblight_mode_noeeprom(base_mode);
            rgblight_sethsv_noeeprom(HSV_GREEN); //green
            break;
        case _SYM:
            rgblight_mode_noeeprom(base_mode);
            rgblight_sethsv_noeeprom(HSV_PURPLE); // Púrpura
            break;
        case _NUM:
            rgblight_mode_noeeprom(base_mode);
            rgblight_sethsv_noeeprom(HSV_GOLD); // Dorado
            break;
        case _GAME:
            rgblight_mode_noeeprom(base_mode);
            rgblight_setrgb(255, 215, 57); // Amarillo Avato
            break;
        case _ADJUST:
            rgblight_mode_noeeprom(lock_mode);
            rgblight_sethsv_noeeprom(HSV_CHARTREUSE); // Verde
            break;
        default:
            rgblight_mode_noeeprom(base_mode);
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv_noeeprom(HSV_RED);
            }
            break;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NUM, _SYM, _ADJUST);

    if ((state & (1UL << _NUM)) && (state & (1UL << _NAV))) {
        state ^= (1UL << _GAME);
    }

    static bool game_layer_active    = false;
    bool        new_game_layer_state = layer_state_cmp(state, _GAME);

    if (game_layer_active != new_game_layer_state) {
        game_layer_active = new_game_layer_state;
        tap_code16(LGUI(KC_SPACE));
        combo_toggle();
    }

    set_rgb_color(state);

    return state;
}

void matrix_scan_user(void) {
    static bool caps_lock_state = false;
    static bool shift_state = false;

    bool new_caps_lock_state = host_keyboard_led_state().caps_lock;
    bool new_shift_state = get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
    if (get_highest_layer(layer_state) != _GAME)
        {
        if (caps_lock_state != new_caps_lock_state || shift_state != new_shift_state) {
            caps_lock_state = new_caps_lock_state;
            shift_state = new_shift_state;
            if (caps_lock_state || shift_state) {
                rgblight_mode_noeeprom(base_mode);
                rgblight_sethsv_noeeprom(HSV_BLUE);
            } else {
                set_rgb_color(layer_state);
            }
        }
    }
}

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(HSV_RED);
  rgblight_mode_noeeprom(base_mode);
}

