#include <stdio.h>

#define LEFT(A, B)  ((A + B) * (A - B))
#define RIGHT(A, B) ((A * A) + (B * B))

int main()
{
    float a, b;

    printf("Input value a: ");
    if (scanf("%f", &a) != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }

    printf("Input value b: ");
    if (scanf("%f", &b) != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }

    if (RIGHT(a, b) == LEFT(a, b))
    {
        printf("tozsamosc jest prawdziwa\n");
    }
    else
    {
        printf("tozsamosc nie jest prawdziwa\n");
    }

    return 0;
}
