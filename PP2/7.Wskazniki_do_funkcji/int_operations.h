#pragma once

typedef int(*op_int)(int, int);

enum operations_t
{
    op_add, op_sub, op_div, op_mul
};

op_int get_function(enum operations_t op);

int calculate(int n1, int n2, int (*op)(int, int));
int add_int(int n1, int n2);
int sub_int(int n1, int n2);
int div_int(int n1, int n2);
int mul_int(int n1, int n2);
