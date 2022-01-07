#include <stdio.h>
#include "my_utils.h"

unsigned long sum_rec(int n);

int main()
{
    int n;
    print_ln("Enter a number:");
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &n) != 1)
    {
        _e_exit(1, "Incorrect input")
    }
    else if (0 >= n)
    {
        _e_exit(2, "Incorrect input data")
    }

    printf_ln("%lu", sum_rec(n));
    return 0;
}

unsigned long sum_rec(int n)
{
    if (n < 1) return 0;
    else if (n == 1) return 1;
    else return (unsigned)n + sum_rec(n - 1);
}
