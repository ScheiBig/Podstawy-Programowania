#pragma once

#define zadanie8 1

#ifdef zadanie8
struct point_t
{
    double x;
    double y;
};

typedef int (*ptr_comp)(const void*, const void*);

int sort(void* arr, int lenght, int size, ptr_comp comp);

int comp_int(const void* ptr1, const void* ptr2);
int comp_double(const void* ptr1, const void* ptr2);
int comp_point(const void* ptr1, const void* ptr2);
#endif

#ifdef zadanie6
typedef int (*int_comp)(int, int);

int sort_int(int* arr, int size, int_comp comp);

int comp_int(int a, int b);
int comp_int_abs(int a, int b);
int comp_int_length(int a, int b);
int comp_int_digits_sum(int a, int b);
#endif
