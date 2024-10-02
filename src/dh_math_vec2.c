/**
 * @file dh_math_vec2.c
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


// #region Header_File_Inclusions
#include "dh_math_vec2.h"
#include "dh_math_f32.h"
#include "dh_math_i32.h"
// #endregion // Header_File_Inclusions


// #region Public_Functions
Vec2i _Vec2f_toI32(Vec2f v) { return Vec2i(i32_fromF32(v.x), i32_fromF32(v.y)); }

Vec2f Vec2f_neg(Vec2f v) { return Vec2f(-v.x, -v.y); }
Vec2f Vec2f_abs(Vec2f v) { return Vec2f(f32_abs(v.x), f32_abs(v.y)); }
Vec2f Vec2f_sign(Vec2f v) { return Vec2f(f32_sign(v.x), f32_sign(v.y)); }

bool Vec2f_eq(Vec2f u, Vec2f v) { return f32_eq(u.x, v.x) && f32_eq(u.y, v.y); }
bool Vec2f_neq(Vec2f u, Vec2f v) { return !Vec2f_eq(u, v); }
bool Vec2f_lt(Vec2f u, Vec2f v) { return f32_lt(u.x, v.x) && f32_lt(u.y, v.y); }
bool Vec2f_gt(Vec2f u, Vec2f v) { return f32_gt(u.x, v.x) && f32_gt(u.y, v.y); }
bool Vec2f_leq(Vec2f u, Vec2f v) { return f32_leq(u.x, v.x) && f32_leq(u.y, v.y); }
bool Vec2f_geq(Vec2f u, Vec2f v) { return f32_geq(u.x, v.x) && f32_geq(u.y, v.y); }

bool Vec2f_isNan(Vec2f v) { return f32_isNan(v.x) || f32_isNan(v.y); }
bool Vec2f_isInf(Vec2f v) { return f32_isInf(v.x) || f32_isInf(v.y); }

Vec2f Vec2f_add(Vec2f u, Vec2f v) { return Vec2f(f32_add(u.x, v.x), f32_add(u.y, v.y)); }
Vec2f Vec2f_sub(Vec2f u, Vec2f v) { return Vec2f(f32_sub(u.x, v.x), f32_sub(u.y, v.y)); }
Vec2f Vec2f_mul(Vec2f u, Vec2f v) { return Vec2f(f32_mul(u.x, v.x), f32_mul(u.y, v.y)); }
Vec2f Vec2f_div(Vec2f u, Vec2f v) { return Vec2f(f32_div(u.x, v.x), f32_div(u.y, v.y)); }
Vec2f Vec2f_mod(Vec2f u, Vec2f v) { return Vec2f(f32_mod(u.x, v.x), f32_mod(u.y, v.y)); }

Vec2f Vec2f_addF32(Vec2f v, f32 s) { return Vec2f_add(v, Vec2f_from(s)); }
Vec2f Vec2f_subF32(Vec2f v, f32 s) { return Vec2f_sub(v, Vec2f_from(s)); }
Vec2f Vec2f_mulF32(Vec2f v, f32 s) { return Vec2f_scale(v, s); }
Vec2f Vec2f_divF32(Vec2f v, f32 s) { return Vec2f_div(v, Vec2f_from(s)); }
Vec2f Vec2f_modF32(Vec2f v, f32 s) { return Vec2f_mod(v, Vec2f_from(s)); }
Vec2f f32_addVec2f(f32 s, Vec2f v) { return Vec2f_add(Vec2f_from(s), v); }
Vec2f f32_subVec2f(f32 s, Vec2f v) { return Vec2f_sub(Vec2f_from(s), v); }
Vec2f f32_mulVec2f(f32 s, Vec2f v) { return Vec2f_scale(v, s); }
Vec2f f32_divVec2f(f32 s, Vec2f v) { return Vec2f_div(Vec2f_from(s), v); }
Vec2f f32_modVec2f(f32 s, Vec2f v) { return Vec2f_mod(Vec2f_from(s), v); }
Vec2f Vec2f_scale(Vec2f v, f32 s) { return Vec2f(f32_mul(v.x, s), f32_mul(v.y, s)); }

Vec2f Vec2f_min(Vec2f u, Vec2f v) { return Vec2f_lt(u, v) ? u : v; }
Vec2f Vec2f_max(Vec2f u, Vec2f v) { return Vec2f_gt(u, v) ? u : v; }
Vec2f Vec2f_clamp(Vec2f v, Vec2f low, Vec2f high) { return Vec2f_min(Vec2f_max(v, low), high); }
Vec2f Vec2f_clamp01(Vec2f v) { return Vec2f_clamp(v, Vec2f_zero, Vec2f_one); }
Vec2f Vec2f_wrap(Vec2f v, Vec2f low, Vec2f high) {
    return Vec2f(f32_wrap(v.x, low.x, high.x), f32_wrap(v.y, low.y, high.y));
}
Vec2f Vec2f_wrap01(Vec2f v) { return Vec2f_wrap(v, Vec2f_zero, Vec2f_one); }

Vec2f Vec2f_floor(Vec2f v) { return Vec2f(f32_floor(v.x), f32_floor(v.y)); }
Vec2f Vec2f_ceil(Vec2f v) { return Vec2f(f32_ceil(v.x), f32_ceil(v.y)); }
Vec2f Vec2f_round(Vec2f v) { return Vec2f(f32_round(v.x), f32_round(v.y)); }

f32 Vec2f_dot(Vec2f u, Vec2f v) { return f32_add(f32_mul(u.x, v.x), f32_mul(u.y, v.y)); }
f32 Vec2f_len(Vec2f v) { return f32_sqrt(Vec2f_lenSq(v)); }
f32 Vec2f_lenSq(Vec2f v) { return Vec2f_dot(v, v); }
f32 Vec2f_mag(Vec2f v) { return Vec2f_len(v); }
f32 Vec2f_magSq(Vec2f v) { return Vec2f_lenSq(v); }
f32 Vec2f_hyp(Vec2f v) { return Vec2f_len(v); }
f32 Vec2f_hypSq(Vec2f v) { return Vec2f_lenSq(v); }
f32 Vec2f_dist(Vec2f u, Vec2f v) { return Vec2f_len(Vec2f_sub(v, u)); }
f32 Vec2f_distSq(Vec2f u, Vec2f v) { return Vec2f_lenSq(Vec2f_sub(v, u)); }

Vec2f Vec2f_norm(Vec2f v) {
    f32 const len = Vec2f_len(v);
    return f32_eq(len, 0.0f) ? Vec2f_zero : Vec2f_divF32(v, len);
}
Vec2f Vec2f_project(Vec2f v, Vec2f n) {
    f32 const len_sq = Vec2f_lenSq(n);
    return f32_eq(len_sq, 0.0f) ? Vec2f_zero : Vec2f_scale(n, f32_div(Vec2f_dot(v, n), len_sq));
}
Vec2f Vec2f_reflect(Vec2f v, Vec2f n) {
    return Vec2f_sub(v, Vec2f_scale(n, f32_mul(2.0f, Vec2f_dot(v, n))));
}

Vec2f Vec2f_skew(Vec2f v) { return Vec2f(-v.y, v.x); }
Vec2f Vec2f_perp(Vec2f v) { return Vec2f_skew(v); }
Vec2f Vec2f_cw90(Vec2f v) { return Vec2f(v.y, -v.x); }

f32   Vec2f_det2(Vec2f u, Vec2f v) { return f32_sub(f32_mul(u.x, v.y), f32_mul(u.y, v.x)); }
f32   Vec2f_cross(Vec2f u, Vec2f v) { return Vec2f_det2(u, v); }
Vec2f Vec2f_crossF32(Vec2f v, f32 s) { return Vec2f(f32_mul(v.y, s), f32_mul(-v.x, s)); }
Vec2f f32_crossVec2f(f32 s, Vec2f v) { return Vec2f(f32_mul(-s, v.y), f32_mul(s, v.x)); }

f32 Vec2f_angle(Vec2f u, Vec2f v) { return f32_atan2(Vec2f_cross(u, v), Vec2f_dot(u, v)); }
f32 Vec2f_shortestArc(Vec2f u, Vec2f v) {
    f32 const angle = Vec2f_angle(u, v);
    return f32_min(angle, f32_sub(f32_tau, angle));
}
Vec2f Vec2f_sincos(f32 radians) { return Vec2f(f32_cos(radians), f32_sin(radians)); }

/* f32 Vec2f_angle(Vec2f a, Vec2f b) { return acosf(f32_div(Vec2f_dot(a, b), f32_mul(Vec2f_len(a), Vec2f_len(b)))); }
f32 Vec2f_shortestArc(Vec2f a, Vec2f b) {
    a         = Vec2f_norm(a);
    b         = Vec2f_norm(b);
    f32 c     = Vec2f_dot(a, b);
    f32 s     = Vec2f_det2(a, b);
    f32 theta = acosf(c);
    return (s > 0) ? theta : -theta;
}
Vec2f Vec2f_onUnitCircleFromAngle(f32 radians) {
    return (Vec2f){ .x = f32_cos(radians), .y = f32_sin(radians) };
}
Vec2f Vec2f_rotate(Vec2f v, f32 radians) {
    f32 c_r = f32_cos(radians);
    f32 s_r = f32_sin(radians);
    return (Vec2f){ .x = f32_sub(f32_mul(v.x, c_r), f32_mul(v.y, s_r)),
                    .y = f32_add(f32_mul(v.x, s_r), f32_mul(v.y, c_r)) };
}
Vec2f Vec2f_rotateAround(Vec2f v, Vec2f other, f32 radians) {
    f32 c_r = f32_cos(radians);
    f32 s_r = f32_sin(radians);
    v       = Vec2f_sub(v, other);
    v       = (Vec2f){ .x = f32_sub(f32_mul(v.x, c_r), f32_mul(v.y, s_r)),
                       .y = f32_add(f32_mul(v.x, s_r), f32_mul(v.y, c_r)) };
    return Vec2f_add(v, other);
} */
/* Vec2f Vec2f_RotateAround(Vec2f v, Vec2f other, f32 radians) {
    // Compute cosine and sine values for our i and j vectors.
    f32 cR = f32_cos(radians);
    f32 sR = f32_sin(radians);

    // v - `p`, other - `q`
    // Translate so that q is the origin
    v = Vec2f_Sub(v, other);

    // Rotate p around the origin.
    // p' = p.x * i + p.y * j
    // where i = (cR, sR), j = (-sR, cR)
    // substitute =>
    // p' = p.x * (cR, sR) + p.y * (-sR, cR)
    v = Vec2_new((v.x * cR - v.y * sR), (v.x * sR + v.y * cR));

    // Translate back to q;
    return Vec2f_Add(v, other);
} */
/* f32 Vec2f_atan2(Vec2f v) { return f32_atan2(v.y, v.x); }

Vec2f Vec2f_lerp(Vec2f a, Vec2f b, f32 t) { return Vec2f_add(a, Vec2f_scale(Vec2f_sub(b, a), t)); }
Vec2f Vec2f_bezierQuad(Vec2f a, Vec2f b, Vec2f c, f32 t) {
    f32   u    = f32_sub(1.0f, t);
    f32   ut   = f32_mul(u, t);
    Vec2f auu  = Vec2f_scale(a, f32_mul(u, u));
    Vec2f but2 = Vec2f_scale(b, f32_mul(ut, 2.0f));
    Vec2f ctt  = Vec2f_scale(c, f32_mul(t, t));
    return Vec2f_add(auu, Vec2f_add(but2, ctt));
}
Vec2f Vec2f_bezierCubic(Vec2f a, Vec2f b, Vec2f c, Vec2f d, f32 t) {
    Vec2f e = Vec2f_bezierQuad(a, b, c, t);
    Vec2f f = Vec2f_bezierQuad(b, c, d, t);
    return Vec2f_lerp(e, f, t);
} */


Vec2f _Vec2i_toF32(Vec2i v) { return Vec2f(f32_fromI32(v.x), f32_fromI32(v.y)); }

Vec2i Vec2i_neg(Vec2i v) { return Vec2i(-v.x, -v.y); }
Vec2i Vec2i_abs(Vec2i v) { return Vec2i(i32_abs(v.x), i32_abs(v.y)); }
Vec2i Vec2i_sign(Vec2i v) { return Vec2i(i32_sign(v.x), i32_sign(v.y)); }

bool Vec2i_eq(Vec2i u, Vec2i v) { return i32_eq(u.x, v.x) && i32_eq(u.y, v.y); }
bool Vec2i_neq(Vec2i u, Vec2i v) { return !Vec2i_eq(u, v); }
bool Vec2i_lt(Vec2i u, Vec2i v) { return i32_lt(u.x, v.x) && i32_lt(u.y, v.y); }
bool Vec2i_gt(Vec2i u, Vec2i v) { return i32_gt(u.x, v.x) && i32_gt(u.y, v.y); }
bool Vec2i_leq(Vec2i u, Vec2i v) { return i32_leq(u.x, v.x) && i32_leq(u.y, v.y); }
bool Vec2i_geq(Vec2i u, Vec2i v) { return i32_geq(u.x, v.x) && i32_geq(u.y, v.y); }

Vec2i Vec2i_add(Vec2i u, Vec2i v) { return Vec2i(i32_add(u.x, v.x), i32_add(u.y, v.y)); }
Vec2i Vec2i_sub(Vec2i u, Vec2i v) { return Vec2i(i32_sub(u.x, v.x), i32_sub(u.y, v.y)); }
Vec2i Vec2i_mul(Vec2i u, Vec2i v) { return Vec2i(i32_mul(u.x, v.x), i32_mul(u.y, v.y)); }
Vec2i Vec2i_div(Vec2i u, Vec2i v) { return Vec2i(i32_div(u.x, v.x), i32_div(u.y, v.y)); }
Vec2i Vec2i_mod(Vec2i u, Vec2i v) { return Vec2i(i32_mod(u.x, v.x), i32_mod(u.y, v.y)); }

Vec2i Vec2i_addI32(Vec2i v, i32 s) { return Vec2i_add(v, Vec2i_from(s)); }
Vec2i Vec2i_subI32(Vec2i v, i32 s) { return Vec2i_sub(v, Vec2i_from(s)); }
Vec2i Vec2i_mulI32(Vec2i v, i32 s) { return Vec2i_scale(v, s); }
Vec2i Vec2i_divI32(Vec2i v, i32 s) { return Vec2i(i32_div(v.x, s), i32_div(v.y, s)); }
Vec2i Vec2i_modI32(Vec2i v, i32 s) { return Vec2i(i32_mod(v.x, s), i32_mod(v.y, s)); }
Vec2i i32_addVec2i(i32 s, Vec2i v) { return Vec2i_add(Vec2i_from(s), v); }
Vec2i i32_subVec2i(i32 s, Vec2i v) { return Vec2i_sub(Vec2i_from(s), v); }
Vec2i i32_mulVec2i(i32 s, Vec2i v) { return Vec2i_scale(v, s); }
Vec2i i32_divVec2i(i32 s, Vec2i v) { return Vec2i(i32_div(s, v.x), i32_div(s, v.y)); }
Vec2i i32_modVec2i(i32 s, Vec2i v) { return Vec2i(i32_mod(s, v.x), i32_mod(s, v.y)); }
Vec2i Vec2i_scale(Vec2i v, i32 s) { return Vec2i(i32_mul(v.x, s), i32_mul(v.y, s)); }

Vec2i Vec2i_min(Vec2i u, Vec2i v) { return Vec2i_lt(u, v) ? u : v; }
Vec2i Vec2i_max(Vec2i u, Vec2i v) { return Vec2i_gt(u, v) ? u : v; }
Vec2i Vec2i_clamp(Vec2i v, Vec2i low, Vec2i high) { return Vec2i_min(Vec2i_max(v, low), high); }
Vec2i Vec2i_wrap(Vec2i v, Vec2i low, Vec2i high) {
    return Vec2i(i32_wrap(v.x, low.x, high.x), i32_wrap(v.y, low.y, high.y));
}

i32 Vec2i_dot(Vec2i u, Vec2i v) { return i32_add(i32_mul(u.x, v.x), i32_mul(u.y, v.y)); }
f32 Vec2i_len(Vec2i v) { return f32_sqrt((f32)Vec2i_lenSq(v)); }
i32 Vec2i_lenSq(Vec2i v) { return Vec2i_dot(v, v); }
f32 Vec2i_mag(Vec2i v) { return Vec2i_len(v); }
i32 Vec2i_magSq(Vec2i v) { return Vec2i_lenSq(v); }
f32 Vec2i_hyp(Vec2i v) { return Vec2i_len(v); }
i32 Vec2i_hypSq(Vec2i v) { return Vec2i_lenSq(v); }
f32 Vec2i_dist(Vec2i u, Vec2i v) { return Vec2i_len(Vec2i_sub(u, v)); }
i32 Vec2i_distSq(Vec2i u, Vec2i v) { return Vec2i_lenSq(Vec2i_sub(u, v)); }

Vec2i Vec2i_skew(Vec2i v) { return Vec2i(-v.y, v.x); }
Vec2i Vec2i_perp(Vec2i v) { return Vec2i_skew(v); }
Vec2i Vec2i_cw90(Vec2i v) { return Vec2i(v.x, -v.y); }

i32   Vec2i_det2(Vec2i u, Vec2i v) { return i32_sub(i32_mul(u.x, v.y), i32_mul(u.y, v.x)); }
i32   Vec2i_cross(Vec2i u, Vec2i v) { return i32_sub(i32_mul(u.x, v.y), i32_mul(u.y, v.x)); }
Vec2i Vec2i_crossI32(Vec2i v, i32 s) { return Vec2i(i32_mul(v.x, s), i32_mul(v.y, s)); }
Vec2i i32_crossVec2i(i32 s, Vec2i v) { return Vec2i(i32_mul(s, v.x), i32_mul(s, v.y)); }

f32 Vec2i_angle(Vec2i u, Vec2i v) { return f32_atan2((f32)Vec2i_cross(u, v), (f32)Vec2i_dot(u, v)); }
f32 Vec2i_shortestArc(Vec2i u, Vec2i v) {
    f32 const angle = Vec2i_angle(u, v);
    return f32_min(angle, f32_sub(f32_tau, angle));
}
// #endregion // Public_Functions
