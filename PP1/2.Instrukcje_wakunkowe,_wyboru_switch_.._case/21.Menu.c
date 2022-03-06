#include <stdio.h>

int main()
{
    int num1, num2;
    char op;

    printf("Input first number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &num1) != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }
    printf("Input second number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &num2) != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }
    printf("Input operation symbol: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf(" %c", &op) != 1 ||
        (op != '+' && op != '-' && op != '*' && op != '/'))
    {
        printf("Incorrect input\n");
        return 1;
    }
    else if (op == '/' && num2 == 0)
    {
        printf("Operation not permitted\n");
        return 2;
    }

    if (op == '+')
    {
        printf("%d\n", num1 + num2);
    }
    else if (op == '-')
    {
        printf("%d\n", num1 - num2);
    }
    else if (op == '*')
    {
        printf("%d\n", num1 * num2);
    }
    else
    {
        printf("%.2f\n", (float)num1 / num2);
    }

    return 0;
}
