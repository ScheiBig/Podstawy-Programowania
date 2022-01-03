#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define eprintf(msg) fprintf(stderr, msg)
#define _e_exit(eno, msg) { eprintf(msg); return eno; }

#define CLIP_RANGE(in, from, to) ((in % to - from + 1) + from)

#define MAT_SIZ 4

int main()
{
    srand((unsigned int)time(NULL));
    int A[MAT_SIZ][MAT_SIZ] = { 0 };
    int B[MAT_SIZ][MAT_SIZ] = { 0 };
    int C[MAT_SIZ][MAT_SIZ] = { 0 };

    for (size_t r = 0; r < MAT_SIZ; ++r)
    {
        for (size_t c = 0; c < MAT_SIZ; ++c)
        {
            A[r][c] = CLIP_RANGE(rand(), 0, 50);
            B[r][c] = CLIP_RANGE(rand(), 0, 50);
            C[r][c] = r == c ? 1 : 0;
        }
    }

    for (size_t r = 0; r < MAT_SIZ; ++r)
    {
        for (size_t c = 0; c < MAT_SIZ; ++c)
        {
            printf("%3d ", A[r][c]);
        }
        printf("\n");
    }
    printf("\n");
    for (size_t r = 0; r < MAT_SIZ; ++r)
    {
        for (size_t c = 0; c < MAT_SIZ; ++c)
        {
            printf("%3d ", B[r][c]);
        }
        printf("\n");
    }
    printf("\n");
    for (size_t r = 0; r < MAT_SIZ; ++r)
    {
        for (size_t c = 0; c < MAT_SIZ; ++c)
        {
            printf("%3d ", C[r][c]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
