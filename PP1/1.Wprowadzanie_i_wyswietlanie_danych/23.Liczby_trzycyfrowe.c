#include <stdio.h>

#define I(A) ((int) A)

int main()
{
    int num = 0;

    printf("Input your sequence: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%9d", &num);
    printf("%.3d\n%.3d\n%.3d\n",
        (num / I(1E+6)) % I(1E+3),
        (num / I(1E+3)) % I(1E+3),
        num % I(1E+3));

    return 0;
}
