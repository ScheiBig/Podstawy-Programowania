#include <stdio.h>

int main()
{
    short int int1, int2;

    printf("Input first number: ");
    scanf("%hd", &int1);
    printf("Input second number: ");
    scanf("%hd", &int2);

    printf("%d\n%d\n%d\n%d\n", int1 + int2, int1 - int2, int1 * int2, int1 / int2);

    return 0;
}
