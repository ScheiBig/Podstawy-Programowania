#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    printf("Input a: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%d", &a);
    printf("Input b: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%d", &b);
    printf("Input c: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%d", &c);

    printf("%.2f\n", sqrt(a * a + b * b + c * c));
    return 0;
}
