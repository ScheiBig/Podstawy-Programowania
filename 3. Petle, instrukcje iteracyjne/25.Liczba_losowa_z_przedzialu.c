#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned int)time(NULL));

    printf("%d\n", rand() % (40 - 30) + 30);

    return 0;
}