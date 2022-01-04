#include <stdio.h>

int main()
{
    int min, max;

    printf("Enter a range minimum: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &min) != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Enter a range maximum: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &max) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    else if (min > max)
    {
        printf("Incorrect range");
        return 2;
    }
    else
    {
        for (int i = min; i <= max; ++i)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}