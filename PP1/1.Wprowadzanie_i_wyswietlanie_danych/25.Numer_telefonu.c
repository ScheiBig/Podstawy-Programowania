#include <stdio.h>

#define I(A) ((int) A)

int main()
{
    unsigned int num1, num2, num3, acode;

    printf("Input your phone number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%3u-%2u-%2u", &num1, &num2, &num3);
    printf("Input your area code: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%2u", &acode);
    printf("(%.2u) %.3u-%.2u-%.2u\n", acode, num1, num2, num3);

    return 0;
}
