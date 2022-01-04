#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>

#include "my_utils.h"

#define MAT_SIZ 10

int is_locmin(int*, int);

int main()
{
    int M[MAT_SIZ][MAT_SIZ] = { 0 };

    printf("Enter a 10x10 matrix:\n");

    for (size_t r = 0; r < MAT_SIZ; ++r)
    {
        for (size_t c = 0; c < MAT_SIZ; ++c)
        {
            if (scanf("%d", *(M + r) + c) != 1) _e_exit(1, "Incorrect input")
        }
    }

    coords2d loc_minim[MAT_SIZ * MAT_SIZ / 4];
    size_t lm_count = 0;

    for (size_t r = 1; r < MAT_SIZ - 1; ++r)
    {
        for (size_t c = 1; c < MAT_SIZ - 1; ++c)
        {
            if (is_locmin(*(M + r) + c, MAT_SIZ))
            {
                loc_minim[lm_count++] = (coords2d){ (int)c, (int)r, 1 };
            }
        }
    }
    if (!lm_count)
    {
        _e_exit(0, "Nothing to show")
    }

    printf_ln("%zu", lm_count);
    for (size_t i = 0; i < lm_count; ++i)
    {
        printf_ln("%d %d", loc_minim[i].y, loc_minim[i].x);
    }

    return 0;
}

int is_locmin(int* cell, int mat_siz)
{
    int current_val = *(cell);
    if (*(cell - mat_siz - 1) <= current_val) return 0; // ↖
    if (*(cell - mat_siz) <= current_val) return 0; // ↑
    if (*(cell - mat_siz + 1) <= current_val) return 0; // ↗
    if (*(cell - 1) <= current_val) return 0; // ←
    if (*(cell + 1) <= current_val) return 0; // →
    if (*(cell + mat_siz - 1) <= current_val) return 0; // ↙
    if (*(cell + mat_siz) <= current_val) return 0; // ↓
    if (*(cell + mat_siz + 1) <= current_val) return 0; // ↘
    return 1;
}
