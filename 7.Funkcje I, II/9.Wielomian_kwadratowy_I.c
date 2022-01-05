#include <stdio.h>
#include "my_utils.h"
#include <math.h>

float poly(float);

int main()
{
    float val1;
    print_ln("Enter a first number:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%f", &val1) != 1)
    {
        _e_exit(1, "Incorrect input")
    }

    printf_ln("%f", poly(val1));

    return 0;
}

float poly(float x)
{
    return 5 * x * x + 12.55 * x + 0.75;
}
