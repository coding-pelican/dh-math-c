/**
 * @file dh_math_f32.h
 * @author Gyeongtae Kim(dev-dasae) <codingpelican@gmail.com>
 *
 * @brief Floating-point mathematical functions and types.
 * @details This file contains floating-point mathematical functions and types.
 *
 * @version 0.1
 * @date 2024-09-19
 *
 * @copyright Released under the MIT License. See LICENSE file for details.
 */


#ifndef DH_MATH_F32_H
#define DH_MATH_F32_H

#if defined(__cplusplus)
extern "C" {
#endif // defined(__cplusplus)


// #region Header_File_Inclusions
#include "dh_math_primitive_types.h"
// #endregion // Header_File_Inclusions


// #region Public_Function_Prototypes
#define f32_fromI32(x) ((f32)(x))
#define f32_toI32(x)   ((i32)(x))
i32 _f32_toI32(f32 x);

f32 f32_neg(f32 x);
f32 f32_abs(f32 x);
f32 f32_sign(f32 x);

bool f32_eq(f32 x, f32 y);
bool f32_neq(f32 x, f32 y);
bool f32_lt(f32 x, f32 y);
bool f32_gt(f32 x, f32 y);
bool f32_leq(f32 x, f32 y);
bool f32_geq(f32 x, f32 y);

bool f32_isNan(f32 x);
bool f32_isInf(f32 x);

f32 f32_add(f32 x, f32 y);
f32 f32_sub(f32 x, f32 y);
f32 f32_mul(f32 x, f32 y);
f32 f32_div(f32 x, f32 y);
f32 f32_mod(f32 x, f32 y);

f32 f32_min(f32 x, f32 y);
f32 f32_max(f32 x, f32 y);
f32 f32_clamp(f32 x, f32 low, f32 high);
f32 f32_clamp01(f32 x);
f32 f32_wrap(f32 x, f32 low, f32 high);
f32 f32_wrap01(f32 x);

f32 f32_ceil(f32 x);
f32 f32_floor(f32 x);
f32 f32_round(f32 x);

// f32 f32_rsq(f32 x);
// f32 f32_rsqrt(f32 x);
f32 f32_sqrt(f32 x);
f32 f32_sq(f32 x);

// f32 f32_rcb(f32 x);
// f32 f32_rcbrt(f32 x);
// f32 f32_cbrt(f32 x);
f32 f32_cb(f32 x);

// f32 f32_rqd(f32 x);
// f32 f32_rqdrt(f32 x);
// f32 f32_qdrt(f32 x);
f32 f32_qd(f32 x);

// f32 f32_exp(f32 x);
// f32 f32_exp2(f32 x);
// f32 f32_exp10(f32 x);
// f32 f32_log(f32 x);
// f32 f32_log2(f32 x);
// f32 f32_log10(f32 x);

f32 f32_rcp(f32 x);
f32 f32_pow(f32 x, f32 y);

f32 f32_deg2rad(f32 degrees);
f32 f32_rad2deg(f32 radians);
f32 f32_sin(f32 radians);
f32 f32_cos(f32 radians);
f32 f32_tan(f32 radians);
// f32 f32_sinh(f32 x);
// f32 f32_cosh(f32 x);
// f32 f32_tanh(f32 x);
// f32 f32_asin(f32 x);
// f32 f32_acos(f32 x);
// f32 f32_atan(f32 x);
// f32 f32_asinh(f32 x);
// f32 f32_acosh(f32 x);
// f32 f32_atanh(f32 x);
f32 f32_atan2(f32 y, f32 x);

f32 f32_lerp(f32 a, f32 b, f32 t);
f32 f32_coserp(f32 a, f32 b, f32 t);
f32 f32_accerp(f32 a, f32 b, f32 t);
f32 f32_decerp(f32 a, f32 b, f32 t);
f32 f32_smoothstep(f32 a, f32 b, f32 t);
// #endregion // Public_Function_Prototypes

static f32 const f32_nan     = NAN;
static f32 const f32_inf     = INFINITY;
static f32 const f32_neg_inf = -INFINITY;

static f32 const f32_eps = FLT_EPSILON;
static f32 const f32_pi  = 3.1415926f;
static f32 const f32_tau = 2.0f * f32_pi;


#if defined(__cplusplus)
}
#endif // defined(__cplusplus)

#endif // !DH_MATH_F32_H
