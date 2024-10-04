/**
 * @file dh_math_i32.h
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


#ifndef DH_MATH_I32_H
#define DH_MATH_I32_H

#if defined(__cplusplus)
extern "C" {
#endif // defined(__cplusplus)


// #region Header_File_Inclusions
#include "dh_math_primitive_types.h"
// #endregion // Header_File_Inclusions


// #region Public_Function_Prototypes
#define i32_fromF32(x) ((i32)(x))
#define i32_toF32(x)   ((f32)(x))
f32 _i32_toF32(i32 x);

i32 i32_neg(i32 x);
i32 i32_abs(i32 x);
i32 i32_sign(i32 x);

bool i32_eq(i32 x, i32 y);
bool i32_neq(i32 x, i32 y);
bool i32_lt(i32 x, i32 y);
bool i32_gt(i32 x, i32 y);
bool i32_leq(i32 x, i32 y);
bool i32_geq(i32 x, i32 y);

i32 i32_add(i32 x, i32 y);
i32 i32_sub(i32 x, i32 y);
i32 i32_mul(i32 x, i32 y);
i32 i32_div(i32 x, i32 y);
i32 i32_mod(i32 x, i32 y);

i32 i32_min(i32 x, i32 y);
i32 i32_max(i32 x, i32 y);
i32 i32_clamp(i32 x, i32 low, i32 high);
i32 i32_wrap(i32 x, i32 low, i32 high);
// #endregion // Public_Function_Prototypes

static i32 const i32_min_value = INT32_MIN;
static i32 const i32_max_value = INT32_MAX;


#if defined(__cplusplus)
}
#endif // defined(__cplusplus)

#endif // !DH_MATH_I32_H
