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
    _int, _float
};

int main()
{
    int type;
    print_ln("Select data type:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &type) != 1) { __m_exit(eINPUT_invalid); }
    else if (!is_num_in_range(type, 0, 1)) { __m_exit(eDATA_invalid); }

    print_ln("Enter values: ");
    switch (type)
    {
    case _int: {
        int a;
        int b;
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%d %d", &a, &b) != 2) { __m_exit(eINPUT_invalid); }
        printf_ln("%d", SQR(a));
        printf_ln("%d", SQR(b));
        printf_ln("%d", MAX(a, b));
        printf_ln("%d", MIN(a, b));
        return 0;
    }
    case _float: {
        float a;
        float b;
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%f %f", &a, &b) != 2) { __m_exit(eINPUT_invalid); }
        printf_ln("%f", SQR(a));
        printf_ln("%f", SQR(b));
        printf_ln("%f", MAX(a, b));
        printf_ln("%f", MIN(a, b));
        return 0;
    }
    }

    return 0;
}
