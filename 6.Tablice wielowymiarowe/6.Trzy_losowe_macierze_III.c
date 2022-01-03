#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "my_utils.h"

#define __MATRIX_MUL__
#define __MATRIX_PRINT__
#include "matrix.h"
#undef __MATRIX_MUL__
#undef __MATRIX_PRINT__


#define MAT_SIZ 4
REGISTER_INT_MATRIX(4)

int main()
{
    srand((unsigned int)time(NULL));
    int A[MAT_SIZ][MAT_SIZ] = { 0 };
    int B[MAT_SIZ][MAT_SIZ] = { 0 };
    int C[MAT_SIZ][MAT_SIZ] = { 0 };

    int AmB[MAT_SIZ][MAT_SIZ] = { 0 };
    int BmA[MAT_SIZ][MAT_SIZ] = { 0 };
    int AmC[MAT_SIZ][MAT_SIZ] = { 0 };
    int CmA[MAT_SIZ][MAT_SIZ] = { 0 };

    for (size_t r = 0; r < MAT_SIZ; ++r)
    {
        for (size_t c = 0; c < MAT_SIZ; ++c)
        {
            A[r][c] = CLIP_RANGE(rand(), 0, 10);
            B[r][c] = CLIP_RANGE(rand(), 0, 10);
            C[r][c] = r == c ? 1 : 0;
        }
    }

    matrix_mul_4(A, B, AmB);
    matrix_mul_4(B, A, BmA);
    matrix_mul_4(A, C, AmC);
    matrix_mul_4(C, A, CmA);

    matrix_print_4(A, 3);
    matrix_print_4(B, 3);
    matrix_print_4(C, 3);
    matrix_print_4(AmB, 3);
    matrix_print_4(BmA, 3);
    matrix_print_4(AmC, 3);
    matrix_print_4(CmA, 3);

    return 0;
}
