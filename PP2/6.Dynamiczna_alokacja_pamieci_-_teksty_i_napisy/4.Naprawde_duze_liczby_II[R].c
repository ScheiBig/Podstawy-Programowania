#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v3.h"
#include "big_number_utils.h"

int main()
{
    cstring expr = (cstring)calloc(501, sizeof(char));
    if (expr == null)
    {
        __m_exit(eMEMORY_cantallocate);
    }
    print_ln("Enter big-number expression:");
    if (fgets(expr, 500, stdin) == null)
    {
        free(expr);
        __m_exit(eINPUT_invalid);
    }
    if (*(expr + strlen(expr) - 1) == '\n')
    {
        *(expr + strlen(expr) - 1) = str_term;
    }
    if (validate_expression(expr) != 0)
    {
        free(expr);
        __m_exit(eINPUT_invalid);
    }
    cstring result;
    if (calculate(expr, &result) == 3)
    {
        free(expr);
        __m_exit(eMEMORY_cantallocate);
    }
    printf_ln("%s", result);
    free(result);
    free(expr);
    return 0;
}
