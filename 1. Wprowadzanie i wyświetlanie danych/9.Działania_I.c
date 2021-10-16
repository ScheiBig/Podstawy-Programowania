#include <stdio.h>

int integer_1 = 13;
int integer_2 = 3;

int main()
{
    printf("%d %d\n", integer_1, integer_2);
    printf("%d\n", integer_1 * integer_2);
    printf("%.2f\n", ((float) integer_1) / integer_2);
    printf("%d\n", integer_1 + integer_2);
    printf("%d\n", integer_1 - integer_2);
    return 0;
}