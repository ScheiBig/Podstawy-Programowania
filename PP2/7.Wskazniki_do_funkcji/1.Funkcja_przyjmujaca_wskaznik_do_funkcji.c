#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v3.h"
#include "int_operations.h"

typedef int(*op_int)(int, int);

int main()
{
    op_int funcs[4] = { add_int, sub_int, div_int, mul_int };
    int n1, n2, op_n;
    print_ln("Enter numbers:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d %d", &n1, &n2) != 2)
    {
        __m_exit(eINPUT_invalid);
    }
    
    print_ln("Enter operation no. (0-add, 1-sub, 2-div, 3-mul):");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &op_n) != 1)
    {
        __m_exit(eINPUT_invalid);
    }
    else if (!is_num_in_range(op_n, 0, 3))
    {
        __m_exit(eDATA_invalid);
    }
    printf_ln("Result: %d", calculate(n1, n2, *(funcs + op_n)));
    return 0;
}