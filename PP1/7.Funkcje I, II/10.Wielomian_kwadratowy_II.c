#include <stdio.h>
#include "my_utils.h"
#include <math.h>

float quadratic_equation(float a, float b, float c, float x);

int main()
{
    float vala, valb, valc, valx;
    print_ln("Enter a function formula:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%fx^2%fx%f", &vala, &valb, &valc) != 3)
    {
        _e_exit(1, "Incorrect input")
    }
    print_ln("Enter x argument:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%f", &valx) != 1)
    {
        _e_exit(1, "Incorrect input")
    }

    printf_ln("%f", quadratic_equation(vala, valb, valc, valx));

    return 0;
}

float quadratic_equation(float a, float b, float c, float x)
{
    return a * x * x + b * x + c;
}
