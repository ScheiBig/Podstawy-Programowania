#include <stdio.h>

int main()
{
    char sign;
    int real, success;
    unsigned int imag;

    printf("Input complex number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    success = scanf("%d%ci%u", &real, &sign, &imag);
    printf("%d%c%ui\n%d\n", real, sign, imag, success);

    return 0;
}
