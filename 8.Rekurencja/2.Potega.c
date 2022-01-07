#include <stdio.h>
#include "my_utils.h"

long power_rec(int a, int n);

int main()
{
    int a, n;
    print_ln("Enter a number:");
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &a) != 1)
    {
        _e_exit(1, "Incorrect input");
    }
    print_ln("Enter a power:");
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &n) != 1)
    {
        _e_exit(1, "Incorrect input");
    }
    else if (0 > n)
    {
        _e_exit(2, "Incorrect input data");
    }

    printf_ln("%ld", power_rec(a, n));

    return 0;
}

long power_rec(int a, int n)
{
    if (n < 0) return 0l;
    else if (n == 0) return 1l;
    else return a * power_rec(a, n - 1);
}
