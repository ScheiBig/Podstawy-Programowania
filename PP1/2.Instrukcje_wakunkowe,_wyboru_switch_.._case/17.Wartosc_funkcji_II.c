#include <stdio.h>

#define F1(X)   (2 * X * X + 3 * X - 1)
#define F2(X)   (((X + 5) * (X + 5)) - 10)
#define F3(X)   ((X / 2 - 2) * (2 - 3 * X / 4))

int main()
{
    float x;
    printf("Input x: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%f", &x) != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }
    if (x < -5)
    {
        printf("%f\n", F2(x));
    }
    else if (x > 5)
    {
        printf("%f\n", F3(x));
    }
    else
    {
        printf("%f\n", F1(x));
    }
    return 0;
}
