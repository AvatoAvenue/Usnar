My personal configuration

code to replace if windows add colemak:

keymap.c

[_COLEMAK] = LAYOUT_planck_grid(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, TD(TD_PC), KC_MINUS,
        KC_BSPC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
        TD(TD_CAPLOCK), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_TAB,
        KC_LCTL, KC_LGUI, KC_MEH, KC_LALT, TT(_NUM), KC_SPC, TT(_NAV), TT(_SYM), KC_RALT, KC_MEH, KC_RSFT, TG(_GAME)
    ),

    [TD_PC] = ACTION_TAP_DANCE_DOUBLE(KC_P, LSFT(KC_P)),
