#include "comparators.h"

#include <stdlib.h>

#include "my_utils_v3.h"
__include__swap(int)

int sort_int(int* arr, int size, int_comp comp)
{
    if (size < 1 || arr == null || comp == null) { return 1; }
    if (size == 1) { return 0; }
    int mov;
    for (int i = size; i > 0; --i)
    {
        mov = 0;
        for (int j = 0; j < (i - 1); ++j)
        {
            if (comp(*(arr + j), *(arr + j + 1)) > 0)
            {
                swap_int(arr + j, arr + (j + 1));
                ++mov;
            }
        }
        if (mov == 0) { break; }
    }
    return 0;
}

int comp_int(int a, int b)
{
    return a - b;
}

int comp_int_abs(int a, int b)
{
    return abs(a) - abs(b);
}

int int_len(int i)
{
    int l;
    for (l = 0; i != 0; ++l, i /= 10);
    return l;
}

int comp_int_length(int a, int b)
{
    return int_len(a) - int_len(b);
}

int int_digi_sum(int i)
{
    int s;
    for (s = abs(i % 10); i != 0; i /= 10, s += abs(i % 10));
    return s;
}

int comp_int_digits_sum(int a, int b)
{
    return int_digi_sum(a) - int_digi_sum(b);
}
