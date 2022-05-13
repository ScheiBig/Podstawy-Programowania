#include "statistics_utils.h"

#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

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
    return (float)sqrt(std_dev / (double)count);
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
    sum_avg /= (double)count;
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
    default: return 1;
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


#define NAN_i INT_MAX
#define EOF_i INT_MIN

int _bin_load_next_number(p_file file)
{
    int n;
    size_t ret = fread(&n, sizeof(int), 1, file);
    if (ret != 1)
    {
        if (feof(file))
        {
            clearerr(file);
            return EOF_i;
        }
        return NAN_i;
    }
    return n;
}

int _txt_load_next_number(p_file file)
{
    int n;
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    int ret = fscanf(file, "%d", &n);
    if (ret != 1)
    {
        if (ret == EOF)
        {
            return EOF_i;
        }
        return NAN_i;
    }
    return n;
}

int load(const char* filename, int*** ptr, enum save_format_t format)
{
    if (filename == null || strlen(filename) == 0 || ptr == null)
    {
        return 1;
    }
    int (*load_num)(p_file);
    char* read_mode;

    switch (format)
    {
    case fmt_text:
        load_num = _txt_load_next_number;
        read_mode = "r";
        break;
    case fmt_binary:
        load_num = _bin_load_next_number;
        read_mode = "rb";
        break;
    default: return 1;
    }

    p_file file;
    if ((file = fopen(filename, read_mode)) == null)
    {
        return 2;
    }

    size_t row_count = 0;
    while (true)
    {
        switch (load_num(file))
        {
        case -1:
            ++row_count;
            break;
        case NAN_i:
            fclose(file);
            return 3;
        case EOF_i: goto break_while;
        default: break;
        }
    }
break_while: { fseek(file, 0L, SEEK_SET); }
    if (row_count == 0)
    {
        fclose(file);
        return 3;
    }
    if ((*ptr = (int**)calloc(row_count + 1, sizeof(int*))) == null)
    {
        fclose(file);
        return 4;
    }
    size_t cell_count;
    for (size_t r = 0; r < row_count; ++r)
    {
        cell_count = 0;
        while (true)
        {
            switch (load_num(file))
            {
            case -1: goto break_while_1;
            default:
                ++cell_count;
                break;
            }
        }
    break_while_1: {}
        if ((*(*ptr + r) = (int*)calloc(cell_count + 1, sizeof(int))) == null)
        {
            for (int i = (int)r - 1; i >= 0; --i)
            {
                free(*(*ptr + i));
            }
            free(*ptr);
            fclose(file);
            return 4;
        }
    }
    fseek(file, 0L, SEEK_SET);
    for (int** r = *ptr; r < *ptr + row_count; ++r)
    {
        for (int* c = *r; ; ++c)
        {
            *c = load_num(file);
            if (*c == -1)
            {
                break;
            }
        }
    }
    fclose(file);
    return 0;
}

float _standard_deviation_v(double avg, int* ptr)
{
    double std_dev = 0;
    size_t count = 0;
    for (int* c = ptr; (*c) != -1; ++c)
    {
        std_dev += ((*c) - avg) * (*c - avg);
        ++count;
    }
    return (float)sqrt(std_dev / (double)count);
}

int statistics_row(int** ptr, struct statistic_t** stats)
{
    if (ptr == null || stats == null)
    {
        return -1;
    }
    size_t ptr_count;
    for (ptr_count = 0; *(ptr + ptr_count) != null; ++ptr_count);
    if (((*stats) = (struct statistic_t*)calloc(ptr_count, sizeof(struct statistic_t))) == null)
    {
        return -2;
    }

    struct statistic_t* s = (*stats);
    double sum_avg;
    size_t count;
    for (int** r = ptr; (*r) != null; ++r, ++s)
    {
        s->min = INT_MAX;
        s->max = INT_MIN;
        sum_avg = 0;
        count = 0;

        for (int* c = (*r); (*c) != -1; ++c)
        {
            cond_assign_g(s->min, (*c));
            cond_assign_l(s->max, (*c));
            sum_avg += (*c);
            ++count;
        }
        if (count == 0)
        {
            s->max = -1;
            s->min = -1;
            s->avg = -1;
            s->standard_deviation = -1;
            s->range = -1;
            continue;
        }
        sum_avg /= (double)count;
        s->avg = (float)sum_avg;
        s->standard_deviation = _standard_deviation_v(sum_avg, (*r));
        s->range = s->max - s->min;
    }
    return (int)ptr_count;
}

void destroy(int*** ptr)
{
    if (ptr != null)
    {
        for (int** r = (*ptr); (*r) != null; ++r)
        {
            free(*r);
        }
        free(*ptr);
        *ptr = null;
    }
}
