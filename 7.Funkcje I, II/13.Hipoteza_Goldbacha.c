#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_utils.h"

int czy_pierwsza(int a);
int goldbach(int x);

int main()
{
    int r_st, r_en;
    print_ln("Enter a first number:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &r_st) != 1)
    {
        _e_exit(1, "Incorrect input")
    }
    print_ln("Enter a second number:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &r_en) != 1 || r_en < r_st)
    {
        _e_exit(1, "Incorrect input")
    }

    for (int i = r_st; i <= r_en; ++i)
    {
        if (i % 2 != 0) continue;
        else goldbach(i);
    }

    return 0;
}

int czy_pierwsza(int a)
{
    if (a < 2) return false;
    double sqr = sqrt(a);
    for (int i = 2; i <= (int)sqr; ++i)
    {
        if (a % i == 0) return false;
    }
    return true;
}

int goldbach(int x)
{
    if (x % 2 != 0) return false;
    pair* pairs = (pair*)calloc((size_t)(0.125 * x + 35), sizeof(pair));
    size_t pair_cnt = 0;

    printf("%d: ", x);
    for (int i = 2; i <= x / 2; ++i)
    {
        if (!czy_pierwsza(i)) continue;
        if (!czy_pierwsza(x - i)) continue;
        pairs[pair_cnt++] = (pair){ x - i, i };
        printf("(%d, %d)", i, x - i);
    }

    int ret = !!pair_cnt;
    pair_cnt = pair_cnt > 0 ? pair_cnt - 1 : 0;
    if (pairs[pair_cnt].a != pairs[pair_cnt].b) printf("(%d, %d)", pairs[pair_cnt].a, pairs[pair_cnt].b);
    for (int i = (int)pair_cnt - 1; i >= 0; --i)
    {
        printf("(%d, %d)", pairs[i].a, pairs[i].b);
    }

    free(pairs);
    print_n();
    return ret;
}
