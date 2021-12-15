#include <stdio.h>
#include <math.h>


int main()
{
    float numbers[10];
    double sum = 0;
    printf("Enter 10 numbers: ");
    if (scanf("%f %f %f %f %f %f %f %f %f %f", numbers, numbers + 1, numbers + 2, numbers + 3, numbers + 4, numbers + 5,
        numbers + 6, numbers + 7, numbers + 8, numbers + 9) != 10)
    {
        printf("Incorrect input");
        return 1;
    }

    for (int i = 0; i < 10; ++i)
    {
        sum += fabsf(numbers[i]);
    }
    printf("Sum: %.2lf", sum);

    return 0;
}