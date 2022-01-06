#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "my_utils.h"

float distance(int x1, int y1, int x2, int y2);
float perimeter(float a, float b, float c);
float area(float a, float b, float c);

int main()
{
    coords2d val1, val2, val3;
    print_ln("Enter a first point:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf(" (%d, %d)", &val1.x, &val1.y) != 2)
    {
        _e_exit(1, "Incorrect input")
    }
    print_ln("Enter a second point:");
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf(" (%d, %d)", &val2.x, &val2.y) != 2)
    {
        _e_exit(1, "Incorrect input")
    }
    // fgets(temp, 15, stdin);
    // printf_ln("%s, %zu", temp, strlen(temp));
    print_ln("Enter a third point:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf(" (%d, %d)", &val3.x, &val3.y) != 2)
    {
        _e_exit(1, "Incorrect input")
    }
    
    float a = distance(val1.x, val1.y, val2.x, val2.y);
    float b = distance(val2.x, val2.y, val3.x, val3.y);
    float c = distance(val3.x, val3.y, val1.x, val1.y);

    double A;
    if ((A = (double)area(a, b, c)) > 0)
    {
        printf_ln("%.2f", A);
    }
    else
    {
        _e_exit(1, "Incorrect input")
    }

    return 0;
}

float distance(int x1, int y1, int x2, int y2)
{
    return sqrtf((float)((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}

float perimeter(float a, float b, float c)
{
    if (a <= 0 || b <= 0 || c <= 0) return -1;
    if (a >= b + c || c >= a + b || b >= c + a) return -1;
    return a + b + c;
}

float area(float a, float b, float c)
{
    float p = perimeter(a, b, c) / 2;
    if (p < 0) return -1;
    return sqrtf(p * (p - a) * (p - b) * (p - c));
}
