#pragma once

#include "format_type.h"

struct statistic_t
{
    int min;
    int max;
    float avg;
    float standard_deviation;
    int range;
};

int statistics(int** ptr, struct statistic_t** stats);
void display(int** ptr);
int save(const char* filename, int** ptr, enum save_format_t format);

int load(const char* filename, int*** ptr, enum save_format_t format);
int statistics_row(int** ptr, struct statistic_t** stats);
void destroy(int*** ptr);