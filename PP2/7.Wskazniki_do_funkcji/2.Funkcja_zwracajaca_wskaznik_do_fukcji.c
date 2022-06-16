#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v3.h"
#include "int_operations.h"



int main()
{
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
    printf_ln("Result: %d", get_function((enum operations_t)op_n)(n1, n2));
    return 0;
}
