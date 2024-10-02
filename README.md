# DH Math Library

A lightweight mathematics library for C, focusing on efficient operations for game development and graphics programming.

## Features

- Single-precision floating-point operations (f32)
- Integer operations (i32)
- 2D vector operations (Vec2f)
- Trigonometric functions
- Interpolation functions
- Utility functions for comparison and rounding

## Usage

Include the necessary header files in your C project and use the provided functions:

```c
#include "dh_math_f32.h"
#include "dh_math_i32.h"
#include "dh_math_vec2.h"

// Example usage
f32 result = f32_lerp(0.0f, 1.0f, 0.5f);
Vec2f rounded = Vec2f_round(Vec2f(1.2f, 3.7f));
```

## Function Categories

### Floating-point operations (f32)

- Basic arithmetic (add, subtract, multiply, divide)
- Comparison (less than, greater than, equal)
- Interpolation (lerp, accerp)
- Trigonometric functions (sin, cos)
- Utility functions (sqrt, round, sign)

### Integer operations (i32)

- Basic arithmetic (add, subtract, multiply)
- Comparison (less than, greater than, equal)
- Min/max functions

### 2D Vector operations (Vec2f)

- Vector arithmetic
- Normalization
- Dot product
- Rotation
- Utility functions (round, wrap, isNan)

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is released under the MIT License. See the [LICENSE](./LICENSE) file for more details.

## Contact

For any questions or inquiries, please contact the project author:
- Name: Gyeongtae Kim
- Email: <codingpelican@gmail.com>
