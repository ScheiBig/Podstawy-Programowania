#include <stdio.h>
#include "my_utils.h"

int sqr(int a);

int main()
{
    int val;
    print_ln("Enter a number:");

    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide scanf_s
    if (scanf("%d", &val) != 1)
    {
        _e_exit(1, "Incorrect input")
    }
    printf_ln("%d", sqr(val));

    return 0;
}

int sqr(int a)
{
    return a * a;
}
