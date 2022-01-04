#include <stdio.h>

int main()
{
    float float1, float2;

    printf("Input first number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%f", &float1);
    printf("Input second number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%f", &float2);

    printf("%f\n%f\n%f\n%f\n", float1 + float2, float1 - float2, float1 * float2, float1 / float2);

    return 0;
}
