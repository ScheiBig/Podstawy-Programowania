#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"

int main()
{
    int i;
    int** mul_arr = (int**)malloc(10u * sizeof(int*));
    if (mul_arr == null)
    {
        __m_exit(eMEMORY_cantallocate);
    }
    for (i = 0; i < 10; ++i)
    {
        *(mul_arr + i) = (int*)malloc(10u * sizeof(int));
        if (*(mul_arr + i) == null)
        {
            for (int j = 0; j < i; ++j)
            {
                free(*(mul_arr + j));
            }
            free(mul_arr);
            __m_exit(eMEMORY_cantallocate);
        }
    }
    for (i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            *(*(mul_arr + i) + j) = (i + 1) * (j + 1);
        }
    }

    for (i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            printf("%4d", *(*(mul_arr + i) + j));
        }
        print_n();
    }

    for (i = 0; i < 10; ++i)
    {
        free(*(mul_arr + i));
    }
    free(mul_arr);
    return 0;
}
