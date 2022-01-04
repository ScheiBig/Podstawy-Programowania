#include <stdio.h>

int main()
{
    int num, success, comp;
    printf("Input your number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    success = scanf("%d", &num);

    comp = 10 * (success == 1) + 1 * (num < 0) + 2 * (num == 0) + 3 * (num > 0);

    switch (comp)
    {
    case 11:
        printf("%d is negative\n", num);
        break;
    case 12:
        printf("%d is equal to 0\n", num);
        break;
    case 13:
        printf("%d is positive\n", num);
        break;
    default:
        printf("Incorrect input\n");
        return 1;
    }

    return 0;
}
