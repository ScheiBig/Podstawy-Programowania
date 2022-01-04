#include <stdio.h>

int main()
{
    int int1, int2;

    printf("Input first number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &int1) != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }
    printf("Input second number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &int2) != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }

    printf("sum=%d\ndidfference=%d\nproduct=%d\n", int1 + int2, int1 - int2, int1 * int2);
    if (int2 != 0)
    {
        printf("quotient=%d\n", int1 / int2);
    }
    else
    {
        printf("Operation not permitted\n");
    }

    return 0;
}
