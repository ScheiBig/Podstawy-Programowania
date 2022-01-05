#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "my_utils.h"

int is_prime(int a);

int main()
{
    int r_st, r_en;
    print_ln("Enter a first number:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%int", &r_st) != 1)
    {
        _e_exit(1, "Incorrect input")
    }
    print_ln("Enter a second number:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%int", &r_en) != 1 || r_en < r_st)
    {
        _e_exit(1, "Incorrect input")
    }

    int count = 0;

    for (int i = r_st; i <= r_en; ++i)
    {
        if (is_prime(i))
        {
            printf("%d ", i);
            ++count;
        }
    }

    if (!count)
    {
        print_ln("Nothing to show");
    }
    else
    {
        print_n();
    }

    return 0;
}

int is_prime(int a)
{
    if (a < 2) return 0;
    double sqr = sqrt(a);
    for (int i = 2; i <= (int)sqr; ++i)
    {
        if (a % i == 0) return 0;
    }
    return 1;
}
