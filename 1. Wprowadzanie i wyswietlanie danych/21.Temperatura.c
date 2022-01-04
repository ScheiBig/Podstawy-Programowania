#include <stdio.h>

int main()
{
    float c, f, k;
    printf("Input temperature in °C: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%f", &c);
    f = 32 + c * 1.8;
    k = c + 273.15;
    printf("Temperature in K: %.2f\n", k);
    printf("Temperature in °F: %.2f\n", f);
    return 0;
}
