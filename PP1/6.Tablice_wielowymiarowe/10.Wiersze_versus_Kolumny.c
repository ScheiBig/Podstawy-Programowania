#include <stdio.h>
#include <math.h>
#include <limits.h>

#include "my_utils.h"

#define __MATRIX_CSUM__
#define __MATRIX_RSUM__
#include "matrix.h"
#undef __MATRIX_CSUM__
#undef __MATRIX_RSUM__

#define MAT_SIZ 10
REGISTER_INT_MATRIX(10)

int main()
{
    int M[MAT_SIZ][MAT_SIZ] = { { 0 } };
    int C[MAT_SIZ] = { 0 };
    int R[MAT_SIZ] = { 0 };
    int max = INT_MIN;

    printf("Enter a 10x10 matrix:\n");

    for (size_t r = 0; r < MAT_SIZ; ++r)
    {
        for (size_t c = 0; c < MAT_SIZ; ++c)
        {
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            if (scanf("%d", *(M + r) + c) != 1) _e_exit(1, "Incorrect input\n");
            if (M[r][c] % 2 == 0) COND_ASSIGN_L(max, M[r][c]);
        }
    }
    if (max == INT_MIN) _e_exit(0, "Nothing to show\n");

    matrix_colsum_10(M, C);
    matrix_rowsum_10(M, R);

    for (size_t c = 0; c < MAT_SIZ; ++c)
    {
        for (size_t r = 0; r < MAT_SIZ; ++r)
        {
            if (M[r][c] == max) printf("%zu %zu %d\n", c, r, C[r] - R[c]);
        }
    }

    return 0;
}
