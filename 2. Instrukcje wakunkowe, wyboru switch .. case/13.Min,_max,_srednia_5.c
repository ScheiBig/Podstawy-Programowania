#include <stdio.h>

int main()
{
    float min, max, avg, num1, num2, num3, num4, num5;

    printf("Input 5 numbers:\n");
    scanf("%f %f %f %f %f", &num1, &num2, &num3, &num4, &num5);

    avg = (num1 + num2 + num3 + num4 + num5) / 5;
    max = num1;
    min = num1;
    if (max < num2) max = num2;
    if (min > num2) min = num2;
    if (max < num3) max = num3;
    if (min > num3) min = num3;
    if (max < num4) max = num4;
    if (min > num4) min = num4;
    if (max < num5) max = num5;
    if (min > num5) min = num5;

    printf("%f\n%f\n%.2f\n", min, max, avg);
    return 0;
}
