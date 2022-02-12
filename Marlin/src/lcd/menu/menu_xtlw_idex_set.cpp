/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

//
// XTLW3D IDE-X set menu
//

#include "../../inc/MarlinConfigPre.h"

#if HAS_LCD_MENU && ENABLED(DUAL_X_CARRIAGE) && ENABLED(XTLW3D)

#include "menu_item.h"
#include "../../module/motion.h"
#include "../../gcode/queue.h"
#include "../../module/settings.h"

/**
 * XTLW3D IDEX set.
 */

static inline void menu_line_calibrate_x_min() {
  START_MENU();
  BACK_ITEM(MSG_X_CALIBRATE);

  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N1, []() { queue.inject_P(PSTR("M219 T1 X+0.04")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N2, []() { queue.inject_P(PSTR("M219 T1 X+0.08")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N3, []() { queue.inject_P(PSTR("M219 T1 X+0.12")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N4, []() { queue.inject_P(PSTR("M219 T1 X+0.16")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N5, []() { queue.inject_P(PSTR("M219 T1 X+0.20")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N6, []() { queue.inject_P(PSTR("M219 T1 X+0.24")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N7, []() { queue.inject_P(PSTR("M219 T1 X+0.28")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N8, []() { queue.inject_P(PSTR("M219 T1 X+0.32")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N9, []() { queue.inject_P(PSTR("M219 T1 X+0.36")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N10, []() { queue.inject_P(PSTR("M219 T1 X+0.40")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N11, []() { queue.inject_P(PSTR("M219 T1 X+0.44")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N12, []() { queue.inject_P(PSTR("M219 T1 X+0.48")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N13, []() { queue.inject_P(PSTR("M219 T1 X+0.52")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N14, []() { queue.inject_P(PSTR("M219 T1 X+0.56")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N15, []() { queue.inject_P(PSTR("M219 T1 X+0.60")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N16, []() { queue.inject_P(PSTR("M219 T1 X+0.64")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N17, []() { queue.inject_P(PSTR("M219 T1 X+0.68")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N18, []() { queue.inject_P(PSTR("M219 T1 X+0.72")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N19, []() { queue.inject_P(PSTR("M219 T1 X+0.76")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_N20, []() { queue.inject_P(PSTR("M219 T1 X+0.80")); ui.goto_previous_screen_no_defer(); });

  END_MENU();
}

static inline void menu_line_calibrate_x_max() {
  START_MENU();
  BACK_ITEM(MSG_X_CALIBRATE);

  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P1, []() { queue.inject_P(PSTR("M219 T1 X-0.04")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P2, []() { queue.inject_P(PSTR("M219 T1 X-0.08")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P3, []() { queue.inject_P(PSTR("M219 T1 X-0.12")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P4, []() { queue.inject_P(PSTR("M219 T1 X-0.16")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P5, []() { queue.inject_P(PSTR("M219 T1 X-0.20")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P6, []() { queue.inject_P(PSTR("M219 T1 X-0.24")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P7, []() { queue.inject_P(PSTR("M219 T1 X-0.28")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P8, []() { queue.inject_P(PSTR("M219 T1 X-0.32")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P9, []() { queue.inject_P(PSTR("M219 T1 X-0.36")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P10, []() { queue.inject_P(PSTR("M219 T1 X-0.40")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P11, []() { queue.inject_P(PSTR("M219 T1 X-0.44")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P12, []() { queue.inject_P(PSTR("M219 T1 X-0.48")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P13, []() { queue.inject_P(PSTR("M219 T1 X-0.52")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P14, []() { queue.inject_P(PSTR("M219 T1 X-0.56")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P15, []() { queue.inject_P(PSTR("M219 T1 X-0.60")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P16, []() { queue.inject_P(PSTR("M219 T1 X-0.64")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P17, []() { queue.inject_P(PSTR("M219 T1 X-0.68")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P18, []() { queue.inject_P(PSTR("M219 T1 X-0.72")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P19, []() { queue.inject_P(PSTR("M219 T1 X-0.76")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_X_CALIBRATE_LINE_P20, []() { queue.inject_P(PSTR("M219 T1 X-0.80")); ui.goto_previous_screen_no_defer(); });

  END_MENU();
}

static inline void menu_line_calibrate_y_min() {
  START_MENU();
  BACK_ITEM(MSG_Y_CALIBRATE);

  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N1, []() { queue.inject_P(PSTR("M219 T1 Y+0.04")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N2, []() { queue.inject_P(PSTR("M219 T1 Y+0.08")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N3, []() { queue.inject_P(PSTR("M219 T1 Y+0.12")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N4, []() { queue.inject_P(PSTR("M219 T1 Y+0.16")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N5, []() { queue.inject_P(PSTR("M219 T1 Y+0.20")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N6, []() { queue.inject_P(PSTR("M219 T1 Y+0.24")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N7, []() { queue.inject_P(PSTR("M219 T1 Y+0.28")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N8, []() { queue.inject_P(PSTR("M219 T1 Y+0.32")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N9, []() { queue.inject_P(PSTR("M219 T1 Y+0.36")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N10, []() { queue.inject_P(PSTR("M219 T1 Y+0.40")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N11, []() { queue.inject_P(PSTR("M219 T1 Y+0.44")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N12, []() { queue.inject_P(PSTR("M219 T1 Y+0.48")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N13, []() { queue.inject_P(PSTR("M219 T1 Y+0.52")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N14, []() { queue.inject_P(PSTR("M219 T1 Y+0.56")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N15, []() { queue.inject_P(PSTR("M219 T1 Y+0.60")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N16, []() { queue.inject_P(PSTR("M219 T1 Y+0.64")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N17, []() { queue.inject_P(PSTR("M219 T1 Y+0.68")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N18, []() { queue.inject_P(PSTR("M219 T1 Y+0.72")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N19, []() { queue.inject_P(PSTR("M219 T1 Y+0.76")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_N20, []() { queue.inject_P(PSTR("M219 T1 Y+0.80")); ui.goto_previous_screen_no_defer(); });

  END_MENU();
}

static inline void menu_line_calibrate_y_max() {
  START_MENU();
  BACK_ITEM(MSG_Y_CALIBRATE);

  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P1, []() { queue.inject_P(PSTR("M219 T1 Y-0.04")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P2, []() { queue.inject_P(PSTR("M219 T1 Y-0.08")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P3, []() { queue.inject_P(PSTR("M219 T1 Y-0.12")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P4, []() { queue.inject_P(PSTR("M219 T1 Y-0.16")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P5, []() { queue.inject_P(PSTR("M219 T1 Y-0.20")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P6, []() { queue.inject_P(PSTR("M219 T1 Y-0.24")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P7, []() { queue.inject_P(PSTR("M219 T1 Y-0.28")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P8, []() { queue.inject_P(PSTR("M219 T1 Y-0.32")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P9, []() { queue.inject_P(PSTR("M219 T1 Y-0.36")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P10, []() { queue.inject_P(PSTR("M219 T1 Y-0.40")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P11, []() { queue.inject_P(PSTR("M219 T1 Y-0.44")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P12, []() { queue.inject_P(PSTR("M219 T1 Y-0.48")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P13, []() { queue.inject_P(PSTR("M219 T1 Y-0.52")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P14, []() { queue.inject_P(PSTR("M219 T1 Y-0.56")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P15, []() { queue.inject_P(PSTR("M219 T1 Y-0.60")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P16, []() { queue.inject_P(PSTR("M219 T1 Y-0.64")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P17, []() { queue.inject_P(PSTR("M219 T1 Y-0.68")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P18, []() { queue.inject_P(PSTR("M219 T1 Y-0.72")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P19, []() { queue.inject_P(PSTR("M219 T1 Y-0.76")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_Y_CALIBRATE_LINE_P20, []() { queue.inject_P(PSTR("M219 T1 Y-0.80")); ui.goto_previous_screen_no_defer(); });

  END_MENU();
}

static inline void menu_line_calibrate_x() {
  START_MENU();
  BACK_ITEM(MSG_LINE_CALIBRATE);

  SUBMENU(MSG_X_CALIBRATE_NEGATIVE, menu_line_calibrate_x_min);
  SUBMENU(MSG_X_CALIBRATE_POSITIVE, menu_line_calibrate_x_max);
  ACTION_ITEM(MSG_LEFT_OFFSET, []() { queue.inject_P(PSTR("M219 T1 X+0.80")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_RIGHT_OFFSET, []() { queue.inject_P(PSTR("M219 T1 X-0.80")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_STORE_EEPROM, ui.store_settings);

  END_MENU();
}

static inline void menu_line_calibrate_y() {
  START_MENU();
  BACK_ITEM(MSG_LINE_CALIBRATE);

  SUBMENU(MSG_Y_CALIBRATE_NEGATIVE, menu_line_calibrate_y_min);
  SUBMENU(MSG_Y_CALIBRATE_POSITIVE, menu_line_calibrate_y_max);
  ACTION_ITEM(MSG_FRONT_OFFSET, []() { queue.inject_P(PSTR("M219 T1 Y+0.80")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_BACK_OFFSET, []() { queue.inject_P(PSTR("M219 T1 Y-0.80")); ui.goto_previous_screen_no_defer(); });
  ACTION_ITEM(MSG_STORE_EEPROM, ui.store_settings);

  END_MENU();
}

static inline void menu_line_calibrate() {
  START_MENU();
  BACK_ITEM(MSG_IDEX_SET);

  SUBMENU(MSG_X_CALIBRATE, menu_line_calibrate_x);
  SUBMENU(MSG_Y_CALIBRATE, menu_line_calibrate_y);
  ACTION_ITEM(MSG_STORE_EEPROM, ui.store_settings);

  END_MENU();
}

static inline void menu_tool_offsets() {
  auto _recalc_offsets = []{
    if (active_extruder && all_axes_trusted()) {
      queue.inject_P(G28_STR);
      active_extruder = 0;
    }
  };

  START_MENU();
  BACK_ITEM(MSG_IDEX_SET);

  EDIT_ITEM_FAST(float52sign, MSG_HOTEND_OFFSET_X, &hotend_offset[1].x, 255, 275, _recalc_offsets);
  EDIT_ITEM_FAST(float52sign, MSG_HOTEND_OFFSET_Y, &hotend_offset[1].y, -5.0, 5.0, _recalc_offsets);
  EDIT_ITEM_FAST(float52sign, MSG_HOTEND_OFFSET_Z, &hotend_offset[1].z, -10.0, 2.0, _recalc_offsets);
  ACTION_ITEM(MSG_STORE_EEPROM, ui.store_settings);

  END_MENU();
}

static inline void menu_idex_model() {
  const bool need_g28 = axes_should_home(_BV(Y_AXIS)|_BV(Z_AXIS));

  START_MENU();
  BACK_ITEM(MSG_IDEX_SET);

  GCODES_ITEM(MSG_IDEX_MODE_AUTOPARK,  PSTR("M605 S1\nG28 X\nG1 X5"));
  GCODES_ITEM(MSG_IDEX_MODE_DUPLICATE, need_g28
    ? PSTR("M605 S1\nT0\nG28\nM605 S2\nG28 X\nG1 X50")
    : PSTR("M605 S1\nT0\nM605 S2\nG28 X\nG1 X50"));
  GCODES_ITEM(MSG_IDEX_MODE_MIRRORED_COPY, need_g28
    ? PSTR("M605 S1\nT0\nG28\nM605 S2 X205\nG28 X\nG1 X0\nM605 S3 X205")
    : PSTR("M605 S1\nT0\nM605 S2 X205\nG28 X\nG1 X0\nM605 S3 X205"));
  GCODES_ITEM(MSG_IDEX_MODE_FULL_CTRL, PSTR("M605 S0\nG28 X"));

  EDIT_ITEM(float42_52, MSG_IDEX_DUPE_GAP, &duplicate_extruder_x_offset, (X2_MIN_POS) - (X1_MIN_POS), (X_BED_SIZE) - 20);

  END_MENU();
}

static inline void menu_xtlw_idex_set() {
  START_MENU();
  BACK_ITEM(MSG_CONFIGURATION);

  SUBMENU(MSG_LINE_CALIBRATE, menu_line_calibrate);
  SUBMENU(MSG_OFFSETS_MENU, menu_tool_offsets);
  SUBMENU(MSG_IDEX_MENU, menu_idex_model);

  END_MENU();
}

//static inline void _lcd_idex_set_homing() {
  //_lcd_draw_homing();
  //if (all_axes_homed()) {
    //ui.goto_screen(menu_xtlw_idex_set);
  //}
//}

void _lcd_xtlw_idex_set() {
  ui.defer_status_screen();
  //set_all_unhomed();
  //queue.inject_P(PSTR("G28"));
  ui.goto_screen(menu_xtlw_idex_set);
}

#endif
