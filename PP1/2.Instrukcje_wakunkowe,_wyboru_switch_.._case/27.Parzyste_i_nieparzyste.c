#include <stdio.h>

int main()
{
    int num, success, comp;
    printf("Input your number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    success = scanf("%d", &num);

    comp = 10 * (success == 1) + num % 2;

    switch (comp)
    {
    case 10:
        printf("%d is even\n", num);
        break;
    case 9:
    case 11:
        printf("%d is odd\n", num);
        break;
    default:
        printf("Incorrect input\n");
        return 1;
    }

    return 0;
}
