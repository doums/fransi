/*
 * HHKB FRANSI layout
 *
 * designed for HHKB Pro2 (KB400) with Hasu alt-controller
 * by deip
 */

#include QMK_KEYBOARD_H

// ⚠ this keymap assumes keyboard layout is set to FR at OS level
#include <keymap_french.h>
#include <sendstring_french.h>

/*
 * BASE
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │Esc│ & │ é │ " │ ' │ % │ - │ è │ _ │ ( │ ) │ * │ = │ \ │ ~ │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 * │Tab  │ a │ z │ e │ r │ t │ y │ u │ i │ o │ p │ [ │ ] │ BS  │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │Ctrl  │ q │ s │ d │ f │ g │ h │ j │ k │ l │ m │ $ │ Return │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 * │Shift   │ w │ x │ c │ v │ b │ n │ , │ ; │ : │ ! │Shift │Fn │
 * └─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴──┬┴───┴┬──┴┬─────┴───┘
 *       │GUI│ Alt │        Space          │AltGr│GUI│
 *       └───┴─────┴───────────────────────┴─────┴───┘
 *
 * SHIFT
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ µ │ + │ | │ ² │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 * │Tab  │ A │ Z │ E │ R │ T │ Y │ U │ I │ O │ P │ { │ } │ BS  │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │Ctrl  │ Q │ S │ D │ F │ G │ H │ J │ K │ L │ M │ % │ Return │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 * │Shift   │ W │ X │ C │ V │ B │ N │ ? │ . │ / │ § │Shift │Fn │
 * └─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴──┬┴───┴┬──┴┬─────┴───┘
 *       │GUI│ Alt │        Space          │AltGr│GUI│
 *       └───┴─────┴───────────────────────┴─────┴───┘
 *
 * AltGr
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │Esc│ ¹ │ ~ │ # │ { │ [ │ | │ ` │ \ │ ^ │ @ │   │ } │ \ │ ¬ │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┲━┷━┳━┷━┱─┴───┤
 * │Tab  │ à │ « │ € │ ¶ │ ŧ │ ← │ ù │ → │ ø │ þ ┃ ^ ┃ ¨ ┃ BS  │  ━ dead keys
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┺┯━━┻┯━━┹─────┤
 * │Ctrl  │ @ │ ß │ ° │ đ │ ŋ │ ħ │   │ ĸ │ ł │ µ │ ¤ │ Return │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 * │Shift   │ ł │ » │ ç │ „ │ “ │ ” │   │ < │ > │   │Shift │Fn │
 * └─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴──┬┴───┴┬──┴┬─────┴───┘
 *       │GUI│ Alt │        Space          │AltGr│GUI│
 *       └───┴─────┴───────────────────────┴─────┴───┘
 *
 * Fn
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │ ² │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│Ins│Del│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 * │Caps │<- │-> │   │=> │   │   │   │PSc│KyL│Pus│ ↑ │   │ BS  │  KyL -> Key Lock feature
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │      │VoD│VoU│Mut│Ejc│   │ * │ / │Hom│PgU│ ← │ → │  Enter │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 * │        │BrD│BrU│   │   │   │ + │ - │End│PgD│ ↓ │      │Fn │
 * └─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴──┬┴───┴┬──┴┬─────┴───┘
 *       │   │     │                       │Stop │   │
 *       └───┴─────┴───────────────────────┴─────┴───┘
 *
 * NOTE: key (0,0) set to "²" instead of "Power" (too risky)
 */

enum layers {
    _BL = 0, // base
    _FN,     // Fn
};

enum keycodes {
    LARW = SAFE_RANGE, // <-
    RARW,              // ->
    RARWD,             // =>
    CU_LBRC,           // custom keycode for [{
    CU_RBRC,           // custom keycode for ]}
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    FR_ASTR, KC_EQL,  KC_BSLS, KC_TILDE,
        KC_TAB /**/, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    CU_LBRC, CU_RBRC, /**/ KC_BSPC,
        KC_LCTL /**/, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, /*        */ KC_ENT,
        KC_LSFT /*  */, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, /*      */ KC_RSFT, MO(_FN),
        /* * * */ KC_LGUI, KC_LALT, /*                       */ KC_SPC /*                      */, KC_RALT, KC_RGUI /* * * * * * * * * * * * */
    ),
    [_FN] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
        KC_CAPS/**/, LARW,    RARW,    _______, RARWD,   _______, _______, _______, KC_PSCR, QK_LOCK, KC_PAUS, KC_UP,   _______, /**/ KC_BSPC,
        _______ /**/, KC_VOLD, KC_VOLU, KC_MUTE, KC_EJCT, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, /*        */ KC_PENT,
        _______ /*  */, KC_BRID, KC_BRIU, _______, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, /*      */ _______, _______,
        /* * * */ _______, _______, /*                      */ _______ /*                      */, KC_STOP, _______ /* * * * * * * * * * * * */
    )
};
// clang-format on

const key_override_t labk_ko = ko_make_basic(MOD_MASK_ALT, KC_COMM, FR_LABK);     // Alt + ; = <
const key_override_t rabk_ko = ko_make_basic(MOD_MASK_ALT, KC_DOT, FR_RABK);      // Alt + : = >
const key_override_t circ_ko = ko_make_basic(MOD_BIT(KC_RALT), CU_LBRC, FR_CIRC); // RAlt + [ = ^ (dead)
const key_override_t diae_ko = ko_make_basic(MOD_BIT(KC_RALT), CU_RBRC, FR_DIAE); // RAlt + ] = ¨ (dead)
const key_override_t lcbr_ko = ko_make_basic(MOD_MASK_SHIFT, CU_LBRC, FR_LCBR);   // Shift + [ = {
const key_override_t rcbr_ko = ko_make_basic(MOD_MASK_SHIFT, CU_RBRC, FR_RCBR);   // Shift + ] = }
const key_override_t agrv_ko = ko_make_basic(MOD_BIT(KC_RALT), KC_Q, FR_AGRV);    // RAlt + A = à
const key_override_t ugrv_ko = ko_make_basic(MOD_BIT(KC_RALT), KC_U, FR_UGRV);    // RAlt + U = ù
const key_override_t degr_ko = ko_make_basic(MOD_BIT(KC_RALT), KC_D, FR_DEG);     // RAlt + D = °
const key_override_t pipe_ko = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, FR_PIPE);   // Shift + \ = |
const key_override_t sup2_ko = ko_make_basic(MOD_MASK_SHIFT, KC_TILD, FR_SUP2);   // Shift + ~ = ²
const key_override_t cedl_ko = ko_make_basic(MOD_MASK_ALT, KC_C, FR_CCED);        // RAlt + C = ç

const key_override_t *key_overrides[] = {&labk_ko, &rabk_ko, &circ_ko, &diae_ko, &lcbr_ko, &rcbr_ko,
                                         &agrv_ko, &ugrv_ko, &degr_ko, &pipe_ko, &sup2_ko, &cedl_ko};

bool key_override_reg(uint16_t keycode, uint8_t mod_filter, keyrecord_t *record) {
    static bool key_registered;
    if (record->event.pressed) {
        if (!(get_mods() & mod_filter) && !(get_oneshot_mods() & mod_filter)) {
            register_code16(keycode);
            key_registered = true;
            return false;
        }
    } else if (key_registered) {
        unregister_code16(keycode);
        key_registered = false;
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BSLS: // keep us qwerty key `\`
            return key_override_reg(FR_BSLS, MOD_MASK_SHIFT, record);
        case CU_LBRC:
            return key_override_reg(FR_LBRC, MOD_MASK_SHIFT | MOD_BIT(KC_RALT), record);
        case CU_RBRC:
            return key_override_reg(FR_RBRC, MOD_MASK_SHIFT | MOD_BIT(KC_RALT), record);
        case KC_QUOT: // convert " to $
            if (IS_LAYER_ON(_FN)) {
                return true;
            }
            return key_override_reg(FR_DLR, MOD_MASK_SHIFT, record);
        case KC_9: // convert 9 to (
            if (IS_LAYER_ON(_FN)) {
                return true;
            }
            return key_override_reg(FR_LPRN, MOD_MASK_SHIFT | MOD_MASK_ALT, record);
        case KC_0: // convert 0 to )
            if (IS_LAYER_ON(_FN)) {
                return true;
            }
            return key_override_reg(FR_RPRN, MOD_MASK_SHIFT | MOD_MASK_ALT, record);
        case KC_5: // convert 5 to %
            if (IS_LAYER_ON(_FN)) {
                return true;
            }
            return key_override_reg(FR_PERC, MOD_MASK_SHIFT | MOD_MASK_ALT, record);
        case LARW:
            if (record->event.pressed) SEND_STRING("<-");
            return true;
        case RARW:
            if (record->event.pressed) SEND_STRING("->");
            return true;
        case RARWD:
            if (record->event.pressed) SEND_STRING("=>");
            return true;
        default:
            return true; // process all other keycodes normally
    }
}
