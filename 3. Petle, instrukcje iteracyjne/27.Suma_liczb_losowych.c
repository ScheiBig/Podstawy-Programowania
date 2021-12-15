#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    long sum = 0;

    for (int i = 0; i < 100; ++i)
    {
        sum += rand() % (21 - 10) + 10;
    }

    printf("%ld", sum);

    return 0;
}