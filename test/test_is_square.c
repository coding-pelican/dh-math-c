#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef float_t f32;
typedef int32_t i32;
typedef int64_t i64;

typedef struct Vec2i Vec2i;
struct Vec2i {
    i32 x, // @brief first component
        y; // @brief second component
};
#define Vec2i(...) ((Vec2i){ __VA_ARGS__ })

bool Vec2i_eq(Vec2i u, Vec2i v) { return u.x == v.x && u.y == v.y; }
bool Vec2i_neq(Vec2i u, Vec2i v) { return u.x != v.x || u.y != v.y; }
bool Vec2i_lt(Vec2i u, Vec2i v) { return u.x < v.x && u.y < v.y; }
bool Vec2i_gt(Vec2i u, Vec2i v) { return u.x > v.x && u.y > v.y; }
bool Vec2i_leq(Vec2i u, Vec2i v) { return u.x <= v.x && u.y <= v.y; }
bool Vec2i_geq(Vec2i u, Vec2i v) { return u.x >= v.x && u.y >= v.y; }

Vec2i Vec2i_add(Vec2i u, Vec2i v) { return Vec2i(u.x + v.x, u.y + v.y); }
Vec2i Vec2i_sub(Vec2i u, Vec2i v) { return Vec2i(u.x - v.x, u.y - v.y); }
Vec2i Vec2i_mul(Vec2i u, Vec2i v) { return Vec2i(u.x * v.x, u.y * v.y); }
Vec2i Vec2i_div(Vec2i u, Vec2i v) { return Vec2i(u.x / v.x, u.y / v.y); }
Vec2i Vec2i_mod(Vec2i u, Vec2i v) { return Vec2i(u.x % v.x, u.y % v.y); }

i32 Vec2i_dot(Vec2i u, Vec2i v) { return u.x * v.x + u.y * v.y; }
i64 Vec2i_lenSq(Vec2i v) { return (i64)v.x * v.x + (i64)v.y * v.y; }

int compareVec2i(const void* a, const void* b) {
    Vec2i* va = (Vec2i*)a;
    Vec2i* vb = (Vec2i*)b;

    if (va->x != vb->x) {
        return va->x - vb->x;
    }
    return va->y - vb->y;
}

bool isSquare(Vec2i sample[4]) {
    // Sort the points
    qsort(sample, 4, sizeof(Vec2i), compareVec2i);

    // Calculate squared lengths
    i64 d1 = Vec2i_lenSq(Vec2i_sub(sample[3], sample[0])); // diagonal
    i64 s1 = Vec2i_lenSq(Vec2i_sub(sample[1], sample[0])); // side 1
    i64 s2 = Vec2i_lenSq(Vec2i_sub(sample[2], sample[0])); // side 2

    // Check if it's a square
    return 0 < s1 && s1 == s2 && s1 + s2 == d1;
}

int main() {
    int T = 0;
    (void)scanf("%d", &T);

    for (int t = 0; t < T; ++t) {
        Vec2i sample[4] = { 0 };
        for (int i = 0; i < 4; ++i) {
            (void)scanf("%d %d", &sample[i].x, &sample[i].y);
        }
        printf("%d\n", isSquare(sample));
    }

    return 0;
}
