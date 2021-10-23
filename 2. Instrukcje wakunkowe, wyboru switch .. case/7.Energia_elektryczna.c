#include <stdio.h>

#define R1 50
#define R2 150
#define R3 250

#define C1 0.50
#define C2 0.75
#define C3 1.20
#define C4 1.50

#define RC1 (R1 * C1)
#define RC2 (R2 * C2)
#define RC3 (R3 * C3)

int main()
{
    int kWh, calc, success;
    float sum = 0;
    printf("Input power usage: ");
    success = scanf("%d", &kWh);

    if (success - 1 || kWh < 0)
    {
        printf("Incorrect input\n");
        return 1;
    }
    
    if ((calc = kWh - R3) > 0)
    {
        sum = RC1 + RC2 + RC3 + calc * C4;
    }
    else if ((calc = kWh - R2) > 0)
    {
        sum = RC1 + RC2 + calc * C3;
    }
    else if ((calc = kWh - R1) > 0)
    {
        sum = RC1 + calc * C1;
    }
    else
    {
        sum = kWh * C1;
    }
    
    sum *= 1.22;
    printf("Cost: %f\n", sum);
    
    

    return 0;
}