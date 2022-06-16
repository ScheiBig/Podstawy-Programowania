#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v3.h"
#include "for_loop.h"

int main()
{
    iteration funcs[4] = { print_value, print_accumulated, print_square, print_abs };

    double start, end_ex, step;
    int op_n;
    print_ln("Enter numbers (start, step, end-exclusive): ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%lf %lf %lf", &start, &step, &end_ex) != 3)
    {
        __m_exit(eINPUT_invalid);
    }
    else if (step > 0 && start > end_ex || step < 0 && start < end_ex || step == 0)
    {
        __m_exit(eDATA_invalid);
    }

    print_ln("Enter operation no. (0-print_value, 1-print_accumulated, 2-print_square, 3-print_abs):");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &op_n) != 1)
    {
        __m_exit(eINPUT_invalid);
    }
    else if (!is_num_in_range(op_n, 0, 3))
    {
        __m_exit(eDATA_invalid);
    }

    for_loop(start, step, end_ex, *(funcs + op_n));
    
    return 0;
}
