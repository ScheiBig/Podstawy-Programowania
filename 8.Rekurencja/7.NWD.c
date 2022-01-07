#include <stdio.h>
#include <stdlib.h>
#include "my_utils.h"

int GCD(int a, int b);

int main()
{
    int a, b;
    print_ln("Enter a first number:");
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &a) != 1)
    {
        _e_exit(1, "Incorrect input")
    }
    print_ln("Enter a first number:");
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &b) != 1)
    {
        _e_exit(1, "Incorrect input")
    }

    printf_ln("%d", GCD(a, b));
    return 0;
}

int GCD(int a, int b)
{
    if (b == 0) return abs(a);
    else return GCD(b, a % b);
}
