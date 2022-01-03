#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "my_utils.h"
#include "matrix.h"

#define MAT_SIZ 4
REGISTER_INT_MATRIX(4)

int main()
{
    srand((unsigned int)time(NULL));
    int A[MAT_SIZ][MAT_SIZ] = { 0 };
    int B[MAT_SIZ][MAT_SIZ] = { 0 };
    int C[MAT_SIZ][MAT_SIZ] = { 0 };

    int Ar[MAT_SIZ] = { 0 };
    int Ac[MAT_SIZ] = { 0 };
    int Br[MAT_SIZ] = { 0 };
    int Bc[MAT_SIZ] = { 0 };
    int Cr[MAT_SIZ] = { 0 };
    int Cc[MAT_SIZ] = { 0 };

    for (size_t r = 0; r < MAT_SIZ; ++r)
    {
        for (size_t c = 0; c < MAT_SIZ; ++c)
        {
            A[r][c] = CLIP_RANGE(rand(), 0, 10);
            B[r][c] = CLIP_RANGE(rand(), 0, 10);
            C[r][c] = r == c ? 1 : 0;
        }
    }

    matrix_rowsum_4(A, Ar);
    matrix_colsum_4(A, Ac);
    matrix_rowsum_4(B, Br);
    matrix_colsum_4(B, Bc);
    matrix_rowsum_4(C, Cr);
    matrix_colsum_4(C, Cc);

    matrix_print_4(A, 3);
    matrix_print_4(B, 3);
    matrix_print_4(C, 3);
    vector_print_4(Ac, 3);
    vector_print_4(Ar, 3);
    vector_print_4(Bc, 3);
    vector_print_4(Br, 3);
    vector_print_4(Cc, 3);
    vector_print_4(Cr, 3);

    return 0;
}
