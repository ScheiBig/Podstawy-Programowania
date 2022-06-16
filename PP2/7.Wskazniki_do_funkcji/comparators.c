#include "comparators.h"

#include <stdlib.h>

#include "my_utils_v3.h"

#ifdef zadanie8
__include__swap_generic()

int sort(void* arr, int lenght, int size, ptr_comp comp)
{
    if (lenght < 1 || arr == null || size < 1 || comp == null) { return 1; }
    if (lenght == 1) { return 0; }
    byte* a = (byte*)arr;
    int mov;
    for (int i = lenght; i > 0; --i)
    {
        mov = 0;
        for (int j = 0; j < (i - 1); ++j)
        {
            if (comp((a + j * size), (a + (j + 1) * size)) > 0)
            {
                swap_generic((a + j * size), (a + (j + 1) * size), (unsigned)size);
                ++mov;
            }
        }
        if (mov == 0) { break; }
    }
    return 0;
}

int comp_int(const void* ptr1, const void* ptr2)
{
    if (ptr1 == null || ptr2 == null) return 0;
    return *(const int*)ptr1 - *(const int*)ptr2;
}

int comp_double(const void* ptr1, const void* ptr2)
{
    if (ptr1 == null || ptr2 == null) return 0;
    return (*(const double*)ptr1 > *(const double*)ptr2) +
        (*(const double*)ptr1 < *(const double*)ptr2) * -1;
}

int comp_point(const void* ptr1, const void* ptr2)
{
    if (ptr1 == null || ptr2 == null) return 0;
    int res = comp_double(ptr1, ptr2);
    if (res == 0) { res = comp_double((const double*)ptr1 + 1, (const double*)ptr2 + 1); }
    return res;
}

#endif

#ifdef zadanie6
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
#endif
