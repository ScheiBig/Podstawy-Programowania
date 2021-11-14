#include <stdio.h>
#include <math.h>


int main()
{
    float current;
    long double product = 1;

    while (INFINITY)
    {
        printf("Input a number: ");
        if (scanf("%f", &current) != 1)
        {
            printf("Incorrect input");
            return 0;
        }
        product *= current;
        printf("Product: %.2Lf\n", product);
    }
}