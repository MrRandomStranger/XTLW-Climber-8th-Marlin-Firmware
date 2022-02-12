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

#include "../../inc/MarlinConfig.h"

#if HAS_HOTEND_OFFSET && ENABLED(XTLW3D)

#include "../gcode.h"
#include "../../module/motion.h"

/**
 * M219 - set hotend offset
 *
 *   T<tool>
 *   X<xoffset> (Relative value)
 *   Y<yoffset> (Relative value)
 */
void GcodeSuite::M219() {

  const int8_t target_extruder = get_target_extruder_from_command();
  if (target_extruder < 0) return;

  if (parser.seenval('X')) hotend_offset[target_extruder].x = parser.value_linear_units() + ABS(hotend_offset[1].x);
  if (parser.seenval('Y')) hotend_offset[target_extruder].y = parser.value_linear_units() + ABS(hotend_offset[1].y);
  if (parser.seenval('Z')) hotend_offset[target_extruder].z = parser.value_linear_units() + ABS(hotend_offset[1].z);

}

#endif
