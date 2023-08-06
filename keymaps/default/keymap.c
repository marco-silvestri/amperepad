#include QMK_KEYBOARD_H
#include "os_detection.h"

#define LAYER_CYCLE_START 0
#define LAYER_CYCLE_END 3

float lc_sound[][2] = SONG(TERMINAL_SOUND);

enum macropad_keycodes {
    CS_0_KC_1 = SAFE_RANGE,
    CS_0_KC_2,
    CS_0_KC_3,
    CS_0_KC_4,
    CS_0_KC_5,
    CS_0_KC_6,
    CS_0_KC_7,
    CS_0_KC_8,
    CS_0_KC_9,
    CS_0_KC_10,
    CS_0_KC_11,
    CS_0_KC_12,
    CS_0_KC_13,
    CS_0_KC_14,
    CS_0_KC_15,
    CS_0_KC_16,
    CS_1_KC_1,
    CS_1_KC_2,
    CS_1_KC_3,
    CS_1_KC_4,
    CS_1_KC_5,
    CS_1_KC_6,
    CS_1_KC_7,
    CS_1_KC_8,
    CS_1_KC_9,
    CS_1_KC_10,
    CS_1_KC_11,
    CS_1_KC_12,
    CS_1_KC_13,
    CS_1_KC_14,
    CS_1_KC_15,
    CS_1_KC_16,
    CS_2_KC_1,
    CS_2_KC_2,
    CS_2_KC_3,
    CS_2_KC_4,
    CS_2_KC_5,
    CS_2_KC_6,
    CS_2_KC_7,
    CS_2_KC_8,
    CS_2_KC_9,
    CS_2_KC_10,
    CS_2_KC_11,
    CS_2_KC_12,
    CS_2_KC_13,
    CS_2_KC_14,
    CS_2_KC_15,
    CS_2_KC_16,
    CS_3_KC_1,
    CS_3_KC_2,
    CS_3_KC_3,
    CS_3_KC_4,
    CS_3_KC_5,
    CS_3_KC_6,
    CS_3_KC_7,
    CS_3_KC_8,
    CS_3_KC_9,
    CS_3_KC_10,
    CS_3_KC_11,
    CS_3_KC_12,
    CS_3_KC_13,
    CS_3_KC_14,
    CS_3_KC_15,
    CS_3_KC_16,
};

enum layer_number {
    _PAD    = 0,
    _VSCODE = 1,
    _GIT    = 2,
    _SETUP  = 3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[_PAD] = LAYOUT(CS_0_KC_16, CS_0_KC_15, CS_0_KC_14, CS_0_KC_13, CS_0_KC_12, CS_0_KC_11, CS_0_KC_10, CS_0_KC_9, CS_0_KC_8, CS_0_KC_7, CS_0_KC_6, CS_0_KC_5, CS_0_KC_4, CS_0_KC_3, CS_0_KC_2, CS_0_KC_1), [_VSCODE] = LAYOUT(CS_1_KC_16, CS_1_KC_15, CS_1_KC_14, CS_1_KC_13, CS_1_KC_12, CS_1_KC_11, CS_1_KC_10, CS_1_KC_9, CS_1_KC_8, CS_1_KC_7, CS_1_KC_6, CS_1_KC_5, CS_1_KC_4, CS_1_KC_3, CS_1_KC_2, CS_1_KC_1), [_GIT] = LAYOUT(CS_2_KC_16, CS_2_KC_15, CS_2_KC_14, CS_2_KC_13, CS_2_KC_12, CS_2_KC_11, CS_2_KC_10, CS_2_KC_9, CS_2_KC_8, CS_2_KC_7, CS_2_KC_6, CS_2_KC_5, CS_2_KC_4, CS_2_KC_3, CS_2_KC_2, CS_2_KC_1), [_SETUP] = LAYOUT(CS_3_KC_16, CS_3_KC_15, CS_3_KC_14, CS_3_KC_13, CS_3_KC_12, CS_3_KC_11, CS_3_KC_10, CS_3_KC_9, CS_3_KC_8, CS_3_KC_7, CS_3_KC_6, CS_3_KC_5, CS_3_KC_4, CS_3_KC_3, CS_3_KC_2, CS_3_KC_1)};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {[_PAD] = {ENCODER_CCW_CW(LCTL(KC_PPLS), LCTL(KC_PMNS)), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)}, [_VSCODE] = {ENCODER_CCW_CW(LCTL(KC_PPLS), LCTL(KC_PMNS)), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)}, [_GIT] = {ENCODER_CCW_CW(LCTL(KC_PPLS), LCTL(KC_PMNS)), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)}, [_SETUP] = {ENCODER_CCW_CW(LCTL(KC_PPLS), LCTL(KC_PMNS)), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)}};

char *os;
char *currentLayer;
bool  jiggler = true;

void drawLayerMap(void) {
    switch (get_highest_layer(layer_state)) {
        case _PAD:
            oled_set_cursor(0, 2);
            oled_write_P(PSTR("Cpy | "), false);
            oled_write_P(PSTR("Cut | "), false);
            oled_write_P(PSTR("Pst | "), false);
            oled_write_P(PSTR("Clr"), false);
            oled_set_cursor(0, 3);
            oled_write_P(PSTR("CpT | "), false);
            oled_write_P(PSTR("PsT | "), false);
            oled_write_P(PSTR("Und | "), false);
            oled_write_P(PSTR("Red"), false);
            oled_set_cursor(0, 4);
            oled_write_P(PSTR("PrT | "), false);
            oled_write_P(PSTR("NxT | "), false);
            oled_write_P(PSTR("NwT | "), false);
            oled_write_P(PSTR("ClT"), false);
            oled_set_cursor(0, 5);
            oled_write_P(PSTR("Dev | "), false);
            oled_write_P(PSTR("Nlg | "), false);
            oled_write_P(PSTR("Crt | "), false);
            oled_write_P(PSTR("Dwn"), false);
            break;
        case _VSCODE:
            oled_set_cursor(0, 2);
            oled_write_P(PSTR("Exp | "), false);
            oled_write_P(PSTR("Trm | "), false);
            oled_write_P(PSTR("Src | "), false);
            oled_write_P(PSTR("SdT"), false);
            oled_set_cursor(0, 3);
            oled_write_P(PSTR("Dcn | "), false);
            oled_write_P(PSTR("SOv | "), false);
            oled_write_P(PSTR("SIn | "), false);
            oled_write_P(PSTR("SOt"), false);
            oled_set_cursor(0, 4);
            oled_write_P(PSTR("Und | "), false);
            oled_write_P(PSTR("Red | "), false);
            oled_write_P(PSTR("Del | "), false);
            oled_write_P(PSTR("Fmt"), false);
            oled_set_cursor(0, 5);
            oled_write_P(PSTR("Cpy | "), false);
            oled_write_P(PSTR("Cut | "), false);
            oled_write_P(PSTR("Pst | "), false);
            oled_write_P(PSTR("TCl"), false);
            break;
        case _GIT:
            oled_set_cursor(0, 2);
            oled_write_P(PSTR("Add | "), false);
            oled_write_P(PSTR("Cmt | "), false);
            oled_write_P(PSTR("Psh | "), false);
            oled_write_P(PSTR("Pul"), false);
            oled_set_cursor(0, 3);
            oled_write_P(PSTR("Shw | "), false);
            oled_write_P(PSTR("Cho | "), false);
            oled_write_P(PSTR("NwB | "), false);
            oled_write_P(PSTR("Ftc"), false);
            oled_set_cursor(0, 4);
            oled_write_P(PSTR("    | "), false);
            oled_write_P(PSTR("    | "), false);
            oled_write_P(PSTR("    | "), false);
            oled_write_P(PSTR("   "), false);
            oled_set_cursor(0, 5);
            oled_write_P(PSTR("    | "), false);
            oled_write_P(PSTR("    | "), false);
            oled_write_P(PSTR("    | "), false);
            oled_write_P(PSTR("    "), false);
            break;
        case _SETUP:
            oled_set_cursor(0, 2);
            oled_write_P(PSTR("    | "), false);
            oled_write_P(PSTR("    | "), false);
            oled_write_P(PSTR("    | "), false);
            oled_write_P(PSTR("   "), false);
            oled_set_cursor(0, 3);
            oled_write_P(PSTR("    | "), false);
            oled_write_P(PSTR("    | "), false);
            oled_write_P(PSTR("    | "), false);
            oled_write_P(PSTR("   "), false);
            oled_set_cursor(0, 4);
            oled_write_P(PSTR("    | "), false);
            oled_write_P(PSTR("    | "), false);
            oled_write_P(PSTR("    | "), false);
            oled_write_P(PSTR("   "), false);
            oled_set_cursor(0, 5);
            oled_write_P(PSTR("    | "), false);
            oled_write_P(PSTR("    | "), false);
            oled_write_P(PSTR("Jig | "), false);
            oled_write_P(PSTR("Mut "), false);
            break;
    }
}

void get_os(void) {
    switch (detected_host_os()) {
        case OS_LINUX:
            os = (char *)"LINUX";
            break;
        case OS_WINDOWS:
            os = (char *)"WINDOWS";
            break;
        case OS_MACOS:
            os = (char *)"MAC";
            break;
        case OS_UNSURE:
            os = (char *)"UNKNOWN";
            break;
        case OS_IOS:
            os = (char *)"IOS";
            break;
    }
}

void matrix_init_user(void) {}

bool oled_task_user(void) {
    const char *text = "Ampere Pad ";
    oled_set_cursor(0, 0);
    oled_write(text, false);
    oled_write_P(PSTR("on "), false);
    switch (get_highest_layer(layer_state)) {
        case _PAD:
            oled_write("Pad\n", false);
            break;
        case _VSCODE:
            oled_write("Code\n", false);
            break;
        case _GIT:
            oled_write("Git\n", false);
            break;
        case _SETUP:
            oled_write("Setup\n", false);
            break;
        default:
            oled_write(PSTR("???\n"), false);
    }

    drawLayerMap();

    oled_set_cursor(0, 7);
    oled_write("Lazy mode: ", false);

    if (jiggler) {
        oled_write("ON ", false);
    } else {
        oled_write("OFF", false);
    }
    return false;
}

void cycle_layers(void) {
    uint8_t current_layer = get_highest_layer(layer_state);
    if (current_layer > LAYER_CYCLE_END || current_layer < LAYER_CYCLE_START) {
        return;
    }

    uint8_t next_layer = current_layer + 1;
    if (next_layer > LAYER_CYCLE_END) {
        next_layer = LAYER_CYCLE_START;
    }
    PLAY_SONG(lc_sound);
    layer_move(next_layer);
}

static uint32_t key_timer = 0;
void            matrix_scan_user(void) {
    if (timer_elapsed32(key_timer) > 300000 && jiggler) {
        key_timer = timer_read32();
        tap_code_delay(KC_MS_UP, 100);
        tap_code_delay(KC_MS_DOWN, 100);
        tap_code_delay(KC_MS_LEFT, 100);
        tap_code_delay(KC_MS_RIGHT, 100);
    }
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                tap_code(KC_MEDIA_PLAY_PAUSE);
            }
            break;
        case 1:
            if (active) {
                cycle_layers();
            }
            break;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    get_os();
    switch (keycode) {
        // first row
        case CS_0_KC_16:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_C));
            };
            return true;
        case CS_1_KC_16:
            if (record->event.pressed) {
                tap_code16(LSFT(LCTL(KC_E)));
            }; // show explorer
            return true;
        case CS_2_KC_16:
            if (record->event.pressed) {
                SEND_STRING("git add .");
            };
            return true;
        case CS_0_KC_15:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_X));
            };
            return true;
        case CS_1_KC_15:
            if (record->event.pressed) {
                tap_code16(LSFT(LCTL(KC_D)));
            }; // show debug
            return true;
        case CS_2_KC_15:
            if (record->event.pressed) {
                SEND_STRING("git commit -m ''");
                tap_code(KC_LEFT);
            };
            return true;
        case CS_0_KC_14:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_V));
            };
            return true;
        case CS_1_KC_14:
            if (record->event.pressed) {
                tap_code16(LSFT(LCTL(KC_G)));
            }; // show source
            return true;
        case CS_2_KC_14:
            if (record->event.pressed) {
                SEND_STRING("git push");
            };
            return true;
        case CS_0_KC_13:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_C));
            };
            return true;
        case CS_1_KC_13:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_B));
            }; // toggle sidebar
            return true;
        case CS_2_KC_13:
            if (record->event.pressed) {
                SEND_STRING("git pull");
            };
            return true;
        // second row
        case CS_0_KC_12:
            if (record->event.pressed) {
                tap_code16(LCTL(LSFT(KC_V)));
            };
            return true;
        case CS_1_KC_12:
            if (record->event.pressed) {
                tap_code(KC_F5);
            }; // debug start/continue
            return true;
        case CS_2_KC_12:
            if (record->event.pressed) {
                SEND_STRING("git show \n");
            };
            return true;
        case CS_0_KC_11:
            if (record->event.pressed) {
                tap_code16(LCTL(LSFT(KC_V)));
            };
            return true;
        case CS_1_KC_11:
            if (record->event.pressed) {
                tap_code(KC_F10);
            }; // step over
            return true;
        case CS_2_KC_11:
            if (record->event.pressed) {
                SEND_STRING("git checkout ");
            };
            return true;
        case CS_0_KC_10:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_Z));
            };
            return true;
        case CS_1_KC_10:
            if (record->event.pressed) {
                tap_code(KC_F11);
            }; // step out
            return true;
        case CS_2_KC_10:
            if (record->event.pressed) {
                SEND_STRING("git checkout -b ''");
                tap_code(KC_LEFT);
            };
            return true;
        case CS_0_KC_9:
            if (record->event.pressed) {
                tap_code16(LCTL(LSFT(KC_Z)));
            };
            return true;
        case CS_1_KC_9:
            if (record->event.pressed) {
                tap_code16(LSFT(KC_F11));
            }; // step in
            return true;
        case CS_2_KC_9:
            if (record->event.pressed) {
                SEND_STRING("git fetch \n");
            };
            return true;
        // third row
        case CS_0_KC_8:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_PGUP));
            };
            return true;
        case CS_1_KC_8:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_Z));
            };
            return true;
        case CS_0_KC_7:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_PGDN));
            };
            return true;
        case CS_1_KC_7:
            if (record->event.pressed) {
                tap_code16(LCTL(LSFT(KC_Z)));
            };
            return true;
        case CS_0_KC_6:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_T));
            };
            return true;
        case CS_1_KC_6:
            if (record->event.pressed) {
                tap_code16(LCTL(LSFT(KC_K)));
            }; // del line
            return true;
        case CS_0_KC_5:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_W));
            };
            return true;
        case CS_1_KC_5:
            if (record->event.pressed) {
                if (os == (char *)"LINUX") {
                    tap_code16(LCTL(LCTL(KC_I)));
                } else if (os == (char *)"WINDOWS") {
                    tap_code16(LSFT(LALT(KC_F)));
                }
            }; // format
            return true;
        // fourth row
        case CS_0_KC_4:
            if (record->event.pressed) {
                tap_code16(LCTL(LSFT(KC_J)));
            }; // dev tools
            return true;
        case CS_1_KC_4:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_C));
            };
            return true;
        case CS_0_KC_3:
            if (record->event.pressed) {
                tap_code16(LCTL(LSFT(KC_M)));
            }; // new login
            return true;
        case CS_1_KC_3:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_X));
            };
            return true;
        case CS_0_KC_2:
            if (record->event.pressed) {
                tap_code(KC_F7);
            }; // caret
            return true;
        case CS_1_KC_2:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_V));
            };
            return true;
        case CS_3_KC_2:
            if (record->event.pressed) {
                jiggler = !jiggler;
            };
            return true;
        case CS_0_KC_1:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_L));
            }; // downloads
            return true;
        case CS_1_KC_1:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_SLSH));
            };
            return true;
        case CS_3_KC_1:
            if (record->event.pressed) {
                audio_toggle();
            };
            return true;
        default:
            return true;
    }
    return true;
}
