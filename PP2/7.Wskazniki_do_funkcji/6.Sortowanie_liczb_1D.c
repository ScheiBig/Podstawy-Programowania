#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v3.h"
#include "my_string.h"
#include "comparators.h"

int main()
{
    int_comp* funcs = (int_comp*)calloc(4, sizeof(int_comp));
    if (funcs == null) { __m_exit(eMEMORY_cantallocate); }
    *(funcs + 0) = comp_int;
    *(funcs + 1) = comp_int_abs;
    *(funcs + 2) = comp_int_length;
    *(funcs + 3) = comp_int_digits_sum;

    int len;
    int* arr;
    int op_n;
    print_ln("Enter array length: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &len) != 1)
    {
        free(funcs);
        __m_exit(eINPUT_invalid);
    }
    else if (len < 1)
    {
        free(funcs);
        __m_exit(eDATA_invalid);
    }
    else if ((arr = (int*)calloc(len, sizeof(int))) == null)
    {
        free(funcs);
        __m_exit(eMEMORY_cantallocate);
    }

    discard_stdin();

    printf_ln("Enter %d numbers: ", len);
    for (int* s = arr; s < arr + len; ++s)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%d", s) != 1)
        {
            free(funcs);
            free(arr);
            __m_exit(eINPUT_invalid);
        }
    }

    print_ln("Enter comparator no. (0-value, 1-absolute, 2-length, 3-digit_sum):");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &op_n) != 1)
    {
        free(funcs);
        free(arr);
        __m_exit(eINPUT_invalid);
    }
    else if (!is_num_in_range(op_n, 0, 3))
    {
        free(funcs);
        free(arr);
        __m_exit(eDATA_invalid);
    }

    sort_int(arr, len, *(funcs + op_n));

    for (int* s = arr; s < arr + len; ++s) { printf("%d ", *s); }
    print_n();
    free(funcs);
    free(arr);
    
    return 0;
}
