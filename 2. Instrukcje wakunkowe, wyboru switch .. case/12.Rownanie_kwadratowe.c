#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    printf("Input quadratic formula coefficients\n");
    printf("a: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%f", &a);
    printf("b: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%f", &b);
    printf("c: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%f", &c);

    float delta = b * b - 4 * a * c;
    float delta_sq = sqrt(delta);

    if (!a && !b && !c)
    {
        printf("nieskonczonosc\n");
    }
    else if (!a && !b)
    {
        printf("brak\n");
    }
    else if (!a)
    {
        printf("jeden pierwiastek: %f\n", -c / b);
    }
    else if (delta > 0)
    {
        float x1 = (-b + delta_sq) / (2 * a);
        float x2 = (-b - delta_sq) / (2 * a);
        printf("dwa pierwiastki: %f %f\n", x1, x2);
    }
    else if (delta == 0)
    {
        float x = (-b) / (2 * a);
        printf("jeden pierwiastek: %f\n", x);
    }
    else
    {
        printf("brak\n");
    }

    return 0;
}
