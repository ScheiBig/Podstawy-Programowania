#pragma once

typedef int (*int_comp)(int, int);

int sort_int(int* arr, int size, int_comp comp);

int comp_int(int a, int b);
int comp_int_abs(int a, int b);
int comp_int_length(int a, int b);
int comp_int_digits_sum(int a, int b);
