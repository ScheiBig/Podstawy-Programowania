#include <stdio.h>

int main()
{
    float float1, float2;

    printf("Input first number: ");
    if (scanf("%f", &float1) != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }
    printf("Input second number: ");
    if (scanf("%f", &float2) != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }

    printf("sum=%f\ndidfference=%f\nproduct=%f\n", float1 + float2, float1 - float2, float1 * float2);
    if (float2 != 0)
    {
        printf("quotient=%f\n", float1 / float2);
    }
    else
    {
        printf("Operation not permitted\n");
    }

    return 0;
}
