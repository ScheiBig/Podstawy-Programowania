#include <stdio.h>
#include <math.h>

int main()
{
    int num;
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    if (num <= 1)
    {
        printf("NO");
        return 0;
    }

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (i != num && num % i == 0)
        {
            printf("NO");
            return 0;
        }
    }

    printf("YES");
    return 0;
}