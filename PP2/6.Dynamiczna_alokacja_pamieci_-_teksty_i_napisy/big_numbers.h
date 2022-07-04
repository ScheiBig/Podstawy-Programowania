#pragma once

#include "my_utils_v3.h"

typedef struct big_numbers_t
{
    int size;
    int capacity;
    cstring* big_number;
} big_numbers_s;

typedef big_numbers_s* big_numbers_ps;
typedef const big_numbers_s* c_big_numbers_ps;

int create(big_numbers_ps bn, int capacity);
int create_big_numbers(big_numbers_ps* bn, int capacity);

void destroy(big_numbers_ps bn);
void destroy_big_numbers(big_numbers_ps* bn);

int add_big_number(big_numbers_ps bn, const char* big_number);

void display(c_big_numbers_ps bn);
