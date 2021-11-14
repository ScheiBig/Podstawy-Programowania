#include <stdio.h>
#include <float.h>
#include <math.h>

int main()
{
    float current, min = FLT_MAX, max = -FLT_MAX;
    long double avg = 0;
    int count = 0;

    printf("Enter your numbers: ");
    while (INFINITY)
    {
        if (scanf("%f", &current) != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        else if (current == -1)
        {
            break;
        }
        avg += current;
        min = min < current ? min : current;
        max = max > current ? max : current;
        ++count;
    }
    avg /= count;

    printf("%.2f\n", min);
    printf("%.2f\n", max);
    printf("%.2Lf\n", avg);

    return 0;
}