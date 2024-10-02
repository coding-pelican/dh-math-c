/**
 * @file dh_math_vec2.h
 * @author Gyeongtae Kim(dev-dasae) <codingpelican@gmail.com>
 *
 * @brief Vector2 mathematical functions and types.
 * @details This file contains vector2 mathematical functions and types.
 *
 * @version 0.1
 * @date 2024-09-21
 *
 * @copyright Released under the MIT License. See LICENSE file for details.
 */


#ifndef DH_MATH_VEC2_H
#define DH_MATH_VEC2_H

#if defined(__cplusplus)
extern "C" {
#endif // defined(__cplusplus)


// #region Header_File_Inclusions
#include "dh_math_f32.h"
#include "dh_math_i32.h"
#include "dh_math_primitive_types.h"
// #endregion // Header_File_Inclusions


// #region Public_Types
typedef struct Vec2f Vec2f;
struct Vec2f {
    union {
        f32 mat[2];
        struct {
            f32 x, // @brief first component
                y; // @brief second component
        };
    };
};

typedef struct Vec2i Vec2i;
struct Vec2i {
    union {
        i32 mat[2];
        struct {
            i32 x, // @brief first component
                y; // @brief second component
        };
    };
};
// #endregion // Public_Types

// #region Public_Function_Prototypes_With_Data
#define Vec2f(...)        ((Vec2f){ .mat = { __VA_ARGS__ } })
#define Vec2f_from(_s)    (Vec2f(_s, _s))
#define Vec2f_fromI32(_s) (Vec2f_from((f32)(_s)));
#define Vec2f_toI32(_v)   (Vec2i(i32_fromF32((_v).x), i32_fromF32((_v).y)))
Vec2i _Vec2f_toI32(Vec2f v);

Vec2f Vec2f_neg(Vec2f v);
Vec2f Vec2f_abs(Vec2f v);
Vec2f Vec2f_sign(Vec2f v);

bool Vec2f_eq(Vec2f u, Vec2f v);
bool Vec2f_neq(Vec2f u, Vec2f v);
bool Vec2f_lt(Vec2f u, Vec2f v);
bool Vec2f_gt(Vec2f u, Vec2f v);
bool Vec2f_leq(Vec2f u, Vec2f v);
bool Vec2f_geq(Vec2f u, Vec2f v);

bool Vec2f_isNan(Vec2f v);
bool Vec2f_isInf(Vec2f v);

Vec2f Vec2f_add(Vec2f u, Vec2f v);
Vec2f Vec2f_sub(Vec2f u, Vec2f v);
Vec2f Vec2f_mul(Vec2f u, Vec2f v);
Vec2f Vec2f_div(Vec2f u, Vec2f v);
Vec2f Vec2f_mod(Vec2f u, Vec2f v);

Vec2f Vec2f_addF32(Vec2f v, f32 s);
Vec2f Vec2f_subF32(Vec2f v, f32 s);
Vec2f Vec2f_mulF32(Vec2f v, f32 s);
Vec2f Vec2f_divF32(Vec2f v, f32 s);
Vec2f Vec2f_modF32(Vec2f v, f32 s);
Vec2f f32_addVec2f(f32 s, Vec2f v);
Vec2f f32_subVec2f(f32 s, Vec2f v);
Vec2f f32_mulVec2f(f32 s, Vec2f v);
Vec2f f32_divVec2f(f32 s, Vec2f v);
Vec2f f32_modVec2f(f32 s, Vec2f v);
Vec2f Vec2f_scale(Vec2f v, f32 s);

Vec2f Vec2f_min(Vec2f u, Vec2f v);
Vec2f Vec2f_max(Vec2f u, Vec2f v);
Vec2f Vec2f_clamp(Vec2f v, Vec2f low, Vec2f high);
Vec2f Vec2f_clamp01(Vec2f v);
Vec2f Vec2f_wrap(Vec2f v, Vec2f low, Vec2f high);
Vec2f Vec2f_wrap01(Vec2f v);

Vec2f Vec2f_floor(Vec2f v);
Vec2f Vec2f_ceil(Vec2f v);
Vec2f Vec2f_round(Vec2f v);

f32 Vec2f_dot(Vec2f u, Vec2f v);
f32 Vec2f_len(Vec2f v);
f32 Vec2f_lenSq(Vec2f v);
f32 Vec2f_mag(Vec2f v);
f32 Vec2f_magSq(Vec2f v);
f32 Vec2f_hyp(Vec2f v);
f32 Vec2f_hypSq(Vec2f v);
f32 Vec2f_dist(Vec2f u, Vec2f v);
f32 Vec2f_distSq(Vec2f u, Vec2f v);

Vec2f Vec2f_norm(Vec2f v);
Vec2f Vec2f_project(Vec2f v, Vec2f n);
Vec2f Vec2f_reflect(Vec2f v, Vec2f n);

Vec2f Vec2f_skew(Vec2f v);
Vec2f Vec2f_perp(Vec2f v);
Vec2f Vec2f_cw90(Vec2f v);

f32   Vec2f_det2(Vec2f u, Vec2f v);
f32   Vec2f_cross(Vec2f u, Vec2f v);
Vec2f Vec2f_crossF32(Vec2f v, f32 s);
Vec2f f32_crossVec2f(f32 s, Vec2f v);

f32   Vec2f_angle(Vec2f u, Vec2f v);
f32   Vec2f_shortestArc(Vec2f u, Vec2f v);
Vec2f Vec2f_sincos(f32 radians);

static Vec2f const Vec2f_nan     = Vec2f_from(f32_nan);
static Vec2f const Vec2f_inf     = Vec2f_from(f32_inf);
static Vec2f const Vec2f_neg_inf = Vec2f_from(f32_neg_inf);

static Vec2f const Vec2f_zero    = Vec2f_from(0.0f);
static Vec2f const Vec2f_one     = Vec2f_from(1.0f);
static Vec2f const Vec2f_neg_one = Vec2f_from(-1.0f);

static Vec2f const Vec2f_unit_x     = Vec2f(1.0f, 0.0f);
static Vec2f const Vec2f_unit_y     = Vec2f(0.0f, 1.0f);
static Vec2f const Vec2f_neg_unit_x = Vec2f(-1.0f, 0.0f);
static Vec2f const Vec2f_neg_unit_y = Vec2f(0.0f, -1.0f);

static Vec2f const Vec2f_up    = Vec2f(0.0f, 1.0f);
static Vec2f const Vec2f_left  = Vec2f(-1.0f, 0.0f);
static Vec2f const Vec2f_right = Vec2f(1.0f, 0.0f);
static Vec2f const Vec2f_down  = Vec2f(0.0f, -1.0f);


#define Vec2i(...)        ((Vec2i){ .mat = { __VA_ARGS__ } })
#define Vec2i_from(_s)    (Vec2i(_s, _s))
#define Vec2i_fromF32(_s) (Vec2i_from((i32)(_s)))
#define Vec2i_toF32(_v)   (Vec2f(f32_fromI32((_v).x), f32_fromI32((_v).y)))
Vec2f _Vec2i_toF32(Vec2i v);

Vec2i Vec2i_neg(Vec2i v);
Vec2i Vec2i_abs(Vec2i v);
Vec2i Vec2i_sign(Vec2i v);

bool Vec2i_eq(Vec2i u, Vec2i v);
bool Vec2i_neq(Vec2i u, Vec2i v);
bool Vec2i_lt(Vec2i u, Vec2i v);
bool Vec2i_gt(Vec2i u, Vec2i v);
bool Vec2i_leq(Vec2i u, Vec2i v);
bool Vec2i_geq(Vec2i u, Vec2i v);

Vec2i Vec2i_add(Vec2i u, Vec2i v);
Vec2i Vec2i_sub(Vec2i u, Vec2i v);
Vec2i Vec2i_mul(Vec2i u, Vec2i v);
Vec2i Vec2i_div(Vec2i u, Vec2i v);
Vec2i Vec2i_mod(Vec2i u, Vec2i v);

Vec2i Vec2i_addI32(Vec2i v, i32 s);
Vec2i Vec2i_subI32(Vec2i v, i32 s);
Vec2i Vec2i_mulI32(Vec2i v, i32 s);
Vec2i Vec2i_divI32(Vec2i v, i32 s);
Vec2i Vec2i_modI32(Vec2i v, i32 s);
Vec2i i32_addVec2i(i32 s, Vec2i v);
Vec2i i32_subVec2i(i32 s, Vec2i v);
Vec2i i32_mulVec2i(i32 s, Vec2i v);
Vec2i i32_divVec2i(i32 s, Vec2i v);
Vec2i i32_modVec2i(i32 s, Vec2i v);
Vec2i Vec2i_scale(Vec2i v, i32 s);

Vec2i Vec2i_min(Vec2i u, Vec2i v);
Vec2i Vec2i_max(Vec2i u, Vec2i v);
Vec2i Vec2i_clamp(Vec2i v, Vec2i low, Vec2i high);
Vec2i Vec2i_wrap(Vec2i v, Vec2i low, Vec2i high);

i32 Vec2i_dot(Vec2i u, Vec2i v);
f32 Vec2i_len(Vec2i v);
i32 Vec2i_lenSq(Vec2i v);
f32 Vec2i_mag(Vec2i v);
i32 Vec2i_magSq(Vec2i v);
f32 Vec2i_hyp(Vec2i v);
i32 Vec2i_hypSq(Vec2i v);
f32 Vec2i_dist(Vec2i u, Vec2i v);
i32 Vec2i_distSq(Vec2i u, Vec2i v);

Vec2i Vec2i_skew(Vec2i v);
Vec2i Vec2i_perp(Vec2i v);
Vec2i Vec2i_cw90(Vec2i v);

i32   Vec2i_det2(Vec2i u, Vec2i v);
i32   Vec2i_cross(Vec2i u, Vec2i v);
Vec2i Vec2i_crossI32(Vec2i v, i32 s);
Vec2i i32_crossVec2i(i32 s, Vec2i v);

f32 Vec2i_angle(Vec2i u, Vec2i v);
f32 Vec2i_shortestArc(Vec2i u, Vec2i v);

static Vec2i const Vec2i_min_value = Vec2i_from(i32_min_value);
static Vec2i const Vec2i_max_value = Vec2i_from(i32_max_value);

static Vec2i const Vec2i_zero    = Vec2i_from(0);
static Vec2i const Vec2i_one     = Vec2i_from(1);
static Vec2i const Vec2i_neg_one = Vec2i_from(-1);

static Vec2i const Vec2i_unit_x     = Vec2i(1, 0);
static Vec2i const Vec2i_unit_y     = Vec2i(0, 1);
static Vec2i const Vec2i_neg_unit_x = Vec2i(-1, 0);
static Vec2i const Vec2i_neg_unit_y = Vec2i(0, -1);

static Vec2i const Vec2i_up    = Vec2i(0, 1);
static Vec2i const Vec2i_left  = Vec2i(-1, 0);
static Vec2i const Vec2i_right = Vec2i(1, 0);
static Vec2i const Vec2i_down  = Vec2i(0, -1);
// #endregion // Public_Function_Prototypes_With_Data


#if defined(__cplusplus)
}
#endif // defined(__cplusplus)

#endif // !DH_MATH_VEC2_H
