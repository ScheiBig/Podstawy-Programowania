#include <stdio.h>
#include "my_utils.h"
#include <math.h>

#undef sign

int sign(int value);

enum sign
{
    negative = -1, zero = 0, positive = 1
};

int main()
{
    int val;
    print_ln("Enter a number:");

    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide scanf_s
    switch (scanf("%d", &val))
    {
    case 1: {
        break;
    }
    default:
        _e_exit(1, "Incorrect input")
    }
    
    switch (sign(val))
    {
    case negative:
        print_ln("negative");
        break;
    case zero:
        print_ln("zero");
        break;
    case positive:
        print_ln("positive");
        break;
    }

    return 0;
}

int sign(int value)
{
    return negative * (value < 0) + zero * (value == 0) + positive * (value > 0);
}
