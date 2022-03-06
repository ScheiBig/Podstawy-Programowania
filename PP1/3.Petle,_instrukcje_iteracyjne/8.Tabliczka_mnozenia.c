#include <stdio.h>

typedef unsigned long long int uLonger;

int main()
{
    for (int i = 0; i <= 10; ++i)
    {
        for (int j = 0; j <= 10; ++j)
        {
            printf("%2d * %2d = %3d\n", i, j, i * j);
        }
    }
    return 0;
}