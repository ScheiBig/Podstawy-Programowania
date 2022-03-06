#include <stdio.h>

#define L(a, b) ((a + b) * (a - b))
#define P(a, b) (a * a + b * b)

int main()
{
    for (int i = -10; i <= 10; ++i)
    {
        for (int j = -10; j <= 10; ++j)
        {
            if (L(i, j) == P(i, j)) printf("%d %d\n", i, j);
        }
    }

    return 0;
}