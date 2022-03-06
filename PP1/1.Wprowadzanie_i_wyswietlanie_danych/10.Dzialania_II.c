#include <stdio.h>

float integer_1 = 13.25;
float integer_2 = 3.5;

int main()
{
    printf("%f %f\n", integer_1, integer_2);
    printf("%f\n", integer_1 * integer_2);
    printf("%.2f\n", ((float)integer_1) / integer_2);
    printf("%f\n", integer_1 + integer_2);
    printf("%f\n", integer_1 - integer_2);
    return 0;
}