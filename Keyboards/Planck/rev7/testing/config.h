#pragma once

// dead keys
#define NO_ACTION_ONESHOT

#define NO_MUSIC_MODE

// #define LAYER_STATE_8BIT
#define LAYER_STATE_16BIT

#define TAPPING_TOGGLE 2
#define TAPPING_TERM 150

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(Castle_Vein_ultrakill)
#endif

#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

#define RGBLIGHT_LIMIT_VAL 100

#define RGBLIGHT_SLEEP
#define RGBLIGHT_EFFECT_BREATHING
