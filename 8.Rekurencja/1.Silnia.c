#include <stdio.h>
// #include "my_utils.h"

unsigned long factorial_rec(int n);

int main()
{
    int n;
    printf("Enter a number:\n");
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &n) != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }
    else if (0 > n || n > 20)
    {
        printf("Incorrect input data\n");
        return 2;
    }

    printf("%lu\n", factorial_rec(n));

    return 0;
}

unsigned long factorial_rec(int n)
{
    if (n < 0) return 0;
    else if (n == 0) return 1;
    else return n * factorial_rec(n - 1);
}
