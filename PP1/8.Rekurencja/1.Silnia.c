#include <stdio.h>
#include "my_utils.h"

unsigned long factorial_rec(int n);

int main()
{
    int n;
    print_ln("Enter a number:");
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &n) != 1)
    {
        _e_exit(1, "Incorrect input")
    }
    else if (0 > n || n > 20)
    {
        _e_exit(2, "Incorrect input data")
    }

    printf_ln("%lu", factorial_rec(n));

    return 0;
}

unsigned long factorial_rec(int n)
{
    if (n < 0) return 0;
    else if (n == 0) return 1;
    else return n * factorial_rec(n - 1);
}
