#include "../src/dh_math.h"
#include <stdio.h>

int main() {
    Vec2f u    = Vec2f_one;
    Vec2f v    = Vec2f_neg_one;
    Vec2f sum  = math_add(u, v);
    Vec2f diff = math_sub(u, v);
    printf("u: %g %g\n", u.mat[0], u.mat[1]);
    printf("v: %g %g\n", v.mat[0], v.mat[1]);
    printf("u + v: %g %g\n", sum.mat[0], sum.mat[1]);
    printf("u - v: %g %g\n", diff.mat[0], diff.mat[1]);
    printf("u == v: %d\n", math_eq(u, v));
    printf("u != v: %d\n", math_neq(u, v));
    printf("u < v: %d\n", math_lt(u, v));
    printf("u > v: %d\n", math_gt(u, v));
    printf("u <= v: %d\n", math_leq(u, v));
    printf("u >= v: %d\n", math_geq(u, v));
    return 0;
}
