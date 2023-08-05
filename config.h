/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define MATRIX_ROWS 4
#define MATRIX_COLS 4

#define MATRIX_ROW_PINS { F7, F6, F5, F4 }
#define MATRIX_COL_PINS { B6, B2, B3, B1 }

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define AUDIO_PIN B5

#define OLED_DISPLAY_128X64

#define NUMBER_OF_ENCODERS 2
#define ENCODERS_PAD_A { B4, C6 }
#define ENCODERS_PAD_B { E6, D4 }
#define ENCODER_RESOLUTION 4

#define DIP_SWITCH_PINS { D7, D3 }
#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_RANDOMNESS 0.02f
