#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <limits.h>
#include <ctype.h>

#include "my_utils_print.h"

int is_equal(int a, int b);
int is_negative(int value);

int main()
{
    int a;
    int b;
    print_ln("Enter two numbers:");
    
    if (!is_equal(scanf("%d %d", &a, &b), 2)) { __m_exit(eINPUT_invalid); }

    printf_ln("%s", is_equal(a, b) ? "rowne" : "nierowne");
    printf_ln("%s %s", is_negative(a) ? "ujemna" : "nieujemna", is_negative(b) ? "ujemna" : "nieujemna");

    return 0;
}

int is_equal(int a, int b)
{
    return !(a ^ b);
}

int is_negative(int value)
{
    return !!(0x80000000 & (unsigned)value);
}
