#include <stdio.h>

int main()
{
    int num, success;

    printf("Input your numer: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    success = scanf("%d", &num);

    if (success - 1)
    {
        printf("Incorrect input\n");
        return 1;
    }

    if (num)
    {
        printf("Not equal to zero\n");
    }
    else
    {
        printf("Equal to zero\n");
    }
    return 0;
}
