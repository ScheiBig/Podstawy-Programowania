#include <stdio.h>

int main()
{
    float current, previous;
    printf("Enter first number: ");
    if (scanf("%f", &previous) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    else if (previous != 0.0)
    {
        while (1)
        {
            printf("Enter next number: ");
            if (scanf("%f", &current) != 1)
            {
                printf("Incorrect input");
                return 1;
            }
            else if (current == 0.0)
            {
                break;
            }
            printf("%f\n", current - previous);
            previous = current;
        }
    }

    return 0;
}