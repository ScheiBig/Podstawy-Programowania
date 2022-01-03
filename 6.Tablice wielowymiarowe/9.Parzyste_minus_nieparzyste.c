#include <stdio.h>
#include <math.h>

#include "my_utils.h"

#define MAT_SIZ 10

int main()
{
    int A[MAT_SIZ][MAT_SIZ] = { 0 };

    printf("Enter a 10x10 matrix:\n");

    for (size_t r = 0; r < MAT_SIZ; ++r)
    {
        for (size_t c = 0; c < MAT_SIZ; ++c)
        {
            if (scanf("%d", *(A + r) + c) != 1) _e_exit(1, "Incorrect input\n");
        }
    }

    long sum = 0;
    for (size_t r = 0; r < MAT_SIZ; ++r)
    {
        for (size_t c = 0; c < MAT_SIZ; ++c)
        {
            if ((r + c) % 2 == 0) sum += A[r][c];
            else sum -= A[r][c];
        }
    }

    printf("%ld\n", sum);

    return 0;
}
