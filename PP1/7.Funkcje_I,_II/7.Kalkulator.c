#include <stdio.h>
#include "my_utils.h"
#include <math.h>

float add(float, float);
float subtract(float, float);
float multiply(float, float);
float divide(float, float);

int main()
{
    float val1, val2;
    print_ln("Enter a first number:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%f", &val1) != 1)
    {
        _e_exit(1, "Incorrect input")
    }
    print_ln("Enter a second number:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%f", &val2) != 1)
    {
        _e_exit(1, "Incorrect input")
    }

    printf_ln("%f", add(val1, val2));
    printf_ln("%f", subtract(val1, val2));
    printf_ln("%f", multiply(val1, val2));
    float div;
    if ((div = divide(val1, val2)) == -1 && val2 == 0)
    {
        print_ln("Operation not permitted");
    }
    else
    {
        printf_ln("%f", div);
    }

    return 0;
}

float add(float v1, float v2)
{
    return v1 + v2;
}

float subtract(float v1, float v2)
{
    return v1 - v2;
}

float multiply(float v1, float v2)
{
    return v1 * v2;
}

float divide(float v1, float v2)
{
    return v2 == 0 ? -1 : v1 / v2;
}
