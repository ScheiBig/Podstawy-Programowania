#include <stdio.h>
#include "my_utils.h"
#include <math.h>

float add(float, float);

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

    return 0;
}

float add(float v1, float v2)
{
    return v1 + v2;
}
