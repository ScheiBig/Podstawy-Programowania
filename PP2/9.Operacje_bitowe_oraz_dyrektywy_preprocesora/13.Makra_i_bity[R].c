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
    _uint, _ushort, _ulong
};

#define format_uint "%u"
#define format_ushort "%hu"
#define format_ulong "%lu"

#define _case(num, type) \
    case num: { \
        int s; \
        int c; \
        type v; \
        if (scanf(format ## num, &v) != 1) { __m_exit(eINPUT_invalid); } \
        COUNT_BITS(v, &s, &c); \
        printf_ln("%d", s); \
        printf_ln("%d", c); \
        DISPLAY_BITS(v); \
        print_n(); \
        REVERSE_BITS(&v); \
        DISPLAY_BITS(v); \
        print_n(); \
        return 0; \
    }

int main()
{
    int type;
    print_ln("Select data type:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &type) != 1) { __m_exit(eINPUT_invalid); }
    else if (!is_num_in_range(type, 0, 2)) { __m_exit(eDATA_invalid); }
    
    print_ln("Enter value: ");
    switch (type)
    {
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        _case(_uint, unsigned int) _case(_ushort, unsigned short) _case(_ulong, unsigned long)
    }

    return 0;
}
