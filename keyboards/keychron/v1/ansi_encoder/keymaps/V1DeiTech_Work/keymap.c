/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

// clang-format off

// Layer names
enum layers{
    WIN_DV_BASE,
    WIN_DV_FN
    WIN_QW_BASE,
    WIN_QW_FN,
    WIN_DV_QDRAW,
    WIN_DV_QCODE,
    WIN_QW_QDRAW,
    WIN_QW_QCODE,
};

// Custom keycode names
enum custom_keycodes {
    MULTIUP = SAFE_RANGE,
    MULTIDOWN
};

// Repeat press settings
#define MULTI_VERT  5 // Number of times to repeat vertical key presses

// Layer macros
#define MQ_DVFN     MO(WIN_DV_FN)
#define MO_DVQD     MO(WIN_DV_QDRAW)
#define LT_DVQC     LT(WIN_DV_QCODE, KC_GRV)
#define MQ_QWFN     MO(WIN_QW_FN)
#define MO_QWQD     MO(WIN_QW_QDRAW)
#define LT_QWQC     LT(WIN_QW_QCODE, KC_GRV)

// Navigation macros
#define KC_TASK     LGUI(KC_TAB)
#define KC_FLXP     LGUI(KC_E)
#define KC_LTAB     LCTL(LSFT(KC_TAB))
#define KC_RTAB     LSFT(KC_TAB)
#define KC_WNLK     LGUI(KC_L)

// VS Code short    cut macros
#define KC_V_CD     LCTL(LSFT(KC_P))    // Command Palette
#define KC_V_OP     LCTL(KC_P)          // Open File
#define KC_V_CB     LSFT(LALT(KP_A))    // Comment block

#define KC_V_AO     LCTL(LSFT(KP_L))    // Select all occurrences
#define KC_V_FD     LCTL(KC_F)          // Find
#define KC_V_RP     LCTL(KC_H)          // Replace
#define KC_V_PO     LSFT(KC_F3)         // Previous occurrence in Find
#define KC_V_NO     KC_F3               // Next occurrence in Find
#define KC_V_LS     LCTL(KC_L)          // Select entire line
#define KC_V_LMU    LALT(KC_UP)         // Move line up
#define KC_V_LMD    LALT(KC_DOWN)       // Move line down
#define KC_V_LCU    LSFT(LALT(KC_UP))   // Copy line up
#define KC_V_LCD    LSFT(LALT(KC_DOWN)) // Copy line down

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Windows Dvorak Base Layer
    [WIN_DV_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_ENT,             KC_WNLK,
        LT_DVQC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_LBRC,    KC_RBRC,  KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_SLSH,    KC_EQL,   KC_BSLS,            KC_PGDN,
        MO_DVQD,  KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,              KC_ENT,             KC_HOME,
        KC_LSFT,            KC_SCLN,  KC_Q,     KC_J,     KC_K,     KC_X,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,                 KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MQ_DVFN,    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    // Windows Dvorak Function Layer
    [WIN_DV_FN] = LAYOUT_ansi_82(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  XXXXXXX,            _______,
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,            XXXXXXX,
        _______,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  NK_TOGG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX),

    // Windows QWERTY Base Layer
    [WIN_QW_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_ENT,             KC_WNLK,
        LT_QWQC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        MO_QWQD,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MQ_QWFN,    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    // Windows QWERTY Function Layer
    [WIN_QW_FN] = LAYOUT_ansi_82(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  XXXXXXX,            _______,
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,            XXXXXXX,
        _______,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  NK_TOGG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX),

    // Windows Dvorak quickdraw Layer
    [WIN_DV_QDRAW] = LAYOUT_ansi_82(
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            _______,
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  KC_DEL,             XXXXXXX,
        XXXXXXX,  XXXXXXX,  KC_PAST,  KC_PPLS,  KC_EQL,   XXXXXXX,  KC_INS,   KC_LTAB,  KC_UP,    KC_RTAB,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        _______,  KC_UNDO,  KC_CUT,   KC_COPY,  KC_PSTE,  C(KC_Y),  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,   XXXXXXX,              XXXXXXX,            XXXXXXX,
        _______,            XXXXXXX,  S(KC_LBRC), KC_LBRC, S(KC_9), KC_BSLS,  KC_SLSH,  S(KC_0),  KC_RBRC,  S(KC_RBRC), XXXXXXX,            XXXXXXX,  KC_MUTE,
        _______,  _______,  _______,                                _______,                                _______,  XXXXXXX,    _______,  KC_MPRV,  KC_MPLY,  KC_MNXT),

    // Windows Dvorak quickcode Layer
    [WIN_DV_QCODE] = LAYOUT_ansi_82(
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            _______,
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_V_OP,  XXXXXXX,  KC_V_LCU, KC_V_LMU, XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_V_CD,  KC_V_LS,  KC_V_LCD, KC_V_LMD, XXXXXXX,              XXXXXXX,            XXXXXXX,
        _______,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_V_CB,  KC_V_AO,  XXXXXXX,  XXXXXXX,              XXXXXXX,  KC_V_FD,
        _______,  _______,  _______,                                _______,                                _______,  XXXXXXX,    _______,  KC_V_PO,  KC_V_RP,  KC_V_NO),

    // Windows QWERTY quickdraw Layer
    [WIN_QW_QDRAW] = LAYOUT_ansi_82(
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            _______,
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  KC_DEL,             XXXXXXX,
        XXXXXXX,  XXXXXXX,  KC_PAST,  KC_PPLS,  KC_EQL,   XXXXXXX,  KC_INS,   KC_LTAB,  KC_UP,    KC_RTAB,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        _______,  KC_UNDO,  KC_CUT,   KC_COPY,  KC_PSTE,  C(KC_Y),  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,   XXXXXXX,              XXXXXXX,            XXXXXXX,
        _______,            XXXXXXX,  S(KC_LBRC), KC_LBRC, S(KC_9), KC_BSLS,  KC_SLSH,  S(KC_0),  KC_RBRC,  S(KC_RBRC), XXXXXXX,            XXXXXXX,  KC_MUTE,
        _______,  _______,  _______,                                _______,                                _______,  XXXXXXX,    _______,  KC_MPRV,  KC_MPLY,  KC_MNXT),

    // Windows QWERTY quickcode Layer
    [WIN_QW_QCODE] = LAYOUT_ansi_82(
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            _______,
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_V_OP,  XXXXXXX,  KC_V_LCU, KC_V_LMU, XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_V_CD,  KC_V_LS,  KC_V_LCD, KC_V_LMD, XXXXXXX,              XXXXXXX,            XXXXXXX,
        _______,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_V_CB,  KC_V_AO,  XXXXXXX,  XXXXXXX,              XXXXXXX,  KC_V_FD,
        _______,  _______,  _______,                                _______,                                _______,  XXXXXXX,    _______,  KC_V_PO,  KC_V_RP,  KC_V_NO),
};

// Macro behaviours
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MULTIUP:
        if (record->event.pressed) {
            // Press UP key several times
            for (int i = 0; i < MULTI_VERT; i++) {
                tap_code(KC_UP);
            }
        }
        break;
    }
    case MULTIDOWN:
        if (record->event.pressed) {
            // Press DOWN key several times
            for (int i = 0; i < MULTI_VERT; i++) {
                tap_code(KC_DOWN);
            }
        }
        break;
    return true;
};

// Encoder map
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [WIN_DV_BASE] =     { ENCODER_CCW_CW(KC_LEFT,   KC_RGHT)},
    [WIN_DV_FN]   =     { ENCODER_CCW_CW(KC_VOLD,   KC_VOLU)},
    [WIN_QW_BASE] =     { ENCODER_CCW_CW(KC_LEFT,   KC_RGHT)},
    [WIN_QW_FN]   =     { ENCODER_CCW_CW(KC_VOLD,   KC_VOLU)},
    [WIN_DV_QDRAW] =    { ENCODER_CCW_CW(KC_UP,     KC_DOWN)},
    [WIN_DV_QCODE] =    { ENCODER_CCW_CW(MULTIUP,   MULTIDOWN)},
    [WIN_QW_QDRAW] =    { ENCODER_CCW_CW(KC_UP,     KC_DOWN)},
    [WIN_QW_QCODE] =    { ENCODER_CCW_CW(MULTIUP,   MULTIDOWN)},
};
#endif // ENCODER_MAP_ENABLE