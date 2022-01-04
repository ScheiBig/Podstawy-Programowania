#include <stdio.h>

int main()
{
    float float1, float2;

    printf("Input first number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%f", &float1) != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }
    printf("Input second number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%f", &float2) != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }

    printf("sum=%f\ndidfference=%f\nproduct=%f\n", float1 + float2, float1 - float2, float1 * float2);
    if (float2 != 0)
    {
        printf("quotient=%f\n", float1 / float2);
    }
    else
    {
        printf("Operation not permitted\n");
    }

    return 0;
}
