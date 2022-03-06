#include <stdio.h>
#include "my_utils.h"

long long binary_exponentiation(long long a, unsigned int n);

int main()
{
    long long a;
    int n;
    print_ln("Enter a number:");
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%lld", &a) != 1)
    {
        _e_exit(1, "Incorrect input")
    }
    print_ln("Enter a power:");
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &n) != 1)
    {
        _e_exit(1, "Incorrect input")
    }
    else if (n < 0)
    {
        _e_exit(2, "Incorrect input data")
    }

    printf_ln("%lld", binary_exponentiation(a, n));
    return 0;
}

long long binary_exponentiation(long long a, unsigned int n)
{
    if (n == 0) return 1LL;
    else if (is_even(n)) return binary_exponentiation(a * a, n / 2);
    else return a * binary_exponentiation(a * a, (n - 1) / 2);
}
