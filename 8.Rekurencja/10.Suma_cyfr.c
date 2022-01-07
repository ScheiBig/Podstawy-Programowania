#include <stdio.h>
#include "my_utils.h"

int sum_of_digits(long long number);

int main()
{
    long long a;
    print_ln("Enter a number:");
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%lld", &a) != 1)
    {
        _e_exit(1, "Incorrect input")
    }

    printf_ln("%d", sum_of_digits(a));
    return 0;
}

int sum_of_digits(long long number)
{
    if (number < 0) return sum_of_digits(-number);
    else if (number < 10) return (int)number;
    else
    {
        return (int)(number % 10) + sum_of_digits(number / 10);
    }
}
