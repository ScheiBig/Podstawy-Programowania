#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    srand((unsigned int)time(NULL));

    int num;

    while (INFINITY)
    {
        num = rand() % (1001 - (-1000)) - 1000;
        printf("%d\n", num);
        if (100 <= num && num <= 200) break;
    }

    return 0;
}