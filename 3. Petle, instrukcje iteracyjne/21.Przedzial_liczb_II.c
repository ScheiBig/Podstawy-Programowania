#include <stdio.h>
#include <math.h>

int main()
{
    float min, max;

    printf("Enter a range minimum: ");
    if (scanf("%f", &min) != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Enter a range maximum: ");
    if (scanf("%f", &max) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    else if (min > max)
    {
        printf("Incorrect range");
        return 2;
    }
    else
    {
        for (float i = min; i <= max; i += 0.25)
        {
            printf("%.2f\n", i);
        }
    }

    return 0;
}