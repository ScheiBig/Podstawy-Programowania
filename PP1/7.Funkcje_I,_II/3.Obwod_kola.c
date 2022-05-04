#include <stdio.h>
#include "my_utils.h"
#include <math.h>

float circumference(float a);

int main()
{
    float val;
    print_ln("Enter a number:");

    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide scanf_s
    if (scanf("%f", &val) != 1)
    {
        _e_exit(1, "Incorrect input")
    }
    if ((int)(val = circumference(val)) == -1)
    {
        _e_exit(1, "Incorrect input")
    }
    printf_ln("%f", val);

    return 0;
}

float circumference(float a)
{
    if (a <= 0) return -1;
    return a * (float)M_PI;
}
