#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v3.h"
#include "my_string.h"
#include "comparators.h"

typedef int (*reader)(void*);
typedef void (*printer)(void*);

int read_int(void* i)
{
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    return scanf("%d", (int*)i);
}
void print_int(void* i) { printf("%d ", *(int*)i); }

int read_double(void* d)
{
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    return scanf("%lf", (double*)d);
}
void print_double(void* d) { printf("%lf ", *(double*)d); }

int read_point(void* p)
{
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    return scanf("%lf %lf", (double*)p, (double*)p + 1) == 2;
}
void print_point(void* p) { printf("%lf %lf\n", *(double*)p, *((double*)p + 1)); }

enum data_type
{
    _int, _double, _point
};

int main()
{
    reader rea;
    printer pri;
    ptr_comp comp;
    int len;
    byte* arr;
    size_t size;
    int op_n;

    print_ln("Enter data type (0-int, 1-double, 2-point_t): ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &op_n) != 1) { __m_exit(eINPUT_invalid); }
    else if (!is_num_in_range(op_n, 0, 2)) { __m_exit(eDATA_invalid); }
    else
    {
        switch ((enum data_type)op_n)
        {
        case _int:
            rea = read_int;
            pri = print_int;
            comp = comp_int;
            size = sizeof(int);
            break;
        case _double:
            rea = read_double;
            pri = print_double;
            comp = comp_double;
            size = sizeof(double);
            break;
        case _point:
            rea = read_point;
            pri = print_point;
            comp = comp_point;
            size = sizeof(struct point_t);
            break;
        }
    }

    print_ln("Enter array length: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &len) != 1) { __m_exit(eINPUT_invalid); }
    else if (len < 1) { __m_exit(eDATA_invalid); }
    else if ((arr = (byte*)calloc(len, size)) == null) { __m_exit(eMEMORY_cantallocate); }

    discard_stdin();

    printf_ln("Enter %d elements: ", len);
    for (byte* s = arr; s < arr + len * size; s += size)
    {
        if (rea(s) != 1)
        {
            free(arr);
            __m_exit(eINPUT_invalid);
        }
    }

    sort(arr, len, (int)size, comp);

    for (byte* s = arr; s < arr + len * size; s += size) { pri(s); }
    print_n();
    free(arr);

    return 0;
}
