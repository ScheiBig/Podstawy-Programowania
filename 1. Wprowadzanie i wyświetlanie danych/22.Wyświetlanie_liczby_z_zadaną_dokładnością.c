#include <stdio.h>

int main()
{
    int prec;
    float num;

    printf("Input your number: ");
    scanf("%f", &num);
    printf("Input desired precision: ");
    scanf("%d", &prec);

    printf("Your output: %.*f\n", prec, num);

    return 0;
}
