#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

enum layers {
    _BL,  // base (blank/lock)
    _DL,  // dvorak-ish base
    _QL,  // qwerty
    _SL,  // symbols/numbers
    _NL,  // navigation
    _FL,  // function/media
    _CL,  // config (rgb/boot)
};

// shorthand so the layer grids stay narrow
#define COPY    LCTL(KC_C)
#define PASTE   RCTL(KC_V)
#define CTL_BSP LCTL_T(KC_BSPC)
#define ALT_LBR LALT_T(KC_LBRC)
#define ALT_QUO LALT_T(KC_QUOT)
#define CTL_MIN RCTL_T(KC_MINS)
#define GUI_EQL LGUI_T(KC_EQL)
#define GUI_DEL RGUI_T(KC_DEL)
#define SL_Z    LT(_SL, KC_Z)
#define SL_J    LT(_SL, KC_J)
#define NL_SPC  LT(_NL, KC_SPC)
#define WM_H    LGUI(KC_H)
#define WM_T    LGUI(KC_T)
#define WM_N    LGUI(KC_N)
#define WM_S    LGUI(KC_S)
#define WMS_H   LSG(KC_H)
#define WMS_T   LSG(KC_T)
#define WMS_N   LSG(KC_N)
#define WMS_S   LSG(KC_S)
#define GUI_LFT LGUI(KC_LEFT)
#define SFT_RGT LSFT(KC_RGHT)
#define CTL_LFT LCTL(KC_LEFT)
#define CTL_RGT LCTL(KC_RGHT)
#define BTICK   LSFT(KC_GRAVE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT_65_ansi_blocker(
        TO(_QL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            TO(_DL),                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_DL] = LAYOUT_65_ansi_blocker(
        KC_K,    KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_TILD,    KC_G,    KC_C,    KC_R,    KC_X,    KC_LCBR, KC_DQUO, KC_BSPC, KC_HOME,
        QK_GESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_F,       KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_UNDS, KC_PIPE, KC_PGUP,
        QK_AREP, KC_TAB,  KC_Q,    KC_SLSH, KC_COLN, KC_L,    KC_AMPR,    KC_M,    KC_W,    KC_B,    KC_V,    KC_LT,   KC_ENT,           KC_PGDN,
        COPY,    KC_PERC, CTL_BSP, SC_LSPO, ALT_LBR, KC_EXLM, ALT_QUO,    SC_SENT, CTL_MIN, KC_HASH, KC_QUES, PASTE,            KC_UP,   OSL(_FL),
        CW_TOGG, SL_Z,    GUI_EQL,                            NL_SPC,                             GUI_DEL, SL_J,    KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_QL] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, TO(_BL),
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_AT,
        COPY,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           PASTE,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   OSL(_FL),
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_SL] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, BTICK,   KC_GT,   _______, _______, _______, KC_4,    KC_3,    KC_6,    KC_DOT,  _______, _______, _______,
        _______, KC_ASTR, KC_RBRC, KC_CIRC, KC_DLR,  _______, _______, _______, KC_1,    KC_0,    KC_5,    KC_9,    _______, _______, _______,
        _______, KC_RPRN, KC_RCBR, KC_HASH, KC_AT,   _______, _______, _______, KC_2,    KC_7,    KC_8,    _______, _______,          KC_PGDN,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______
    ),

    [_NL] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______, _______, _______,
        _______, WM_H,    WM_T,    WM_N,    WM_S,    _______, _______, GUI_LFT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, SFT_RGT, _______, _______,
        _______, WMS_H,   WMS_T,   WMS_N,   WMS_S,   _______, _______, _______, CTL_LFT, KC_HOME, KC_END,  CTL_RGT, _______,          _______,
        _______, _______, KC_LSFT, KC_LCTL, KC_LALT, _______, KC_RALT, KC_RCTL, KC_RSFT, _______, _______, _______,          _______, _______,
        _______, _______, KC_LGUI,                            _______,                            KC_RGUI, _______, _______, _______, _______
    ),

    [_FL] = LAYOUT_65_ansi_blocker(
        TO(_CL), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  TO(_CL), _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_CAPS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LCAP,          KC_VOLU, KC_MUTE,
        TO(_BL), TO(_QL), TO(_DL),                            _______,                            _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),

    [_CL] = LAYOUT_65_ansi_blocker(
        TO(_QL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PWR,  EE_CLR,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NK_TOGG, QK_BOOT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          GU_TOGG,
        XXXXXXX, XXXXXXX, UG_SATD, UG_VALD, UG_HUED, XXXXXXX, UG_HUEU, UG_VALU, UG_SATU, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
        TO(_DL), XXXXXXX, UG_PREV,                            RM_TOGG,                            UG_NEXT, XXXXXXX, XXXXXXX, TO(_BL), XXXXXXX
    )
};

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C

