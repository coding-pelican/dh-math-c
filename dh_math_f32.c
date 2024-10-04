/**
 * @file dh_math_f32.c
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


// #region Header_File_Inclusions
#include "dh_math_f32.h"
// #endregion // Header_File_Inclusions


// #region Public_Functions
i32 _f32_toI32(f32 x) { return (i32)x; }

f32 f32_neg(f32 x) { return -x; }
f32 f32_abs(f32 x) { return fabsf(x); }
f32 f32_sign(f32 x) { return (f32)((i32)(0.0f < x) - (i32)(x < 0.0f)); }

bool f32_eq(f32 x, f32 y) { return fabsf(x - y) <= f32_eps; }
bool f32_neq(f32 x, f32 y) { return !f32_eq(x, y); }
bool f32_lt(f32 x, f32 y) { return x < y - f32_eps; }
bool f32_gt(f32 x, f32 y) { return x > y + f32_eps; }
bool f32_leq(f32 x, f32 y) { return x <= y + f32_eps; }
bool f32_geq(f32 x, f32 y) { return x >= y - f32_eps; }

bool f32_isNan(f32 x) { return isnan(x); }
bool f32_isInf(f32 x) { return isinf(fabsf(x)); }

#define F32_BINARY_OP(name, op) \
    f32 f32_##name(f32 x, f32 y) { return x op y; }
F32_BINARY_OP(add, +)
F32_BINARY_OP(sub, -)
F32_BINARY_OP(mul, *)
F32_BINARY_OP(div, /)
f32 f32_mod(f32 x, f32 y) { return fmodf(x, y); }

#define F32_MIN_MAX(name, op) \
    f32 f32_##name(f32 x, f32 y) { return op(x, y) ? x : y; }
F32_MIN_MAX(min, f32_lt)
F32_MIN_MAX(max, f32_gt)
f32 f32_clamp(f32 x, f32 low, f32 high) { return f32_min(f32_max(x, low), high); }
f32 f32_clamp01(f32 x) { return f32_clamp(x, 0.0f, 1.0f); }
f32 f32_wrap(f32 x, f32 low, f32 high) { return (high - low <= 0.0f) ? x : fmodf(x - low, high - low) + low; }
f32 f32_wrap01(f32 x) { return f32_wrap(x, 0.0f, 1.0f); }

f32 f32_ceil(f32 x) { return ceilf(x); }
f32 f32_floor(f32 x) { return floorf(x); }
f32 f32_round(f32 x) { return roundf(x); }

f32 f32_sqrt(f32 x) { return sqrtf(x); }
f32 f32_sq(f32 x) { return x * x; }
f32 f32_cb(f32 x) { return x * x * x; }
f32 f32_qd(f32 x) { return x * x * x * x; }
f32 f32_rcp(f32 x) { return 1.0f / x; }
f32 f32_pow(f32 x, f32 y) { return powf(x, y); }

#define F32_DEG_RAD_CONV(name, op, val) \
    f32 f32_##name(f32 x) { return (x op val) * (f32_pi / 180.0f); }
F32_DEG_RAD_CONV(deg2rad, *, 1.0f)
F32_DEG_RAD_CONV(rad2deg, /, f32_pi)
f32 f32_sin(f32 radians) { return sinf(radians); }
f32 f32_cos(f32 radians) { return cosf(radians); }
f32 f32_tan(f32 radians) { return tanf(radians); }
f32 f32_atan2(f32 y, f32 x) { return atan2f(-y, -x) + f32_pi; }

f32 f32_lerp(f32 a, f32 b, f32 t) { return a + (b - a) * t; }
f32 f32_coserp(f32 a, f32 b, f32 t) { return f32_lerp(a, b, (1.0f - cosf(t * f32_pi)) * 0.5f); }
f32 f32_accerp(f32 a, f32 b, f32 t) { return f32_lerp(a, b, t * t); }
f32 f32_decerp(f32 a, f32 b, f32 t) { return f32_lerp(a, b, 1.0f - f32_sq(1.0f - t)); }
f32 f32_smoothstep(f32 a, f32 b, f32 t) { return f32_lerp(a, b, t * t * (3.0f - 2.0f * t)); }
// #endregion // Public_Functions
