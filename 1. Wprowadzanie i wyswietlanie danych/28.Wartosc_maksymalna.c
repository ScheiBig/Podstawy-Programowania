#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Input your numbers: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", (a >= b) + (a >= c));
    return 0;
}
