/**
 * @file dh_math.h
 * @author Gyeongtae Kim(dev-dasae) <codingpelican@gmail.com>
 *
 * @brief Mathematical functions and types.
 * @details This file contains mathematical functions and types.
 *
 * @version 0.1
 * @date 2024-09-19
 *
 * @copyright Released under the MIT License. See LICENSE file for details.
 */


#ifndef DH_MATH_H
#define DH_MATH_H

#if defined(__cplusplus)
extern "C" {
#endif // defined(__cplusplus)


// #region Header_File_Inclusions
#include "dh_math_vec2.h"
// #endregion // Header_File_Inclusions


// TODO(dev-dasae): Add type error handling
// #region Pre-Processor_Definitions
#define math_toI32(_x) (     \
    _Generic(                \
        (_x),                \
        f32: _f32_toI32,     \
        i32: 0,              \
        Vec2f: _Vec2f_toI32, \
        Vec2i: 0,            \
        default: 0           \
    )(_x)                    \
)
#define math_toF32(_x) (     \
    _Generic(                \
        (_x),                \
        f32: 0,              \
        i32: _i32_toF32,     \
        Vec2f: 0,            \
        Vec2i: _Vec2i_toF32, \
        default: 0           \
    )(_x)                    \
)

#define math_neg(_x) (    \
    _Generic(             \
        (_x),             \
        f32: f32_neg,     \
        i32: i32_neg,     \
        Vec2f: Vec2f_neg, \
        Vec2i: Vec2i_neg, \
        default: 0        \
    )(_x)                 \
)
#define math_abs(_x) (    \
    _Generic(             \
        (_x),             \
        f32: f32_abs,     \
        i32: i32_abs,     \
        Vec2f: Vec2f_abs, \
        Vec2i: Vec2i_abs, \
        default: 0        \
    )(_x)                 \
)
#define math_sign(_x) (    \
    _Generic(              \
        (_x),              \
        f32: f32_sign,     \
        i32: i32_sign,     \
        Vec2f: Vec2f_sign, \
        Vec2i: Vec2i_sign, \
        default: 0         \
    )(_x)                  \
)

#define math_eq(_x, _y) ( \
    _Generic(             \
        (_x),             \
        f32: f32_eq,      \
        i32: i32_eq,      \
        Vec2f: Vec2f_eq,  \
        Vec2i: Vec2i_eq,  \
        default: 0        \
    )(_x, _y)             \
)
#define math_neq(_x, _y) ( \
    _Generic(              \
        (_x),              \
        f32: f32_neq,      \
        i32: i32_neq,      \
        Vec2f: Vec2f_neq,  \
        Vec2i: Vec2i_neq,  \
        default: 0         \
    )(_x, _y)              \
)
#define math_lt(_x, _y) ( \
    _Generic(             \
        (_x),             \
        f32: f32_lt,      \
        i32: i32_lt,      \
        Vec2f: Vec2f_lt,  \
        Vec2i: Vec2i_lt,  \
        default: 0        \
    )(_x, _y)             \
)
#define math_gt(_x, _y) ( \
    _Generic(             \
        (_x),             \
        f32: f32_gt,      \
        i32: i32_gt,      \
        Vec2f: Vec2f_gt,  \
        Vec2i: Vec2i_gt,  \
        default: 0        \
    )(_x, _y)             \
)
#define math_leq(_x, _y) ( \
    _Generic(              \
        (_x),              \
        f32: f32_leq,      \
        i32: i32_leq,      \
        Vec2f: Vec2f_leq,  \
        Vec2i: Vec2i_leq,  \
        default: 0         \
    )(_x, _y)              \
)
#define math_geq(_x, _y) ( \
    _Generic(              \
        (_x),              \
        f32: f32_geq,      \
        i32: i32_geq,      \
        Vec2f: Vec2f_geq,  \
        Vec2i: Vec2i_geq,  \
        default: 0         \
    )(_x, _y)              \
)

#define math_add(_x, _y) (       \
    _Generic(                    \
        (_x),                    \
        f32: _Generic(           \
            (_y),                \
            f32: f32_add,        \
            Vec2f: f32_addVec2f, \
            default: 0           \
        ),                       \
        i32: _Generic(           \
            (_y),                \
            i32: i32_add,        \
            Vec2i: i32_addVec2i, \
            default: 0           \
        ),                       \
        Vec2f: _Generic(         \
            (_y),                \
            Vec2f: Vec2f_add,    \
            f32: Vec2f_addF32,   \
            default: 0           \
        ),                       \
        Vec2i: _Generic(         \
            (_y),                \
            Vec2i: Vec2i_add,    \
            i32: Vec2i_addI32,   \
            default: 0           \
        ),                       \
        default: 0               \
    )(_x, _y)                    \
)
#define math_sub(_x, _y) (       \
    _Generic(                    \
        (_x),                    \
        f32: _Generic(           \
            (_y),                \
            f32: f32_sub,        \
            Vec2f: f32_subVec2f, \
            default: 0           \
        ),                       \
        i32: _Generic(           \
            (_y),                \
            i32: i32_sub,        \
            Vec2i: i32_subVec2i, \
            default: 0           \
        ),                       \
        Vec2f: _Generic(         \
            (_y),                \
            Vec2f: Vec2f_sub,    \
            f32: Vec2f_subF32,   \
            default: 0           \
        ),                       \
        Vec2i: _Generic(         \
            (_y),                \
            Vec2i: Vec2i_sub,    \
            i32: Vec2i_subI32,   \
            default: 0           \
        ),                       \
        default: 0               \
    )(_x, _y)                    \
)
#define math_mul(_x, _y) (       \
    _Generic(                    \
        (_x),                    \
        f32: _Generic(           \
            (_y),                \
            f32: f32_mul,        \
            Vec2f: f32_mulVec2f, \
            default: 0           \
        ),                       \
        i32: _Generic(           \
            (_y),                \
            i32: i32_mul,        \
            Vec2i: i32_mulVec2i, \
            default: 0           \
        ),                       \
        Vec2f: _Generic(         \
            (_y),                \
            Vec2f: Vec2f_mul,    \
            f32: Vec2f_mulF32,   \
            default: 0           \
        ),                       \
        Vec2i: _Generic(         \
            (_y),                \
            Vec2i: Vec2i_mul,    \
            i32: Vec2i_mulI32,   \
            default: 0           \
        ),                       \
        default: 0               \
    )(_x, _y)                    \
)
#define math_div(_x, _y) (       \
    _Generic(                    \
        (_x),                    \
        f32: _Generic(           \
            (_y),                \
            f32: f32_div,        \
            Vec2f: f32_divVec2f, \
            default: 0           \
        ),                       \
        i32: _Generic(           \
            (_y),                \
            i32: i32_div,        \
            Vec2i: i32_divVec2i, \
            default: 0           \
        ),                       \
        Vec2f: _Generic(         \
            (_y),                \
            Vec2f: Vec2f_div,    \
            f32: Vec2f_divF32,   \
            default: 0           \
        ),                       \
        Vec2i: _Generic(         \
            (_y),                \
            Vec2i: Vec2i_div,    \
            i32: Vec2i_divI32,   \
            default: 0           \
        ),                       \
        default: 0               \
    )(_x, _y)                    \
)
#define math_mod(_x, _y) (       \
    _Generic(                    \
        (_x),                    \
        f32: _Generic(           \
            (_y),                \
            f32: f32_mod,        \
            Vec2f: f32_modVec2f, \
            default: 0           \
        ),                       \
        i32: _Generic(           \
            (_y),                \
            i32: i32_mod,        \
            Vec2i: i32_modVec2i, \
            default: 0           \
        ),                       \
        Vec2f: _Generic(         \
            (_y),                \
            Vec2f: Vec2f_mod,    \
            f32: Vec2f_modF32,   \
            default: 0           \
        ),                       \
        Vec2i: _Generic(         \
            (_y),                \
            Vec2i: Vec2i_mod,    \
            i32: Vec2i_modI32,   \
            default: 0           \
        ),                       \
        default: 0               \
    )(_x, _y)                    \
)

#define math_min(_x, _y) ( \
    _Generic(              \
        (_x),              \
        f32: f32_min,      \
        i32: i32_min,      \
        Vec2f: Vec2f_min,  \
        Vec2i: Vec2i_min,  \
        default: 0         \
    )(_x, _y)              \
)
#define math_max(_x, _y) ( \
    _Generic(              \
        (_x),              \
        f32: f32_max,      \
        i32: i32_max,      \
        Vec2f: Vec2f_max,  \
        Vec2i: Vec2i_max,  \
        default: 0         \
    )(_x, _y)              \
)
// [low, high)
#define math_wrap(_x, _low, _high) ( \
    _Generic(                        \
        (_x),                        \
        f32: f32_wrap,               \
        i32: i32_wrap,               \
        Vec2f: Vec2f_wrap,           \
        Vec2i: Vec2i_wrap,           \
        default: 0                   \
    )(_x, _low, _high)               \
)
// [low, high]
#define math_clamp(_x, _low, _high) ( \
    _Generic(                         \
        (_x),                         \
        f32: f32_clamp,               \
        i32: i32_clamp,               \
        Vec2f: Vec2f_clamp,           \
        Vec2i: Vec2i_clamp,           \
        default: 0                    \
    )(_x, _low, _high)                \
)
// #endregion // Pre-Processor_Definitions


#if defined(__cplusplus)
}
#endif // defined(__cplusplus)

#endif // !DH_MATH_H
