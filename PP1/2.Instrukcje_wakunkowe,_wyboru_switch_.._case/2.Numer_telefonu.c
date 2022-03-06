#include <stdio.h>

int main()
{
    int acode, num1, num2, num3, success;
    printf("Input your phone number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    success = scanf("(%2d) %3d-%2d-%2d", &acode, &num1, &num2, &num3);
    if (success != 4)
    {
        printf("Incorrect input\n");
        return 1;
    }

    printf("Area code: %2.2d\n", acode);
    printf("Phone number: %3.3d-%2.2d-%2.2d\n", num1, num2, num3);
    return 0;
}
