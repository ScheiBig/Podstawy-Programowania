#include <stdio.h>

int main()
{
    int num1, num2, success;
    printf("Input first number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    success = scanf("%d", &num1);
    if (success - 1)
    {
        printf("Incorrect input\n");
        return 1;
    }
    printf("Input second number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    success = scanf("%d", &num2);
    if (success - 1)
    {
        printf("Incorrect input\n");
        return 1;
    }
    else if (num2 == 0)
    {
        printf("Operation not permitted\n");
        return 1;
    }

    if (num1 % num2)
    {
        printf("%d is not divisible by %d\n", num1, num2);
    }
    else
    {
        printf("%d is divisible by %d\n", num1, num2);
    }



    return 0;
}
