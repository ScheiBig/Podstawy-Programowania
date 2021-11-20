#include <stdio.h>

int main()
{

    for (int i = 0; i <= 100; ++i)
    {
        if ((10 <= i && i < 15) || (40 <= i && i <= 60) || (70 < i && i < 80))
        { printf("*"); }
        printf("%d\n", i);
    }

    return 0;
}