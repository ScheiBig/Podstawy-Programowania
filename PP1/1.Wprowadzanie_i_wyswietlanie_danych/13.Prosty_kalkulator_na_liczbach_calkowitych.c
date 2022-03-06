#include <stdio.h>

int main()
{
    short int int1, int2;

    printf("Input first number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%hd", &int1);
    printf("Input second number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%hd", &int2);

    printf("%d\n%d\n%d\n%d\n", int1 + int2, int1 - int2, int1 * int2, int1 / int2);

    return 0;
}
