#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "my_utils.h"

#define __MATRIX_PRINT__
#include "matrix.h"
#undef __MATRIX_PRINT__

#define R_START 0
#define R_END 30
#define MAT_SIZ 15
REGISTER_INT_MATRIX(15)

int main()
{
    srand((unsigned int)time(NULL));
    int A[MAT_SIZ][MAT_SIZ] = { { 0 } };

    printf("Enter a 15x15 matrix:\n");

    for (size_t r = 0; r < MAT_SIZ; ++r)
    {
        for (size_t c = 0; c < MAT_SIZ; ++c)
        {
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            if (scanf("%d", *(A + r) + c) != 1) _e_exit(1, "Incorrect input\n");
            if (!(R_START <= A[r][c] && A[r][c] < R_END)) _e_exit(2, "Value out of range\n");
        }
    }

    int mapping[R_END] = { 0 };
    for (size_t r = 0; r < MAT_SIZ; ++r)
    {
        for (size_t c = 0; c < MAT_SIZ; ++c)
        {
            ++mapping[A[r][c]];
        }
    }

    int B[MAT_SIZ][MAT_SIZ] = { { 0 } };
    for (size_t r = 0; r < MAT_SIZ; ++r)
    {
        for (size_t c = 0; c < MAT_SIZ; ++c)
        {
            B[r][c] = mapping[A[r][c]];
        }
    }

    matrix_print_15(B, 2);

    return 0;
}
