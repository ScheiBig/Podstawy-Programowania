#include <stdio.h>

int main()
{
    float sum = 0, temp;
    for (int i = 0; i < 10; ++i)
    {
        printf("Enter number #%i :", i);
        if (scanf("%f", &temp) != 1)
        {
            printf("Incorrect input\n");
            return 1;
        }
        sum += temp;
    }
    printf("Your sum is: %f", sum);
    return 0;
}