#include <stdio.h>

int main()
{
    float num;
    printf("Input your number: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%f", &num) == 1)
    {
        if (num > 0)
        {
            printf("dodatnia\n");
        }
        else if (num == 0)
        {
            printf("zerowa\n");
        }
        else
        {
            printf("ujemna\n");
        }
    }
    else
    {
        printf("Incorrect input\n");
        return 1;
    }
    return 0;
}