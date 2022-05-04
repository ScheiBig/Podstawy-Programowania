#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "my_utils.h"

float toRadian(float a);
float toDegree(float a);

int main()
{
    int op;
    float angle;
    print_ln("Enter a operation (1: deg -> rad, 2: rad -> deg):");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &op) != 1 || (op != 1 && op != 2))
    {
        _e_exit(1, "Incorrect input")
    }
    print_ln("Enter an angle:");
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%f", &angle) != 1)
    {
        _e_exit(1, "Incorrect input")
    }

    printf_ln("%.2f", op == 1 ? (double)toRadian(angle) : (double)toDegree(angle));

    return 0;
}

float toRadian(float a)
{
    return a * (float)M_PI / 180;
}

float toDegree(float a)
{
    return a * 180 / (float)M_PI;
}
