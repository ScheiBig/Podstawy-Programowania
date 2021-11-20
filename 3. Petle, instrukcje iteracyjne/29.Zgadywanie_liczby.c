#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_RANG(MAX, MIN) (rand() % (MAX - MIN + 1) + MIN)

int main()
{
    srand(time(NULL));

    int num = RAND_RANG(100, 0);
    int current;

    for (int i = 10; i > 0; --i)
    {
        printf("Enter your guess: ");
        scanf("%d", &current);

        if (current > num)
        { printf("Za duzo\n"); }
        else if (current < num)
        { printf("Za malo\n"); }
        else
        {
            printf("wygrales");
            return 0;
        }
    }

    printf("przegrales");

    return 0;
}