#include <stdio.h>
#include <math.h>

#define PI (atan(1) * 4)

int main()
{
    float radius = 0;
    char buffer[32];
    while (1)
    {
        printf("Input circle radius: ");
        fgets(buffer, sizeof buffer, stdin);
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        radius *= sscanf(buffer, "%f", &radius) == 1;
        if (radius > 1)
        {
            break;
        }
        else
        {
            printf("Incorrect input\n");
        }
    }
    printf("Circumference: %.3f\n", 2 * radius * PI);
    printf("Area: %.3f\n", radius * radius * PI);

    return 0;
}