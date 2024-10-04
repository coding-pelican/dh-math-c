/**
 * @file dh_math_i32.c
 * @author Gyeongtae Kim(dev-dasae) <codingpelican@gmail.com>
 *
 * @brief Integer mathematical functions and types.
 * @details This file contains integer mathematical functions and types.
 *
 * @version 0.1
 * @date 2024-09-19
 *
 * @copyright Released under the MIT License. See LICENSE file for details.
 */


// #region Header_File_Inclusions
#include "dh_math_i32.h"
// #endregion // Header_File_Inclusions


// #region Public_Functions
f32 _i32_toF32(i32 x) { return (f32)x; }

i32 i32_neg(i32 x) { return -x; }
i32 i32_abs(i32 x) { return (x < 0) ? -x : x; }
i32 i32_sign(i32 x) { return (0 < x) - (x < 0); }

bool i32_eq(i32 x, i32 y) { return x == y; }
bool i32_neq(i32 x, i32 y) { return x != y; }
bool i32_lt(i32 x, i32 y) { return x < y; }
bool i32_gt(i32 x, i32 y) { return x > y; }
bool i32_leq(i32 x, i32 y) { return x <= y; }
bool i32_geq(i32 x, i32 y) { return x >= y; }

i32 i32_add(i32 x, i32 y) { return x + y; }
i32 i32_sub(i32 x, i32 y) { return x - y; }
i32 i32_mul(i32 x, i32 y) { return x * y; }
i32 i32_div(i32 x, i32 y) { return x / y; }
i32 i32_mod(i32 x, i32 y) { return x % y; }

i32 i32_min(i32 x, i32 y) { return x < y ? x : y; }
i32 i32_max(i32 x, i32 y) { return x > y ? x : y; }
i32 i32_clamp(i32 x, i32 low, i32 high) { return i32_min(i32_max(x, low), high); }
i32 i32_wrap(i32 x, i32 low, i32 high) {
    const i32 range = high - low;
    const i32 n     = (x - low) % range;
    return n < 0 ? n + low : n + high;
}
// #endregion // Public_Functions
