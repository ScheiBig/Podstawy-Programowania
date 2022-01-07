#include <stdio.h>
#include "my_utils.h"

long int fibonacci(int n);

int main()
{
    int n;
    print_ln("Enter a number:");
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &n) != 1)
    {
        _e_exit(1, "Incorrect input")
    }
    else if (0 > n)
    {
        _e_exit(2, "Incorrect input data")
    }

    printf_ln("%ld", fibonacci(n));
    return 0;
}

long int fibonacci(int n)
{
    if (n < 0) return -1;
    else if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}
