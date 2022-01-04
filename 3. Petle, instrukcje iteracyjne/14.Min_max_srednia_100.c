#include <stdio.h>
#include <float.h>

int main()
{
    float current, min = FLT_MAX, max = -FLT_MAX;
    long double avg = 0;

    printf("Enter your numbers: ");
    for (int i = 0; i < 100; ++i)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%f", &current) != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        avg += current;
        min = min < current ? min : current;
        max = max > current ? max : current;
    }
    avg /= 100;

    printf("%.2f\n", min);
    printf("%.2f\n", max);
    printf("%.2Lf\n", avg);

    return 0;
}