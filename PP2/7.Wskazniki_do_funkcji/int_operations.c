#include "int_operations.h"

#define null (void*)0

int calculate(int n1, int n2, int (*op)(int, int))
{
    return op(n1, n2);
}

int add_int(int n1, int n2)
{
    return n1 + n2;
}

int sub_int(int n1, int n2)
{
    return n1 - n2;
}

int div_int(int n1, int n2)
{
    return n2 != 0 ? n1 / n2 : 0;
}

int mul_int(int n1, int n2)
{
    return n1 * n2;
}

op_int get_function(enum operations_t op)
{
    op_int funcs[4] = { add_int, sub_int, div_int, mul_int };
    return *(funcs + op);
}