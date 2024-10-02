/**
 * @file dh_math_types.h
 * @author Gyeongtae Kim(dev-dasae) <codingpelican@gmail.com>
 *
 * @brief Primitive types for mathematical functions.
 * @details This file contains primitive types for mathematical functions.
 *
 * @version 0.1
 * @date 2024-09-19
 *
 * @copyright Released under the MIT License. See LICENSE file for details.
 */


#ifndef DH_MATH_PRIMITIVE_TYPES_H
#define DH_MATH_PRIMITIVE_TYPES_H

#if defined(__cplusplus)
extern "C" {
#endif // defined(__cplusplus)


// #region Header_File_Inclusions
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
// #endregion // Header_File_Inclusions


// #region Public_Types
typedef int32_t I32;
typedef I32     i32;
typedef int64_t I64;
typedef I64     i64;

typedef float_t  F32;
typedef F32      f32;
typedef double_t F64;
typedef F64      f64;
// #endregion // Public_Types


#if defined(__cplusplus)
}
#endif // defined(__cplusplus)

#endif // !DH_MATH_PRIMITIVE_TYPES_H
