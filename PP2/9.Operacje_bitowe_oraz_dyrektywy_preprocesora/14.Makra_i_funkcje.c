#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <limits.h>
#include <ctype.h>
#include <stdint.h>

#include "my_utils_v3.h"
#include "functions.h"

enum type_t
{
    _int, _float, _double
};

#define format_int "%d"
#define format_float "%f"
#define format_double "%lf"

//NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
CREATE_READ_FUNCTIONS(int, format_int)
//NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
CREATE_READ_FUNCTIONS(float, format_float)
//NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
CREATE_READ_FUNCTIONS(double, format_double)

CREATE_SORT_FUNCTIONS(int)
CREATE_SORT_FUNCTIONS(float)
CREATE_SORT_FUNCTIONS(double)

CREATE_DISPLAY_FUNCTIONS(int, format_int)
CREATE_DISPLAY_FUNCTIONS(float, format_float)
CREATE_DISPLAY_FUNCTIONS(double, format_double)

#define _case(TYPE) \
    case _ ## TYPE: { \
        TYPE* data = (TYPE*)calloc((unsigned)el_num, sizeof(TYPE)); \
        if (data == null) { __m_exit(eMEMORY_cantallocate); } \
        printf_ln("Enter %d numbers: ", el_num); \
        if (read_ ## TYPE(data, el_num) != 0) \
        { \
            free(data); \
            __m_exit(eINPUT_invalid); \
        } \
        sort_ ## TYPE(data, el_num); \
        display_ ## TYPE(data, el_num); \
        free(data); \
        return 0; \
    }

int main()
{
    int type;
    print_ln("Select data type:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &type) != 1) { __m_exit(eINPUT_invalid); }
    else if (!is_num_in_range(type, 0, 2)) { __m_exit(eDATA_invalid); }

    int el_num;
    print_ln("Enter number of arrays:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &el_num) != 1) { __m_exit(eINPUT_invalid); }
    else if (el_num <= 0) { __m_exit(eDATA_invalid); }

    switch (type)
    {
    _case(int) _case(float) _case(double)
    }

    return 0;
}
