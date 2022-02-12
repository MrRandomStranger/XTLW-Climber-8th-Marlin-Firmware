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
// XTLW3D Leveling menu
//

#include "../../inc/MarlinConfigPre.h"

#if HAS_LCD_MENU && ENABLED(LEVEL_BED_CORNERS) && ENABLED(XTLW3D)

#include "menu_item.h"
#include "../../gcode/queue.h"
#include "../../module/motion.h"
#include "../../module/planner.h"
#include "../../module/tool_change.h"
#include "../../module/settings.h"

#if HAS_LEVELING
  #include "../../feature/bedlevel/bedlevel.h"
#endif

#ifndef LEVEL_CORNERS_Z_HOP
  #define LEVEL_CORNERS_Z_HOP 4.0
#endif

#ifndef LEVEL_CORNERS_HEIGHT
  #define LEVEL_CORNERS_HEIGHT 0.0
#endif

static_assert(LEVEL_CORNERS_Z_HOP >= 0, "LEVEL_CORNERS_Z_HOP must be >= 0. Please update your configuration.");

#if HAS_LEVELING
  static bool leveling_was_active = false;
#endif

/**
 * Level corners, starting in the front-left corner.
 */

static int8_t bed_corner;
static inline void _lcd_goto_next_corner() {
  line_to_z(LEVEL_CORNERS_Z_HOP);
  switch (bed_corner) {
    case 0:
      current_position.set(40, 40);
      break;
    case 1:
      current_position.x = 165;
      break;
    case 2:
      current_position.y = 180;
      break;
    case 3:
      current_position.x = 40;
      break;
    #if ENABLED(LEVEL_CENTER_TOO)
      case 4:
        current_position.set(105, 110);
        break;
    #endif
  }
  line_to_current_position(manual_feedrate_mm_s.x);
  line_to_z(LEVEL_CORNERS_HEIGHT);
  if (++bed_corner > 3
    #if ENABLED(LEVEL_CENTER_TOO)
      + 1
    #endif
  ) bed_corner = 0;
}

static inline void _lcd_level_bed_corners_homing() {
  _lcd_draw_homing();
  if (all_axes_homed()) {
    bed_corner = 0;
    ui.goto_screen([]{
      MenuItem_confirm::select_screen(
        GET_TEXT(MSG_BUTTON_NEXT), GET_TEXT(MSG_BUTTON_DONE),
        _lcd_goto_next_corner,
        []{
          #if HAS_LEVELING
            set_bed_leveling_enabled(leveling_was_active);
          #endif
          ui.goto_previous_screen_no_defer();
          queue.inject_P(PSTR("M605 S1\nT0\nG28"));
        },
        GET_TEXT(
          #if ENABLED(LEVEL_CENTER_TOO)
            MSG_LEVEL_BED_NEXT_POINT
          #else
            MSG_NEXT_CORNER
          #endif
        ), (PGM_P)nullptr, PSTR("?")
      );
    });
    ui.set_selection(true);
    _lcd_goto_next_corner();
  }
}

static inline void _lcd_xtlw_level_bed_corners() {
  ui.defer_status_screen();
  set_all_unhomed();
  queue.inject_P(PSTR("M605 S1\nT0\nG28"));

  // Disable leveling so the planner won't mess with us
  #if HAS_LEVELING
    leveling_was_active = planner.leveling_active;
    set_bed_leveling_enabled(false);
  #endif

  ui.goto_screen(_lcd_level_bed_corners_homing);
}

/**
 * Level nozzle at upper left.
 */
static uint8_t tool_index;
static inline void _lcd_goto_next_nozzle() {
  switch (tool_index) {
    case 0:
      tool_change(tool_index = 1);
      break;
    case 1:
      tool_change(tool_index = 0);
      break;
  }
  line_to_current_position(manual_feedrate_mm_s.x);
  line_to_z(LEVEL_CORNERS_HEIGHT);
}

static inline void _lcd_level_nozzle_homing() {
  _lcd_draw_homing();
  if (all_axes_homed()) {
    //hotend_offset[1].z = 0;
    tool_index = 0;
    line_to_z(LEVEL_CORNERS_Z_HOP);
    current_position.set(40, 40);
    line_to_current_position(manual_feedrate_mm_s.x);
    ui.goto_screen([]{
      MenuItem_confirm::select_screen(
        GET_TEXT(MSG_BUTTON_NEXT), GET_TEXT(MSG_BUTTON_DONE),
        _lcd_goto_next_nozzle,
        []{
          ui.goto_previous_screen_no_defer();
          queue.inject_P(PSTR("M605 S0\nT0\nG28\nM605 S1"));
        },
        GET_TEXT(
          MSG_TOOL_CHANGE
        ), (PGM_P)nullptr, PSTR("?")
      );
    });
    ui.set_selection(true);
    _lcd_goto_next_nozzle();
  }
}

static inline void _lcd_xtlw_level_nozzle() {
  ui.defer_status_screen();
  set_all_unhomed();
  queue.inject_P(PSTR("M605 S1\nT0\nG28"));
  ui.goto_screen(_lcd_level_nozzle_homing);
}

/**
 * Adjust z home.
 */
static inline void _lcd_reset_z_endstop(){
  current_position.z = 0;
  line_to_current_position(manual_feedrate_mm_s.x);
  queue.inject_P(PSTR("G28 Z"));
}

static inline void _lcd_adjust_z_homing(){
  _lcd_draw_homing();
  if (all_axes_homed()){
    line_to_z(LEVEL_CORNERS_Z_HOP);
    current_position.set(102.5, 110);
    line_to_current_position(manual_feedrate_mm_s.x);
    ui.goto_screen([] {
      MenuItem_confirm::select_screen(
        GET_TEXT(MSG_BUTTON_RESET), GET_TEXT(MSG_BUTTON_DONE),
        _lcd_reset_z_endstop,
        [] {
          ui.goto_previous_screen_no_defer();
          queue.inject_P(PSTR("M605 S1\nT0\nG28"));
        },
        GET_TEXT(
          MSG_RESET_Z_ENDSTOP
        ),(PGM_P) nullptr, PSTR("?")
      );
    });
    ui.set_selection(true);
    _lcd_reset_z_endstop();
  }
}

static inline void _lcd_xtlw_adjust_z_home(){
  ui.defer_status_screen();
  set_all_unhomed();
  queue.inject_P(PSTR("M605 S1\nT0\nG28"));
  ui.goto_screen(_lcd_adjust_z_homing);
}

void menu_xtlw_leveling() {

  auto _recalc_offsets = []{
    if (active_extruder && all_axes_trusted()) {
      queue.inject_P(PSTR("G28"));
      active_extruder = 0;
    }
  };

  START_MENU();
  BACK_ITEM(MSG_MOTION);

  //EDIT_ITEM_FAST(float52sign, MSG_HOME_OFFSET_Z, &home_offset.z, -10.0, 2.0, _recalc_offsets);

  #if ENABLED(CLIMBER)
    EDIT_ITEM_FAST(float52sign, MSG_HOTEND_OFFSET_Z, &hotend_offset[1].z, -10.0, 2.0, _recalc_offsets);
    SUBMENU(MSG_LEVEL_NOZZLE, _lcd_xtlw_level_nozzle);
  #endif
  SUBMENU(MSG_LEVEL_CORNERS, _lcd_xtlw_level_bed_corners);
  SUBMENU(MSG_ADJUST_Z_HOME, _lcd_xtlw_adjust_z_home);
  ACTION_ITEM(MSG_STORE_EEPROM, ui.store_settings);

  END_MENU();
}

#endif 