#include <stdio.h>
#include <stdlib.h>
#include "my_utils.h"

int even_odd(int s, int n);

int main()
{
    int a, n;
    print_ln("Enter a number:");
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &a) != 1)
    {
        _e_exit(1, "Incorrect input")
    }
    print_ln("Enter a index:");
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &n) != 1)
    {
        _e_exit(1, "Incorrect input")
    }
    else if (n < 0)
    {
        _e_exit(2, "Incorrect input data")
    }

    printf_ln("%d", even_odd(a, n));
    return 0;
}

int even_odd(int s, int n)
{
    if (n < 0) return -1;
    else if (n == 0) return s;
    else
    {
        int ret = even_odd(s, n - 1);
        if (ret % 2 == 0)
            return ret / 2;
        else
            return 3 * ret + 1;
    }
}
