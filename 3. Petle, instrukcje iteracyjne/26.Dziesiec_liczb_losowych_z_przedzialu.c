#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", rand() % (21 - 10) + 10);
    }

    return 0;
}