#include <stdio.h>

int main()
{
    int num1, num2;
    char op;

    printf("Input numbers: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    switch (scanf("%d %d", &num1, &num2))
    {
    case 2:
        break;
    default:
        printf("Incorrect input\n");
        return 1;
    }
    printf("Input operation symbol: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    switch (scanf(" %c", &op))
    {
    case 1:
        break;
    default:
        printf("Incorrect input\n");
        return 1;
    }
    switch (op)
    {
    case '+':
        printf("%d\n", num1 + num2);
        break;
    case '-':
        printf("%d\n", num1 - num2);
        break;
    case '*':
        printf("%d\n", num1 * num2);
        break;
    case '/':
        switch (num2)
        {
        case 0:
            printf("Illegal operation\n");
            return 2;
        default:
            printf("%.2f\n", (float)num1 / num2);
            break;
        }
        break;
    default:
        printf("Incorrect input\n");
        return 1;
    }

    return 0;
}
