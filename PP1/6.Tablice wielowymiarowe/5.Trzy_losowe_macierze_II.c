#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define __MATRIX_ADD__
#define __MATRIX_SUB__
#define __MATRIX_NEG__
#define __MATRIX_PRINT__
#include "matrix.h"
#undef __MATRIX_ADD__
#undef __MATRIX_SUB__
#undef __MATRIX_NEG__
#undef __MATRIX_PRINT__

#define eprintf(msg) fprintf(stderr, msg)
#define _e_exit(eno, msg) { eprintf(msg); return eno; }

#define CLIP_RANGE(in, from, to) ((in % to - from + 1) + from)

#define MAT_SIZ 4
REGISTER_INT_MATRIX(4)

int main()
{
    srand((unsigned int)time(NULL));
    int A[MAT_SIZ][MAT_SIZ] = { { 0 } };
    int B[MAT_SIZ][MAT_SIZ] = { { 0 } };
    int C[MAT_SIZ][MAT_SIZ] = { { 0 } };

    int AaB[MAT_SIZ][MAT_SIZ] = { { 0 } };
    int AsB[MAT_SIZ][MAT_SIZ] = { { 0 } };
    int AaBaC[MAT_SIZ][MAT_SIZ] = { { 0 } };
    int AsBsC[MAT_SIZ][MAT_SIZ] = { { 0 } };
    int mB[MAT_SIZ][MAT_SIZ] = { { 0 } };

    for (size_t r = 0; r < MAT_SIZ; ++r)
    {
        for (size_t c = 0; c < MAT_SIZ; ++c)
        {
            A[r][c] = CLIP_RANGE(rand(), 0, 50);
            B[r][c] = CLIP_RANGE(rand(), 0, 50);
            C[r][c] = r == c ? 1 : 0;
        }
    }

    matrix_add_4(A, B, AaB);
    matrix_sub_4(A, B, AsB);
    matrix_add_4(AaB, C, AaBaC);
    matrix_sub_4(AsB, C, AsBsC);
    matrix_neg_4(B, mB);

    matrix_print_4(A, 3);
    matrix_print_4(B, 3);
    matrix_print_4(C, 3);
    matrix_print_4(AaB, 3);
    matrix_print_4(AsB, 3);
    matrix_print_4(AaBaC, 3);
    matrix_print_4(AsBsC, 3);
    matrix_print_4(mB, 3);

    return 0;
}
