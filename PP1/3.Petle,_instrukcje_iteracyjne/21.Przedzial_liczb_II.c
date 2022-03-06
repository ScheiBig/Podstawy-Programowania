#include <stdio.h>
#include <math.h>

int main()
{
    float min, max;

    printf("Enter a range minimum: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%f", &min) != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Enter a range maximum: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%f", &max) != 1)
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
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        for (float i = min; i <= max; i += 0.25)
        {
            printf("%.2f\n", i);
        }
    }

    return 0;
}