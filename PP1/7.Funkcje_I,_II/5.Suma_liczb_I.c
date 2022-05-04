#include <stdio.h>
#include "my_utils.h"
#include <math.h>

int add(int, int);

int main()
{
    int val1, val2;
    print_ln("Enter a first number:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &val1) != 1)
    {
        _e_exit(1, "Incorrect input")
    }
    print_ln("Enter a second number:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &val2) != 1)
    {
        _e_exit(1, "Incorrect input")
    }

    printf_ln("%d", add(val1, val2));

    return 0;
}

int add(int v1, int v2)
{
    return v1 + v2;
}
