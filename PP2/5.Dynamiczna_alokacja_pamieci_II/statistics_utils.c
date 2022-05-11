#include "statistics_utils.h"

#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>

#include "my_utils_v2.h"

float _standard_deviation(double avg, int** ptr)
{
    double std_dev = 0;
    size_t count = 0;
    for (int** r = ptr; (*r) != null; ++r)
    {
        for (int* c = (*r); (*c) != -1; ++c)
        {
            std_dev += ((*c) - avg) * (*c - avg);
            ++count;
        }
    }
    return (float)sqrt(std_dev / count);
}

int statistics(int** ptr, struct statistic_t** stats)
{
    if (ptr == null || stats == null)
    {
        return 1;
    }
    if (((*stats) = (struct statistic_t*)calloc(1, sizeof(struct statistic_t))) == null)
    {
        return 2;
    }
    (*stats)->min = INT_MAX;
    (*stats)->max = INT_MIN;
    double sum_avg = 0;
    size_t count = 0;

    for (int** r = ptr; (*r) != null; ++r)
    {
        for (int* c = (*r); (*c) != -1; ++c)
        {
#undef min
#undef max
            cond_assign_g((*stats)->min, (*c));
            cond_assign_l((*stats)->max, (*c));
            sum_avg += (*c);
            ++count;
        }
    }
    if (count == 0)
    {
        free(*stats);
        return 3;
    }
    sum_avg /= count;
    (*stats)->avg = (float)sum_avg;
    (*stats)->standard_deviation = _standard_deviation(sum_avg, ptr);
    (*stats)->range = (*stats)->max - (*stats)->min;

    return 0;
}

void display(int** ptr)
{
    if (ptr != null)
    {
        for (int** r = ptr; (*r) != null; ++r)
        {
            for (int* c = (*r); (*c) != -1; ++c)
            {
                printf("%d ", (*c));
            }
            print_n();
        }
    }
}

void _bin_save_next_row(p_file file, int* row)
{
    int* c;
    for (c = row; (*c) != -1; ++c)
    {
        fwrite(c, sizeof(int), 1, file);
    }
    fwrite(c, sizeof(int), 1, file);
}

void _txt_save_next_row(p_file file, int* row)
{
    for (int* c = row; (*c) != -1; ++c)
    {
        fprintf(file, "%d ", (*c));
    }
    fprintf(file, "-1\n");
}

int save(const char* filename, int** ptr, enum save_format_t format)
{
    if (filename == null || strlen(filename) == 0 || ptr == null)
    {
        return 1;
    }
    void (*save_row)(p_file, int*);
    char* write_mode;

    switch (format)
    {
    case fmt_text:
        save_row = _txt_save_next_row;
        write_mode = "w";
        break;
    case fmt_binary:
        save_row = _bin_save_next_row;
        write_mode = "wb";
        break;
    default:
        return 1;
    }

    p_file file;
    if ((file = fopen(filename, write_mode)) == null)
    {
        return 2;
    }
    for (int** r = ptr; (*r) != null; ++r)
    {
        save_row(file, (*r));
    }
    
    fclose(file);
    return 0;
}