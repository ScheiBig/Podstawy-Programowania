#include <stdio.h>

int main()
{
    int prec;
    float num;

    printf("Input your number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%f", &num);
    printf("Input desired precision: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%d", &prec);

    printf("Your output: %.*f\n", prec, num);

    return 0;
}
