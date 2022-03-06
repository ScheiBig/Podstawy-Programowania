#include <stdio.h>
#include "my_utils.h"

int test1(int a);

int main()
{
    int val;
    print_ln("Enter a number:");

    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide scanf_s
    if (scanf("%d", &val) != 1)
    {
        _e_exit(1, "Incorrect input")
    }
    printf_ln("%d", test1(val));

    return 0;
}

int test1(int a)
{
    return a;
}
