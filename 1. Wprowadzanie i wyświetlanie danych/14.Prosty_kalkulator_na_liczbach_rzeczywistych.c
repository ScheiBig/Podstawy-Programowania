#include <stdio.h>

int main()
{
    float float1, float2;

    printf("Input first number: ");
    scanf("%f", &float1);
    printf("Input second number: ");
    scanf("%f", &float2);

    printf("%f\n%f\n%f\n%f\n", float1 + float2, float1 - float2, float1 * float2, float1 / float2);

    return 0;
}
